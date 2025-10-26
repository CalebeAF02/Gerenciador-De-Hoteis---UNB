//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOTEL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOTEL_H

#include <iostream>
#include "TextoApresentacao.h"

using namespace std;

class ServicosHotel
{
public:
    // Construtor dos servicosHotel
    ServicosHotel() = default;

    // Confirmar que e um Hotel
    void acessandoHotel();

    // Acessando servicos
    void exibirCentralDeServicos();
    void exibirCentralDeServicosHotel();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOTEL_H