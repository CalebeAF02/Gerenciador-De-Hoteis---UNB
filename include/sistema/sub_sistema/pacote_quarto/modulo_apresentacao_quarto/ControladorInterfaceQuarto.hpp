//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSQUARTO_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSQUARTO_H

#include <iostream>
#include "../../../../../libs/formato/Formato.hpp"
#include "../../../../../libs/menu/ExibirMenu.hpp"
#include "../../../../../libs/io/IO.hpp"

using namespace std;
namespace Hotelaria {
    class ControladorInterfaceQuarto : public ExibirMenu {
    public:
        // Construtor dos servicosQuarto
        ControladorInterfaceQuarto() = default;

        // Acessando servicos
        void exibirMenu() override;

        // Menu CRUD
        void exibirMenuCRUD();
    };
}
#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSQUARTO_H