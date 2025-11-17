//
// Created by caleb on 01/11/2025.
//

#ifndef Hotelaria_UnB_TP1_STATUSSOLICITACAOHOSPEDAGEM_H
#define Hotelaria_UnB_TP1_STATUSSOLICITACAOHOSPEDAGEM_H

#include "iostream"
#include <string>

using namespace std;
namespace Hotelaria {
    enum class StatusSolicitacaoHospedagem : int {
        PENDENTE = 0,
        APROVADO = 1,
        RECUSADO = 2,
    };
}

#endif //Hotelaria_UnB_TP1_STATUSSOLICITACAOHOSPEDAGEM_H