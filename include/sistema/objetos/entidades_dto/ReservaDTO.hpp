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
        int dinheiro;
        string codigo;

    public:
        ReservaDTO() = default;

        ReservaDTO(int reservaId, string chegada, string partida, int dinheiro, string codigo) : reservaId(reservaId),
            chegada(chegada), partida(partida), dinheiro(dinheiro), codigo(codigo) {
        };

        int getReservaId() const;

        void setReservaId(int valor);

        string getChegada() const;

        void setChegada(const string &valor);

        string getPartida() const;

        void setPartida(const string &valor);

        int getDinheiro() const;

        void setDinheiro(const int &valor);

        string getCodigo() const;

        void setCodigo(const string &valor);
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_RESERVADTO_HPP