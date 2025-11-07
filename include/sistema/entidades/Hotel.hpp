#ifndef HOTEL_INCLUDE
#define HOTEL_INCLUDE

#include "Nome.hpp"
#include "Endereco.hpp"
#include "Telefone.hpp"
#include "Codigo.hpp"

#include <string>

using namespace std;

class Hotel {
private:
    Nome nome;
    Endereco endereco;
    Telefone telefone;
    Codigo codigo;

public:
    Hotel() = default;

    Hotel(Nome nome, Endereco endereco, Telefone telefone, Codigo codigo) {
        setNome(nome);
        setEndereco(endereco);
        setTelefone(telefone);
        setCodigo(codigo);
    };

    void setNome(const Nome &newNome) {
        this->nome = newNome;
    };

    void setEndereco(const Endereco &newEndereco) {
        this->endereco = newEndereco;
    };

    void setTelefone(const Telefone &newTelefone) {
        this->telefone = newTelefone;
    };

    void setCodigo(const Codigo &newCodigo) {
        this->codigo = newCodigo;
    };

    //Get
    string getNome() const {
        return nome.getValor();
    };

    string getEndereco() const {
        return endereco.getValor();
    };

    string getTelefone() const {
        return telefone.getValor();
    };

    string getCodigo() const {
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