#ifndef RESERVA_INCLUDE
#define RESERVA_INCLUDE

#include "ReservaDTO.hpp"
#include "Data.hpp"
#include "Dinheiro.hpp"
#include "Codigo.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace Hotelaria {
    class Reserva {
    private:
        Data chegada;
        Data partida;
        Dinheiro dinheiro;
        Codigo codigo;

    public:
        Reserva() = default;

        Reserva(Data chegada, Data partida, Dinheiro dinheiro, Codigo codigo);

        Reserva(ReservaDTO &reserva_dto);

        void setChegada(const Data &newChegada);

        void setPartida(const Data &newPartida);

        void setDinheiro(const Dinheiro &newDinheiro);

        void setCodigo(const Codigo &newCodigo);

        Data getChegada() const;

        Data getPartida() const;

        int getDinheiro() const;

        string getCodigo() const;
    };
}

#endif