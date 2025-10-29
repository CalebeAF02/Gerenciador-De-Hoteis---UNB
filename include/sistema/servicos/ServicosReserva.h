//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSRESERVA_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSRESERVA_H

#include <iostream>
#include "TextoApresentacao.h"

using namespace std;

class ServicosReserva
{
public:
    // Construtor dos servicosReserva
    ServicosReserva() = default;

    // Confirmar que e um Reserva
    void acessandoReserva();

    // Acessando servicos
    void exibirCentralDeServicos();
    void exibirCentralDeServicosReservas();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSRESERVA_H