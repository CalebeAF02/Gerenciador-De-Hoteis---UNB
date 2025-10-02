#ifndef HOTEL_INCLUDE
#define HOTEL_INCLUDE

#include "../validadoresPrincipais/ValidarString.h"
#include "Dominios/Nome.h"
#include "Dominios/Endereco.h"
#include "Dominios/Telefone.h"
#include "Dominios/Codigo.h"
#include <string>

using namespace std;

class Hotel
{
private:
    Nome nome;
    Endereco endereco;
    Telefone telefone;
    Codigo codigo;

public:
    Hotel() = default;

    void setNome(const string valor)
    {
        nome.setValor(valor);
    };

    void setEndereco(const string valor)
    {
        endereco.setValor(valor);
    };

    void setTelefone(const string valor)
    {
        telefone.setValor(valor);
    };

    void setCodigo(const string valor)
    {
        codigo.setValor(valor);
    };

    //Get
    string getNome() const
    {
        return nome.getValor();
    };

    string getEndereco() const
    {
        return endereco.getValor();
    };

    string getTelefone() const
    {
        return telefone.getValor();
    };

    string getCodigo() const
    {
        return codigo.getValor();
    };


    /*
    void listarHoteis [];

    void listarQuartos [];

    void listarReservas [];

    void listarHospedes [];
    */
};

#endif