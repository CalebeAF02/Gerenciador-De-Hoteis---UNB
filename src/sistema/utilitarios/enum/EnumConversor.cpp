//
// Created by caleb on 01/11/2025.
//

#include "EnumConversor.hpp"

namespace Hotelaria {
    int EnumConversor::StatusSolicitacaoHospedagemParaInteiro(StatusSolicitacaoHospedagem status) {
        return static_cast<int>(status); // Pega o enum e transforma em valor um statico inteiro
    };

    StatusSolicitacaoHospedagem EnumConversor::InteiroParaStatusSolicitacaoHospedagem(int valor) {
        switch (valor) {
            case 0: return StatusSolicitacaoHospedagem::PENDENTE;
            case 1: return StatusSolicitacaoHospedagem::APROVADO;
            case 2: return StatusSolicitacaoHospedagem::RECUSADO;
            default:
                throw invalid_argument("Erro: Opcao Invalida!");
        }
    }
}