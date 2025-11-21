#include "Reserva.hpp"

#include "Telefone.hpp"

namespace Hotelaria {
    Reserva::Reserva(Data chegada, Data partida, Dinheiro dinheiro, Codigo codigo) {
        setChegada(chegada);
        setPartida(partida);
        setDinheiro(dinheiro);
        setCodigo(codigo);
    };

    Reserva::Reserva(ReservaDTO &reserva_dto) {
        setChegada(Data(reserva_dto.getChegada()));
        setPartida(Data(reserva_dto.getPartida()));
        setDinheiro(Dinheiro(reserva_dto.getDinheiro()));
        setCodigo(Codigo(reserva_dto.getCodigo()));
    };

    void Reserva::setChegada(const Data &newChegada) {
        this->chegada = newChegada;
    };

    void Reserva::setPartida(const Data &newPartida) {
        this->partida = newPartida;
    };

    void Reserva::setDinheiro(const Dinheiro &newDinheiro) {
        this->dinheiro = newDinheiro;
    };

    void Reserva::setCodigo(const Codigo &newCodigo) {
        this->codigo = newCodigo;
    };

    Data Reserva::getChegada() const {
        return chegada;
    };

    Data Reserva::getPartida() const {
        return partida;
    };

    int Reserva::getDinheiro() const {
        return dinheiro.getValor();
    };

    string Reserva::getCodigo() const {
        return codigo.getValor();
    };
}