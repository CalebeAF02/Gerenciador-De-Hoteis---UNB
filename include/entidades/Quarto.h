#ifndef QUARTO_INCLUDE
#define QUARTO_INCLUDE

#include "Numero.h"
#include "Capacidade.h"
#include "Dinheiro.h"
#include "Ramal.h"

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

    Quarto(Numero numero, Capacidade capacidade, Dinheiro diaria, Ramal ramal)
    {
        setNumero(numero);
        setCapacidade(capacidade);
        setDiaria(diaria);
        setRamal(ramal);
    }

    void setNumero(const Numero& newNumero)
    {
        this->numero = newNumero;
    }

    void setCapacidade(const Capacidade& newCapacidade)
    {
        this->capacidade = newCapacidade;
    }

    void setDiaria(const Dinheiro& newDiaria)
    {
        this->diaria = newDiaria;
    }

    void setRamal(const Ramal& newRamal)
    {
        this->ramal = newRamal;
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

    int getDiaria() const
    {
        diaria.getValor();
    }

    string getRamal() const
    {
        return ramal.getValor();
    }
};

#endif