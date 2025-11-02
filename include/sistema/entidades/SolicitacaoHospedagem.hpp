//
// Created by caleb on 26/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SOLICITACAOHOSPEDAGEM_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SOLICITACAOHOSPEDAGEM_H

#include "../utilitarios/Data.hpp"
#include "Codigo.hpp"
#include <string>
#include <stdexcept>

#include "StatusSolicitacaoHospedagem.hpp"

class SolicitacaoHospedagem {
private:
    string hospedeId;
    string hotelId;
    string quartoId;
    Data chegada;
    Data partida;
    StatusSolicitacaoHospedagem status;
    string motivoRecusa;

public:
    SolicitacaoHospedagem() = default; // construtor padrao

    SolicitacaoHospedagem(
        const string &hospedeId,
        const string &hotelId,
        const string &quartoId,
        const Data &chegada,
        const Data &partida,
        const StatusSolicitacaoHospedagem status,
        const string &motivoRecusa
    );

    // Setters inline
    void setHospedeId(const string &id) { hospedeId = id; }
    void setHotelId(const string &id) { hotelId = id; }
    void setQuartoId(const string &id) { quartoId = id; }
    void setChegada(const Data &d) { chegada = d; }
    void setPartida(const Data &d) { partida = d; }

    void setStatus(StatusSolicitacaoHospedagem s) {
        this->status = s;
    }

    void setMotivoRecusa(const string &motivo) { motivoRecusa = motivo; }

    // Getters inline

    string getHospedeId() const {
        return hospedeId;
    }

    string getHotelId() const {
        return hotelId;
    }

    string getQuartoId() const {
        return quartoId;
    }

    Data getChegada() const {
        return chegada;
    }

    Data getPartida() const {
        return partida;
    }

    StatusSolicitacaoHospedagem getStatus() const {
        return status;
    }

    string getMotivoRecusa() const {
        return motivoRecusa;
    }
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SOLICITACAOHOSPEDAGEM_H
