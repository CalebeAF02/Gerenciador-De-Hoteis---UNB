//
// Created by caleb on 26/10/2025.
//

#include "SolicitacaoHospedagem.h"

SolicitacaoHospedagem::SolicitacaoHospedagem(
    const Codigo& codigo,
    const std::string& hospedeId,
    const std::string& hotelId,
    const std::string& quartoId,
    const Data& chegada,
    const Data& partida,
    int status,
    const std::string& motivoRecusa
)
{
    setCodigo(codigo);
    setHospedeId(hospedeId);
    setHotelId(hotelId);
    setQuartoId(quartoId);
    setChegada(chegada);
    setPartida(partida);
    setStatus(status);
    setMotivoRecusa(motivoRecusa);
}