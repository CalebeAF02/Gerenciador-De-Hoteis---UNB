//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSQUARTO_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSQUARTO_H

#include <iostream>
#include "TextoApresentacao.h"

using namespace std;

class ServicosQuarto

{
public:
    // Construtor dos servicosQuarto
    ServicosQuarto() = default;

    // Confirmar que e um Quarto
    void acessandoQuarto();

    // Acessando servicos
    void exibirCentralDeServicos();
    void exibirCentralDeServicosQuartos();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSQUARTO_H