#ifndef QUARTO_INCLUDE
#define QUARTO_INCLUDE

#include "../validadoresPrincipais/ValidarString.h"
#include "../validadoresPrincipais/ValidarInt.h"
#include "../validadoresAbstratos/ValidarRamal.h"
#include "../validadoresAbstratos/ValidarDinheiro.h"

#include <string>
#include <stdexcept>

using namespace std;

class Quarto : public ValidarString, public ValidarInt, public ValidarRamal, public ValidarDinheiro, public exception
{
private:
    string numero;
    int capacidade;
    int diaria;
    string ramal;

public:
    static int const TIPO_NUMERO = 1;
    static int const TIPO_CAPACIDADE = 2;
    static int const TIPO_DIARIA = 3;
    static int const TIPO_RAMAL = 4;

    // Regras específicas de validação do gerente
    void validar(int tipo, string valor) override;

    void validar(int tipo, int valor) override;

    void validarNumero(string numero);

    void validarCapacidade(int capacidade);

    void validarDiaria(int diaria);

    void setNumero(const string numero)
    {
        validar(TIPO_NUMERO, numero);
        this->numero = numero;
    }

    void setCapacidade(const int capacidade)
    {
        validar(TIPO_CAPACIDADE, capacidade);
        this->capacidade = capacidade;
    }

    void setDiaria(const int diaria)
    {
        validar(TIPO_DIARIA, diaria);
        this->diaria = diaria;
    }

    void setRamal(const string ramal)
    {
        validar(TIPO_RAMAL, ramal);
        this->ramal = ramal;
    }

    //Get
    string getNumero();

    int getCapacidade();

    int getDinheiro();

    string getRamal();
};

inline string Quarto::getNumero()
{
    return numero;
};

inline int Quarto::getCapacidade()
{
    return capacidade;
};

inline int Quarto::getDinheiro()
{
    return diaria;
};

inline string Quarto::getRamal()
{
    return ramal;
}
#endif