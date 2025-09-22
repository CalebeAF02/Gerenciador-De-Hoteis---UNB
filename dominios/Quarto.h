//
// Created by caleb on 10/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_QUARTO_H
#define CODIGOS_CLION_TP1_IML_QUARTO_H

#include "../validadores/ValidarInt.h"
#include "../validadores/ValidarRamal.h"
#include "../validadores/ValidarDinheiro.h"

#include<stdexcept>

using namespace std;

class Quarto : public ValidarInt, ValidarRamal, exception {
private:
    int numero;
    int capacidade;
    int dinheiro;
    int ramal;

public:
    static int const TIPO_NUMERO = 1;
    static int const TIPO_CAPACIDADE = 2;
    static int const TIPO_DINHEIRO = 3;
    static int const TIPO_RAMAL = 4;

    // Regras específicas de validação do gerente

    void validar(int tipo, int valor) override;

    void validarNumero(int numero);

    void validarCapacidade(int capacidade);

    void validarDinheiro(int diaria);

    void setNumero(int numero) {
        validar(TIPO_NUMERO, numero);
        this->numero = numero;
    }

    void setCapacidade(int capacidade) {
        validar(TIPO_CAPACIDADE, capacidade);
        this->capacidade = capacidade;
    }

    void setDinheiro(int diaria) {
        validar(TIPO_DINHEIRO, dinheiro);
        this->dinheiro = dinheiro;
    }

    void setRamal(int ramal) {
        validar(TIPO_RAMAL, ramal);
        this->ramal = ramal;
    }

    //Get
    int getNumero();

    int getCapacidade();

    int getDinheiro();

    int getRamal();
};

inline int Quarto::getNumero() {
    return numero;
};

inline int Quarto::getCapacidade() {
    return capacidade;
};

inline int Quarto::getDinheiro() {
    return dinheiro;
};

inline int Quarto::getRamal() {
    return ramal;
}


#endif //CODIGOS_CLION_TP1_IML_QUARTO_H
