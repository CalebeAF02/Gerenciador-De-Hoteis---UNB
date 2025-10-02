#ifndef RESERVA_INCLUDE
#define RESERVA_INCLUDE

#include <iostream>
#include "../validadoresPrincipais/ValidarString.h"
#include "../validadoresPrincipais/ValidarInt.h"
#include "../../coisas/utilitarios/Data.h"
#include "Dominios/Dinheiro.h"
#include "Dominios/Codigo.h"

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


    void setChegada(const int dia, const int mes, const int ano)
    {
        chegada.setData(dia, mes, ano);
        this->chegada = chegada;
    };

    void setPartida(const int dia, const int mes, const int ano)
    {
        partida.setData(dia, mes, ano);
        this->partida = partida;
    };

    void setDinheiro(const int valor)
    {
        dinheiro.setValor(valor);
    };

    void setCodigo(const string valor)
    {
        codigo.setValor(valor);
        this->codigo = codigo;
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

    string getCodigo();
};
#endif