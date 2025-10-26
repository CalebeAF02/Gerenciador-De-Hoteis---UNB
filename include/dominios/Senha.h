//
// Created by caleb on 01/10/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_SENHA_H
#define GERENCIADOR_HOTEL_UNB_SENHA_H

#include <iostream>
#include <string>

using namespace std;

class Senha
{
private:
    string valor;

    void validar(string senha); // Metodo de validacao

public:
    Senha() = default;

    explicit Senha(const string& senha)
    {
        setValor(senha);
    };

    void setValor(const string& senha)
    {
        validar(senha);
        this->valor = senha;
    }

    string getValor() const;
};

inline string Senha::getValor() const
{
    return valor;
}

#endif //GERENCIADOR_HOTEL_UNB_SENHA_H