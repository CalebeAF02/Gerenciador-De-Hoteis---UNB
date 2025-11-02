//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_NOME_H
#define GERENCIADOR_HOTEL_UNB_NOME_H

#include <iostream>
#include <string>

using namespace std;

class Nome
{
private:
    string valor;

    void validar(const string& nome); // Metodo de validacao

public:
    Nome() = default;

    explicit Nome(const string& nomeStr)
    {
        setValor(nomeStr);
    };

    void setValor(const string& nome)
    {
        validar(nome);
        this->valor = nome;
    }

    string getValor() const;
};

inline string Nome::getValor() const
{
    return valor;
}

#endif //GERENCIADOR_HOTEL_UNB_NOME_H
