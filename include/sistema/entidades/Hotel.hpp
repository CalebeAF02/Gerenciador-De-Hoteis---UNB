#ifndef HOTEL_INCLUDE
#define HOTEL_INCLUDE

#include "Nome.hpp"
#include "Endereco.hpp"
#include "Telefone.hpp"
#include "Codigo.hpp"
#include "HotelDTO.hpp"

#include <string>

using namespace std;

class Hotel {
private:
    Nome nome;
    Endereco endereco;
    Telefone telefone;
    Codigo codigo;

public:
    //-----------------------------------------------------------------------------------------------------------------
    // Contrutor de Hotel sem valores
    Hotel() = default;

    // Contrutor de Hotel Com todos valores
    Hotel(Nome nome, Endereco endereco, Telefone telefone, Codigo codigo) {
        setNome(nome);
        setEndereco(endereco);
        setTelefone(telefone);
        setCodigo(codigo);
    };

    // construtor com valores do banco de dados
    // Transforma HotelDTO em Hotel
    Hotel(HotelDTO &hotel_dto) {
        setNome(Nome(hotel_dto.getNome()));
        setEndereco(Endereco(hotel_dto.getEndereco()));
        setTelefone(Telefone(hotel_dto.getTelefone()));
        setCodigo(Codigo(hotel_dto.getCodigo()));
    };

    //-----------------------------------------------------------------------------------------------------------------
    // Set
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
    //-----------------------------------------------------------------------------------------------------------------
    // Get
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
    //-----------------------------------------------------------------------------------------------------------------
};

#endif