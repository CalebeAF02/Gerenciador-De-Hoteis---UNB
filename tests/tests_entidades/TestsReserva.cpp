#include "TestsReserva.h"
#include <iostream>

void TestsReserva::executar() {
    testarChegada();
    testarChegadaInvalida();
    testarPartida();
    testarPartidaInvalida();
    testarDinheiro();
    testarDinheiroInvalido();
    testarCodigo();
    testarCodigoInvalido();
    testarConstrucaoCompleta();
    testarConstrucaoInvalida();
    testarGetters();
}

void TestsReserva::testarChegada() {
    apresentacaoTeste("01/11/2025");
    try {
        Reserva r;
        r.setChegada(Data("01/11/2025"));
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsReserva::testarChegadaInvalida() {
    apresentacaoTeste("32/11/2025");
    try {
        Reserva r;
        r.setChegada(Data("32/11/2025"));
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsReserva::testarPartida() {
    apresentacaoTeste("05/11/2025");
    try {
        Reserva r;
        r.setPartida(Data("05/11/2025"));
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsReserva::testarPartidaInvalida() {
    apresentacaoTeste("00/11/2025");
    try {
        Reserva r;
        r.setPartida(Data("00/11/2025"));
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsReserva::testarDinheiro() {
    apresentacaoTeste("R$100,00");
    try {
        Reserva r;
        r.setDinheiro(Dinheiro(10000));
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsReserva::testarDinheiroInvalido() {
    apresentacaoTeste("R$0,00");
    try {
        Reserva r;
        r.setDinheiro(Dinheiro(0));
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsReserva::testarCodigo() {
    apresentacaoTeste("RES123");
    try {
        Reserva r;
        r.setCodigo(Codigo("RES123"));
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsReserva::testarCodigoInvalido() {
    apresentacaoTeste("RES@123");
    try {
        Reserva r;
        r.setCodigo(Codigo("RES@123"));
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsReserva::testarConstrucaoCompleta() {
    apresentacaoTeste("Reserva completa valida");
    try {
        Reserva r(
            Data("01/11/2025"),
            Data("05/11/2025"),
            Dinheiro(10000),
            Codigo("RES123")
        );
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsReserva::testarConstrucaoInvalida() {
    apresentacaoTeste("Reserva com valor invalido");
    try {
        Reserva r(
            Data("01/11/2025"),
            Data("05/11/2025"),
            Dinheiro(0),
            Codigo("RES123")
        );
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsReserva::testarGetters() {
    apresentacaoTeste("Testando getters de Reserva");

    Data chegada("01/11/2025");
    Data partida("05/11/2025");
    Dinheiro dinheiro(10000);
    Codigo codigo("RES123");

    Reserva r;
    r.setChegada(chegada);
    r.setPartida(partida);
    r.setDinheiro(dinheiro);
    r.setCodigo(codigo);

    checaResultado(DEVE_DAR_CERTO, r.getChegada().toString() == chegada.toString() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
    checaResultado(DEVE_DAR_CERTO, r.getPartida().toString() == partida.toString() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
    checaResultado(DEVE_DAR_CERTO, r.getDinheiro() == dinheiro.getValor() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
    checaResultado(DEVE_DAR_CERTO, r.getCodigo() == codigo.getValor() ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO);
}