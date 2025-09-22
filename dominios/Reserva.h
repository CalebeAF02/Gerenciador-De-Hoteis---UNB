//
// Created by caleb on 21/09/2025.
//

#ifndef PROJETOS_CPP_UNB_7_IML_RESERVA_H
#define PROJETOS_CPP_UNB_7_IML_RESERVA_H

#include <iostream>
#include "../validadores/ValidarString.h"
#include "../validadores/ValidarInt.h"
#include "../validadores/ValidarCodigo.h"
#include "../validadores/ValidarDinheiro.h"


#include <stdexcept>
#include <string>

using namespace std;

class Reserva : public exception, ValidarString, ValidarInt, ValidarDinheiro, ValidarCodigo {
private:
    string chegada = "dia-mes-ano";
    string partida = "dia-mes-ano";
    int dinheiro;
    string codigo;

public:
    static int const TIPO_CHEGADA = 1;
    static int const TIPO_PARTIDA = 2;
    static int const TIPO_DINHEIRO = 3;
    static int const TIPO_CODIGO = 4;

    // Regras específicas de validação do hóspede

    void validar(int tipo, string valor) override;
    void validarChegada(string chegada);
    void validarPartida(string partida);

    void validar(int tipo, int valor) override;

    void setChegada(string chegada) {
        validar(TIPO_CHEGADA, chegada);
        this->chegada = chegada;
    };
    void setPartida(string partida) {
        validar(TIPO_CHEGADA, partida);
        this->partida = partida;
    };
    void setDinheiro(int dinheiro) {
        validar(TIPO_DINHEIRO, dinheiro);
        this->dinheiro = dinheiro;
    };
    void setCodigo(string codigo) {
        validar(TIPO_PARTIDA, codigo);
        this->codigo = codigo;
    };



    //Get
    string getChegada();

    string getPartida();

    int getDinheiro();

    string getCodigo();
};

inline string Reserva::getChegada() {
    return chegada;
};
inline string Reserva::getPartida() {
    return partida;
};
inline int Reserva::getDinheiro() {
    return dinheiro;
}
inline string Reserva::getCodigo() {
    return codigo;
};
#endif //PROJETOS_CPP_UNB_7_IML_RESERVA_H

