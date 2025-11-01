//
// Created by caleb on 26/10/2025.
//

#include "../../../include/sistema/entidades/SolicitacaoHospedagem.h"

SolicitacaoHospedagem::SolicitacaoHospedagem(
    const std::string &hospedeId,
    const std::string &hotelId,
    const std::string &quartoId,
    const Data &chegada,
    const Data &partida,
    const StatusSolicitacaoHospedagem status,
    const std::string &motivoRecusa
) {
    setHospedeId(hospedeId);
    setHotelId(hotelId);
    setQuartoId(quartoId);
    setChegada(chegada);
    setPartida(partida);
    setStatus(status);
    setMotivoRecusa(motivoRecusa);
}