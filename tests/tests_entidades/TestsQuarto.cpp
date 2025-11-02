#include "TestsQuarto.hpp"
#include <iostream>

void TestsQuarto::executar() {
    testarNumero();
    testarNumeroInvalido();
    testarCapacidade();
    testarCapacidadeInvalida();
    testarDiaria();
    testarDiariaInvalida();
    testarRamal();
    testarRamalInvalido();
    testarConstrucaoCompleta();
    testarConstrucaoInvalida();
    testarGetters();
}

void TestsQuarto::testarNumero() {
    apresentacaoTeste("101");
    try {
        Quarto q;
        q.setNumero(Numero("101"));
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsQuarto::testarNumeroInvalido() {
    apresentacaoTeste("10A");
    try {
        Quarto q;
        q.setNumero(Numero("10A"));
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsQuarto::testarCapacidade() {
    apresentacaoTeste("2");
    try {
        Quarto q;
        q.setCapacidade(Capacidade(2));
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsQuarto::testarCapacidadeInvalida() {
    apresentacaoTeste("0");
    try {
        Quarto q;
        q.setCapacidade(Capacidade(0));
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsQuarto::testarDiaria() {
    apresentacaoTeste("R$50,00");
    try {
        Quarto q;
        q.setDiaria(Dinheiro(5000));
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsQuarto::testarDiariaInvalida() {
    apresentacaoTeste("R$0,00");
    try {
        Quarto q;
        q.setDiaria(Dinheiro(0));
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsQuarto::testarRamal() {
    apresentacaoTeste("1234");
    try {
        Quarto q;
        q.setRamal(Ramal("1234"));
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsQuarto::testarRamalInvalido() {
    apresentacaoTeste("12a4");
    try {
        Quarto q;
        q.setRamal(Ramal("12a4"));
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsQuarto::testarConstrucaoCompleta() {
    apresentacaoTeste("Quarto completo valido");
    try {
        Quarto q;
        q.setNumero(Numero("101"));
        q.setCapacidade(Capacidade(2));
        q.setDiaria(Dinheiro(5000));
        q.setRamal(Ramal("1234"));
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsQuarto::testarConstrucaoInvalida() {
    apresentacaoTeste("Quarto com diária invalida");
    try {
        Quarto q;
        q.setNumero(Numero("101"));
        q.setCapacidade(Capacidade(2));
        q.setDiaria(Dinheiro(0));
        q.setRamal(Ramal("1234"));
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsQuarto::testarGetters() {
    apresentacaoTeste("Testando getters de Quarto");

    Quarto q;
    Numero numero("101");
    Capacidade capacidade(2);
    Dinheiro diaria(5000);
    Ramal ramal("1234");

    q.setNumero(numero);
    q.setCapacidade(capacidade);
    q.setDiaria(diaria);
    q.setRamal(ramal);

    checaResultado(DEVE_DAR_CERTO, q.getNumero() == numero.getValor() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
    checaResultado(DEVE_DAR_CERTO, q.getCapacidade() == capacidade.getValor() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
    checaResultado(DEVE_DAR_CERTO, q.getDiaria() == diaria.getValor() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
    checaResultado(DEVE_DAR_CERTO, q.getRamal() == ramal.getValor() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
}