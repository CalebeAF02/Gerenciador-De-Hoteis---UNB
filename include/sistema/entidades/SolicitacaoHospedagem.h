//
// Created by caleb on 26/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SOLICITACAOHOSPEDAGEM_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SOLICITACAOHOSPEDAGEM_H

#include "../utilitarios/Data.h"
#include "Codigo.h"
#include <string>
#include <stdexcept>

class SolicitacaoHospedagem
{
private:
    Codigo codigo;
    std::string hospedeId;
    std::string hotelId;
    std::string quartoId;
    Data chegada;
    Data partida;
    int status; // 0 = pendente, 1 = aprovada, 2 = recusada
    std::string motivoRecusa;

public:
    SolicitacaoHospedagem(); // construtor padrao

    SolicitacaoHospedagem(
        const Codigo& codigo,
        const std::string& hospedeId,
        const std::string& hotelId,
        const std::string& quartoId,
        const Data& chegada,
        const Data& partida,
        int status = 0,
        const std::string& motivoRecusa = ""
    );

    // Setters inline
    void setCodigo(const Codigo& c) { codigo = c; }
    void setHospedeId(const std::string& id) { hospedeId = id; }
    void setHotelId(const std::string& id) { hotelId = id; }
    void setQuartoId(const std::string& id) { quartoId = id; }
    void setChegada(const Data& d) { chegada = d; }
    void setPartida(const Data& d) { partida = d; }

    void setStatus(int s)
    {
        if (s < 0 || s > 2) throw std::invalid_argument("Status invalido");
        status = s;
    }

    void setMotivoRecusa(const std::string& motivo) { motivoRecusa = motivo; }

    // Getters inline
    Codigo getCodigo() const
    {
        return codigo;
    }

    std::string getHospedeId() const
    {
        return hospedeId;
    }

    std::string getHotelId() const
    {
        return hotelId;
    }

    std::string getQuartoId() const
    {
        return quartoId;
    }

    Data getChegada() const
    {
        return chegada;
    }

    Data getPartida() const
    {
        return partida;
    }

    int getStatus() const
    {
        return status;
    }

    std::string getMotivoRecusa() const
    {
        return motivoRecusa;
    }
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SOLICITACAOHOSPEDAGEM_H