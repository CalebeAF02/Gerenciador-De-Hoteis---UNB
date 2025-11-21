//
// Created by caleb on 26/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SOLICITACAOHOSPEDAGEM_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SOLICITACAOHOSPEDAGEM_H

#include "SolicitacaoHospedagemDTO.hpp"
#include "StatusSolicitacaoHospedagem.hpp"
#include "Data.hpp"
#include "Codigo.hpp"

#include <string>
#include <stdexcept>

namespace Hotelaria {
    class SolicitacaoHospedagem {
    private:
        int hospedeId;
        int hotelId;
        int quartoId;
        Data chegada;
        Data partida;
        StatusSolicitacaoHospedagem status;
        string motivoRecusa;

    public:
        SolicitacaoHospedagem() = default; // construtor padrao

        SolicitacaoHospedagem(
            const int &hospedeId,
            const int &hotelId,
            const int &quartoId,
            const Data &chegada,
            const Data &partida,
            const StatusSolicitacaoHospedagem status,
            const string &motivoRecusa
        );

        SolicitacaoHospedagem(SolicitacaoHospedagemDTO &solicitacao_hospedagem_dto);

        // Setters inline
        void setHospedeId(const int &valor);

        void setHotelId(const int &valor);

        void setQuartoId(const int &valor);

        void setChegada(const Data &valor);

        void setPartida(const Data &valor);

        void setStatus(StatusSolicitacaoHospedagem valor);

        void setMotivoRecusa(const string &valor);

        int getHospedeId() const;

        int getHotelId() const;

        int getQuartoId() const;

        Data getChegada() const;

        Data getPartida() const;

        StatusSolicitacaoHospedagem getStatus() const;

        string getMotivoRecusa() const;
    };
}

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SOLICITACAOHOSPEDAGEM_H