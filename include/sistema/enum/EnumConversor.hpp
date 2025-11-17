//
// Created by caleb on 01/11/2025.
//

#ifndef Hotelaria_UnB_TP1_ENUMCONVERSOR_H
#define Hotelaria_UnB_TP1_ENUMCONVERSOR_H

#include "StatusSolicitacaoHospedagem.hpp"

namespace Hotelaria {
    class EnumConversor {
    public:
        static int StatusSolicitacaoHospedagemParaInteiro(StatusSolicitacaoHospedagem status);

        static StatusSolicitacaoHospedagem InteiroParaStatusSolicitacaoHospedagem(int valor);
    };
}

#endif //Hotelaria_UnB_TP1_ENUMCONVERSOR_H