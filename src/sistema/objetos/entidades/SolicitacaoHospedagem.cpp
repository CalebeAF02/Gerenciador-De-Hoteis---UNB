//
// Created by caleb on 26/10/2025.
//

#include "SolicitacaoHospedagem.hpp"

SolicitacaoHospedagem::SolicitacaoHospedagem(
    const string &hospedeId,
    const string &hotelId,
    const string &quartoId,
    const Data &chegada,
    const Data &partida,
    const StatusSolicitacaoHospedagem status,
    const string &motivoRecusa
) {
    setHospedeId(hospedeId);
    setHotelId(hotelId);
    setQuartoId(quartoId);
    setChegada(chegada);
    setPartida(partida);
    setStatus(status);
    setMotivoRecusa(motivoRecusa);
}