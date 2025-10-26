#ifndef RESERVA_INCLUDE
#define RESERVA_INCLUDE

#include "../utilitarios/Data.h"
#include "Dinheiro.h"
#include "Codigo.h"

#include <iostream>
#include <string>

using namespace std;

class Reserva
{
private:
    Data chegada;
    Data partida;
    Dinheiro dinheiro;
    Codigo codigo;

public:
    Reserva() = default;

    Reserva(Data chegada, Data partida, Dinheiro dinheiro, Codigo codigo)
    {
        setChegada(chegada);
        setPartida(partida);
        setDinheiro(dinheiro);
        setCodigo(codigo);
    };

    void setChegada(const Data& newChegada)
    {
        this->chegada = newChegada;
    };

    void setPartida(const Data& newPartida)
    {
        this->partida = newPartida;
    };

    void setDinheiro(const Dinheiro& newDinheiro)
    {
        this->dinheiro = newDinheiro;
    };

    void setCodigo(const Codigo& newCodigo)
    {
        this->codigo = newCodigo;
    };


    //Get
    Data getChegada() const
    {
        return chegada;
    };

    Data getPartida() const
    {
        return partida;
    };

    int getDinheiro() const
    {
        return dinheiro.getValor();
    };

    string getCodigo() const
    {
        return codigo.getValor();
    };
};
#endif