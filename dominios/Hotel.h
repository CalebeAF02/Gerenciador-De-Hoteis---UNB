//
// Created by caleb on 10/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_HOTEL_H
#define CODIGOS_CLION_TP1_IML_HOTEL_H


#include "../validadores/ValidarString.h"
#include "../validadores/ValidarEndereco.h"
#include "../validadores/ValidarNome.h"

#include <string>
#include<stdexcept>
using namespace std;

class Hotel : public ValidarString, ValidarEndereco,ValidarNome, exception{
private:
    string nome;
    string endereco;
    string telefone;
    //Codigo

public:
    static int const TIPO_NOME = 1;
    static int const TIPO_ENDERECO = 2;
    static int const TIPO_TELEFONE = 3;


    void validar(int tipo, string valor) override;
    void validarNome(string nome);
    void validarTelefone(string telefone);

    Hotel();

    void setNome(string nome) {
        validar(TIPO_NOME, nome);
        this->nome = nome;
    };

    void setEndereco(string endereco) {
        this->endereco = endereco;
    };
    void setTelefone(string telefone) {
        this->telefone = telefone;
    };

    //Get
    string getNome();
    string getEndereco();
    string getTelefone();


    /*
    void listarHoteis [];

    void listarQuartos [];

    void listarReservas [];

    void listarHospedes [];
    */
};

inline string Hotel::getNome() {
    return nome;
};
inline string Hotel::getEndereco() {
    return endereco;
};
inline string Hotel::getTelefone() {
    return telefone;
};

#endif //CODIGOS_CLION_TP1_IML_HOTEL_H
