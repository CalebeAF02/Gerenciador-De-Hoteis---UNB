//
// Created by caleb on 01/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_ENUMCONVERSOR_H
#define GERENCIADOR_DE_HOTEIS_UNB_ENUMCONVERSOR_H

#include "StatusSolicitacaoHospedagem.hpp"

namespace Hotelaria {
    class EnumConversor {
    public:
        static int StatusSolicitacaoHospedagemParaInteiro(StatusSolicitacaoHospedagem status);

        static StatusSolicitacaoHospedagem InteiroParaStatusSolicitacaoHospedagem(int valor);
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_ENUMCONVERSOR_H