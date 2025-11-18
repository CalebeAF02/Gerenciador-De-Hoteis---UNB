//
// Created by caleb on 08/11/2025.
//

#ifndef Hotelaria_UnB_TP1_HOTELDTO_HPP
#define Hotelaria_UnB_TP1_HOTELDTO_HPP

#include <iostream>

using namespace std;
namespace Hotelaria {
    class HotelDTO {
    private:
        int hotelId;
        string nome;
        string endereco;
        string telefone;
        string codigo;

    public:
        HotelDTO() = default;

        HotelDTO(int hotelId, string nome, string endereco, string telefone, string codigo) : hotelId(hotelId),nome(nome), endereco(endereco), telefone(telefone), codigo(codigo) {};

        int getId() const {
            return hotelId;
        }

        void setId(int valor) {
            this->hotelId = valor;
        }

        string getNome() const {
            return nome;
        }

        void setNome(const string &valor) {
            this->nome = valor;
        }

        string getEndereco() const {
            return endereco;
        }

        void setEndereco(const string &valor) {
            this->endereco = valor;
        }

        string getTelefone() const {
            return telefone;
        }

        void setTelefone(const string &valor) {
            this->telefone = valor;
        }

        string getCodigo() const {
            return codigo;
        }

        void setCodigo(const string &valor) {
            this->codigo = valor;
        }
    };
}

#endif //Hotelaria_UnB_TP1_HOTELDTO_HPP