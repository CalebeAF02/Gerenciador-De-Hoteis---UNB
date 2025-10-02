#ifndef QUARTO_INCLUDE
#define QUARTO_INCLUDE

#include "../validadoresPrincipais/ValidarString.h"
#include "../validadoresPrincipais/ValidarInt.h"
#include "Dominios/Numero.h"
#include "Dominios/Capacidade.h"
#include "Dominios/Dinheiro.h"
#include "Dominios/Ramal.h"

#include <string>
#include <stdexcept>


using namespace std;

class Quarto
{
private:
    Numero numero;
    Capacidade capacidade;
    Dinheiro diaria;
    Ramal ramal;

public:
    Quarto() = default;

    void setNumero(const string valor)
    {
        numero.setValor(valor);
    }

    void setCapacidade(const int valor)
    {
        capacidade.setValor(valor);
    }

    void setDiaria(const int valor)
    {
        diaria.setValor(valor);
    }

    void setRamal(const string valor)
    {
        ramal.setValor(valor);
    }

    //Get
    string getNumero() const
    {
        return numero.getValor();
    }

    int getCapacidade() const
    {
        return capacidade.getValor();
    }

    int getDinheiro() const
    {
        diaria.getValor();
    }

    string getRamal() const
    {
        return ramal.getValor();
    }
};

#endif