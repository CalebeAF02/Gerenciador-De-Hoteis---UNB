#pragma once

#include <iostream>
#include "validadoresPrincipais/ValidarString.h"
#include "validadoresPrincipais/ValidarInt.h"
#include "validadoresAbstratos/ValidarCodigo.h"
#include "validadoresAbstratos/ValidarDinheiro.h"
#include "Data.h"

#include <string>

using namespace std;

class Reserva : public ValidarString, public ValidarInt, public ValidarDinheiro,
                public ValidarCodigo {
private:
    Data chegada;
    Data partida;
    int dinheiro;
    string codigo;

public:
    static int const TIPO_CHEGADA = 1;
    static int const TIPO_PARTIDA = 2;
    static int const TIPO_DINHEIRO = 3;
    static int const TIPO_CODIGO = 4;

    // Regras específicas de validação do hóspede

    void validar(int tipo, string valor) override;

    void validar(int tipo, int valor) override;

    void setChegada(const int dia, const int mes, const int ano) {
        chegada.setData(dia, mes, ano);
        this->chegada = chegada;
    };

    void setPartida(const int dia, const int mes, const int ano) {
        partida.setData(dia, mes, ano);
        this->partida = partida;
    };

    void setDinheiro(const int dinheiro) {
        validar(TIPO_DINHEIRO, dinheiro);
        this->dinheiro = dinheiro;
    };

    void setCodigo(const string codigo) {
        validar(TIPO_CODIGO, codigo);
        this->codigo = codigo;
    };


    //Get
    Data getChegada();

    Data getPartida();

    int getDinheiro();

    string getCodigo();
};

inline Data Reserva::getChegada() {
    return chegada;
};

inline Data Reserva::getPartida() {
    return partida;
};

inline int Reserva::getDinheiro() {
    return dinheiro;
}

inline string Reserva::getCodigo() {
    return codigo;
};