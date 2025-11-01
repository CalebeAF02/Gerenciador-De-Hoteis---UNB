//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOTEL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOTEL_H

#include <iostream>
#include "TextoApresentacao.h"
#include "InterfaceApresentacaoExibirMenu.h"
#include "Menu.h"
#include "MenuItem.h"

using namespace std;

class ControladorInterfaceHotel : public InterfaceApresentacaoExibirMenu {
public:
    // Construtor dos servicosHotel
    ControladorInterfaceHotel() = default;

    // Acessando servicos
    void exibirMenu() override;

    // Menu CRUD
    void exibirMenuCRUD();

    // Opções de Hotel
    bool criarHotel();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOTEL_H