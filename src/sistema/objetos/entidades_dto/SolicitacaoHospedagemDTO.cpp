//
// Created by caleb on 18/11/2025.
//

#include "SolicitacaoHospedagemDTO.hpp"

namespace Hotelaria {
    int SolicitacaoHospedagemDTO::getSolicitacaoHospedagemId() const {
        return solicitacaoHospedagemId;
    }

    void SolicitacaoHospedagemDTO::setSolicitacaoHospedagemId(int valor) {
        this->solicitacaoHospedagemId = valor;
    }

    int SolicitacaoHospedagemDTO::getHospedeId() const {
        return hospedeId;
    }

    void SolicitacaoHospedagemDTO::setHospedeId(int valor) {
        this->hospedeId = valor;
    }

    int SolicitacaoHospedagemDTO::getHotelId() const {
        return hotelId;
    }

    void SolicitacaoHospedagemDTO::setHotelId(int valor) {
        this->hotelId = valor;
    }

    int SolicitacaoHospedagemDTO::getQuartoId() const {
        return quartoId;
    }

    void SolicitacaoHospedagemDTO::setQuartoId(int valor) {
        this->quartoId = valor;
    }

    Data SolicitacaoHospedagemDTO::getChegada() const {
        return chegada;
    }

    void SolicitacaoHospedagemDTO::setChegada(const Data &valor) {
        this->chegada = valor;
    }

    Data SolicitacaoHospedagemDTO::getPartida() const {
        return partida;
    }

    void SolicitacaoHospedagemDTO::setPartida(const Data &valor) {
        this->partida = valor;
    }

    StatusSolicitacaoHospedagem SolicitacaoHospedagemDTO::getStatus() const {
        return status;
    }

    void SolicitacaoHospedagemDTO::setStatus(const StatusSolicitacaoHospedagem &valor) {
        this->status = valor;
    }

    string SolicitacaoHospedagemDTO::getMotivoRecusa() const {
        return motivoRecusa;
    }

    void SolicitacaoHospedagemDTO::setMotivoRecusa(const string &valor) {
        this->motivoRecusa = valor;
    }
}