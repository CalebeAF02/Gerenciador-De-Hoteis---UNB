//
// Created by caleb on 18/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_RESERVADTO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_RESERVADTO_HPP

#include <string>

using namespace std;
namespace Hotelaria {
    class ReservaDTO {
    private:
        int reservaId;
        string chegada;
        string partida;
        string dinheiro;
        string codigo;

    public:
        ReservaDTO() = default;

        ReservaDTO(int reservaId, string chegada, string partida, string dinheiro, string codigo) : reservaId(reservaId), chegada(chegada), partida(partida), dinheiro(dinheiro), codigo(codigo) {
        };

        int getReservaId() const {
            return reservaId;
        }

        void setReservaId(int valor) {
            this->reservaId = valor;
        }

        string getChegada() const {
            return chegada;
        }

        void setChegada(const string &valor) {
            this->chegada = valor;
        }

        string getPartida() const {
            return partida;
        }

        void setPartida(const string &valor) {
            this->partida = valor;
        }

        string getDinheiro() const {
            return dinheiro;
        }

        void setDinheiro(const string &valor) {
            this->dinheiro = valor;
        }
        string getCodigo() const {
            return codigo;
        }

        void setCodigo(const string &valor) {
            this->codigo = valor;
        }
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_RESERVADTO_HPP