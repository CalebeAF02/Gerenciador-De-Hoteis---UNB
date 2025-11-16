//
// Created by caleb on 01/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_STATUSSOLICITACAOHOSPEDAGEM_H
#define GERENCIADOR_DE_HOTEIS_UNB_STATUSSOLICITACAOHOSPEDAGEM_H

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

#endif //GERENCIADOR_DE_HOTEIS_UNB_STATUSSOLICITACAOHOSPEDAGEM_H