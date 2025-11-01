#include "TestsGerente.h"
#include <iostream>

void TestsGerente::executar() {
    testarNome();
    testarNomeInvalido();
    testarEmail();
    testarEmailInvalido();
    testarSenha();
    testarSenhaInvalida();
    testarRamal();
    testarRamalInvalido();
    testarConstrucaoCompleta();
    testarConstrucaoInvalida();
    testarGetters();
}

void TestsGerente::testarNome() {
    apresentacaoTeste("Joao Silva");
    try {
        Gerente g;
        g.setNome(Nome("Joao Silva"));
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsGerente::testarNomeInvalido() {
    apresentacaoTeste("Joao@Silva");
    try {
        Gerente g;
        g.setNome(Nome("Joao@Silva"));
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsGerente::testarEmail() {
    apresentacaoTeste("joao@empresa.com");
    try {
        Gerente g;
        g.setEmail(Email("joao@empresa.com"));
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsGerente::testarEmailInvalido() {
    apresentacaoTeste("joao@.com");
    try {
        Gerente g;
        g.setEmail(Email("joao@.com"));
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsGerente::testarSenha() {
    apresentacaoTeste("a1!Bz"); // ✅ válida: 5 caracteres, sem sequência, contém todos os tipos
    try {
        Gerente g;
        g.setSenha(Senha("a1!Bz"));
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsGerente::testarSenhaInvalida() {
    apresentacaoTeste("a1Bz"); // ❌ apenas 4 caracteres
    try {
        Gerente g;
        g.setSenha(Senha("a1Bz"));
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsGerente::testarRamal() {
    apresentacaoTeste("42");
    try {
        Gerente g;
        g.setRamal(Ramal("42"));
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsGerente::testarRamalInvalido() {
    apresentacaoTeste("12a4");
    try {
        Gerente g;
        g.setRamal(Ramal("12a4"));
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsGerente::testarConstrucaoCompleta() {
    apresentacaoTeste("Gerente completo valido");
    try {
        Gerente g;
        g.setNome(Nome("Joao Silva"));
        g.setEmail(Email("joao@empresa.com"));
        g.setSenha(Senha("a1!Bz")); // ✅ válida
        g.setRamal(Ramal("42")); // ✅ válida
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsGerente::testarConstrucaoInvalida() {
    apresentacaoTeste("Gerente com senha invalida");
    try {
        Gerente g;
        g.setNome(Nome("Joao Silva"));
        g.setEmail(Email("joao@empresa.com"));
        g.setSenha(Senha("123")); // ❌ inválida: curta, sem tipos
        g.setRamal(Ramal("42")); // ✅ válida
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsGerente::testarGetters() {
    apresentacaoTeste("Testando getters de Gerente");

    Nome nome("Joao Silva");
    Email email("joao@empresa.com");
    Senha senha("a1!B2"); // ✅ válida
    Ramal ramal("42"); // ✅ válida

    Gerente g;
    g.setNome(nome);
    g.setEmail(email);
    g.setSenha(senha);
    g.setRamal(ramal);

    checaResultado(DEVE_DAR_CERTO, g.getNome() == nome.getValor() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
    checaResultado(DEVE_DAR_CERTO, g.getEmail() == email.getValor() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
    checaResultado(DEVE_DAR_CERTO, g.getSenha() == senha.getValor() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
    checaResultado(DEVE_DAR_CERTO, g.getRamal() == ramal.getValor() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
}