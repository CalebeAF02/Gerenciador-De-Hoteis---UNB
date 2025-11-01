//
// Created by caleb on 01/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_ENUMCONVERSOR_H
#define GERENCIADOR_DE_HOTEIS_UNB_ENUMCONVERSOR_H

#include "StatusSolicitacaoHospedagem.h"

class EnumConversor {
public:
    static int StatusSolicitacaoHospedagemParaInteiro(StatusSolicitacaoHospedagem status) {
        return static_cast<int>(status); // Pega o enum e transforma em valor um statico inteiro
    };

    static StatusSolicitacaoHospedagem InteiroParaStatusSolicitacaoHospedagem(int valor) {
        switch (valor) {
            case 0: return StatusSolicitacaoHospedagem::PENDENTE;
            case 1: return StatusSolicitacaoHospedagem::APROVADO;
            case 2: return StatusSolicitacaoHospedagem::RECUSADO;
            default:
                throw invalid_argument("Erro: Opcao Invalida!");
        }
    }
};

#endif //GERENCIADOR_DE_HOTEIS_UNB_ENUMCONVERSOR_H