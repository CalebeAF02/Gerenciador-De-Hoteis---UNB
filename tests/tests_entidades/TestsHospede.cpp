#include "TestsHospede.hpp"
#include <iostream>

void TestsHospede::executar() {
    testarNome();
    testarNomeInvalido();
    testarEmail();
    testarEmailInvalido();
    testarEndereco();
    testarEnderecoInvalido();
    testarCartao();
    testarCartaoInvalido();
    testarConstrucaoCompleta();
    testarConstrucaoInvalida();
    testarGetters();
}

void TestsHospede::testarNome() {
    apresentacaoTeste("Maria Clara");
    try {
        Hospede h;
        h.setNome(Nome("Maria Clara"));
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsHospede::testarNomeInvalido() {
    apresentacaoTeste("Maria@Clara");
    try {
        Hospede h;
        h.setNome(Nome("Maria@Clara"));
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsHospede::testarEmail() {
    apresentacaoTeste("maria@exemplo.com");
    try {
        Hospede h;
        h.setEmail(Email("maria@exemplo.com"));
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsHospede::testarEmailInvalido() {
    apresentacaoTeste("maria@.com");
    try {
        Hospede h;
        h.setEmail(Email("maria@.com"));
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsHospede::testarEndereco() {
    apresentacaoTeste("Rua Central,123");
    try {
        Hospede h;
        h.setEndereco(Endereco("Rua Central,123")); // ✅ válido
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsHospede::testarEnderecoInvalido() {
    apresentacaoTeste("rua central @ 123");
    try {
        Hospede h;
        h.setEndereco(Endereco("rua central @ 123")); // ❌ inválido
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsHospede::testarCartao() {
    apresentacaoTeste("4111111111111111");
    try {
        Hospede h;
        h.setCartao(Cartao("4111111111111111"));
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsHospede::testarCartaoInvalido() {
    apresentacaoTeste("4111-1111-1111-1111");
    try {
        Hospede h;
        h.setCartao(Cartao("4111-1111-1111-1111")); // ❌ inválido
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsHospede::testarConstrucaoCompleta() {
    apresentacaoTeste("Hospede completo valido");
    try {
        Hospede h;
        h.setNome(Nome("Maria Clara"));
        h.setEmail(Email("maria@exemplo.com"));
        h.setEndereco(Endereco("Avenida Brasil,1000,Bloco A")); // ✅ válido
        h.setCartao(Cartao("4111111111111111"));
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsHospede::testarConstrucaoInvalida() {
    apresentacaoTeste("Hospede com cartao invalido");
    try {
        Hospede h;
        h.setNome(Nome("Maria Clara"));
        h.setEmail(Email("maria@exemplo.com"));
        h.setEndereco(Endereco("Avenida Brasil,1000,Bloco A")); // ✅ corrigido
        h.setCartao(Cartao("4111-1111-1111-1111")); // ❌ inválido
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsHospede::testarGetters() {
    apresentacaoTeste("Testando getters de Hospede");

    Hospede h;
    Nome nome("Maria Clara");
    Email email("maria@exemplo.com");
    Endereco endereco("Rua Central,123"); // ✅ corrigido
    Cartao cartao("4111111111111111");

    h.setNome(nome);
    h.setEmail(email);
    h.setEndereco(endereco);
    h.setCartao(cartao);

    checaResultado(DEVE_DAR_CERTO, h.getNome() == nome.getValor() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
    checaResultado(DEVE_DAR_CERTO, h.getEmail() == email.getValor() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
    checaResultado(DEVE_DAR_CERTO, h.getEndereco() == endereco.getValor() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
    checaResultado(DEVE_DAR_CERTO, h.getCartao() == cartao.getValor() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
}