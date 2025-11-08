//
// Created by caleb on 08/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_HOTELDTO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_HOTELDTO_HPP

#include <iostream>

using namespace std;

class HotelDTO {
private:
    int id;
    string nome;
    string endereco;
    string telefone;
    string codigo;

public:
    HotelDTO(int id, string nome, string endereco, string telefone, string codigo) : id(id),
        nome(nome),
        endereco(endereco),
        telefone(telefone),
        codigo(codigo) {
    };

    int getId() const {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    string getNome() const {
        return nome;
    }

    void setNome(const string &nome) {
        this->nome = nome;
    }

    string getEndereco() const {
        return endereco;
    }

    void setEndereco(const string &endereco) {
        this->endereco = endereco;
    }

    string getTelefone() const {
        return telefone;
    }

    void setTelefone(const string &telefone) {
        this->telefone = telefone;
    }

    string getCodigo() const {
        return codigo;
    }

    void setCodigo(const string &codigo) {
        this->codigo = codigo;
    }
};
#endif //GERENCIADOR_DE_HOTEIS_UNB_HOTELDTO_HPP