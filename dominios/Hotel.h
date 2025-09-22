//
// Created by caleb on 10/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_HOTEL_H
#define CODIGOS_CLION_TP1_IML_HOTEL_H

#include "../validadores/ValidarString.h"
#include "../validadores/ValidarEndereco.h"
#include "../validadores/ValidarNome.h"
#include "../validadores/ValidarCodigo.h"

#include <string>

#include<stdexcept>

using namespace std;

class Hotel : public ValidarString, ValidarEndereco, ValidarNome,ValidarCodigo, exception {
private:
    string nome;
    string endereco;
    string telefone;
    string codigo;

public:
    static int const TIPO_NOME = 1;
    static int const TIPO_ENDERECO = 2;
    static int const TIPO_TELEFONE = 3;
    static int const TIPO_CODIGO = 4;



    void validar(int tipo, string valor) override;

    void validarTelefone(string telefone);


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

    void setCodigo(string codigo) {
        this->codigo = codigo;
    };

    //Get
    string getNome();

    string getEndereco();

    string getTelefone();

    string getCodigo();


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

inline string Hotel::getCodigo() {
    return codigo;
};
#endif //CODIGOS_CLION_TP1_IML_HOTEL_H
