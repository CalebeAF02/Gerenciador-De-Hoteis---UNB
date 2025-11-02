#include "TestsHotel.hpp"
#include <iostream>

void TestsHotel::executar() {
    testarNome();
    testarNomeInvalido();
    testarEndereco();
    testarEnderecoInvalido();
    testarTelefone();
    testarTelefoneInvalido();
    testarCodigo();
    testarCodigoInvalido();
    testarConstrucaoCompleta();
    testarConstrucaoInvalida();
    testarGetters();
}

void TestsHotel::testarNome() {
    apresentacaoTeste("Hotel Central");
    try {
        Hotel h;
        h.setNome(Nome("Hotel Central"));
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsHotel::testarNomeInvalido() {
    apresentacaoTeste("Hotel@Central");
    try {
        Hotel h;
        h.setNome(Nome("Hotel@Central"));
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsHotel::testarEndereco() {
    apresentacaoTeste("Av. Brasil, 1000, Bloco A");
    try {
        Hotel h;
        h.setEndereco(Endereco("Av. Brasil, 1000, Bloco A")); // ✅ formato completo
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsHotel::testarEnderecoInvalido() {
    apresentacaoTeste("Av. Brasil @ 1000");
    try {
        Hotel h;
        h.setEndereco(Endereco("Av. Brasil @ 1000")); // ❌ símbolo inválido
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsHotel::testarTelefone() {
    apresentacaoTeste("(61) 91234-5678");
    try {
        Hotel h;
        h.setTelefone(Telefone("(61) 91234-5678")); // ✅ válido
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsHotel::testarTelefoneInvalido() {
    apresentacaoTeste("(61) 01234-5678");
    try {
        Hotel h;
        h.setTelefone(Telefone("(61) 01234-5678")); // ❌ número começa com 0
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsHotel::testarCodigo() {
    apresentacaoTeste("ABC123");
    try {
        Hotel h;
        h.setCodigo(Codigo("ABC123")); // ✅ válido
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsHotel::testarCodigoInvalido() {
    apresentacaoTeste("ABC@123");
    try {
        Hotel h;
        h.setCodigo(Codigo("ABC@123")); // ❌ símbolo inválido
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsHotel::testarConstrucaoCompleta() {
    apresentacaoTeste("Hotel completo valido");
    try {
        Hotel h;
        h.setNome(Nome("Hotel Central"));
        h.setEndereco(Endereco("Av. Brasil, 1000, Bloco A")); // ✅ completo
        h.setTelefone(Telefone("(61) 91234-5678")); // ✅ válido
        h.setCodigo(Codigo("ABC123")); // ✅ válido
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsHotel::testarConstrucaoInvalida() {
    apresentacaoTeste("Hotel com codigo invalido");
    try {
        Hotel h;
        h.setNome(Nome("Hotel Central"));
        h.setEndereco(Endereco("Av. Brasil, 1000, Bloco A")); // ✅ válido
        h.setTelefone(Telefone("(61) 91234-5678")); // ✅ válido
        h.setCodigo(Codigo("ABC@123")); // ❌ inválido
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsHotel::testarGetters() {
    apresentacaoTeste("Testando getters de Hotel");

    Hotel h;
    Nome nome("Hotel Central");
    Endereco endereco("Av. Brasil, 1000, Bloco A");
    Telefone telefone("(61) 91234-5678");
    Codigo codigo("ABC123");

    h.setNome(nome);
    h.setEndereco(endereco);
    h.setTelefone(telefone);
    h.setCodigo(codigo);

    checaResultado(DEVE_DAR_CERTO, h.getNome() == nome.getValor() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
    checaResultado(DEVE_DAR_CERTO, h.getEndereco() == endereco.getValor() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
    checaResultado(DEVE_DAR_CERTO, h.getTelefone() == telefone.getValor() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
    checaResultado(DEVE_DAR_CERTO, h.getCodigo() == codigo.getValor() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
}
