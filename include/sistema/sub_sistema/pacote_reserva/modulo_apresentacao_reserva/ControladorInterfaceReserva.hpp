//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSRESERVA_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSRESERVA_H

#include "../../../../../libs/formato/Formato.hpp"
#include "../../../../../libs/menu/ExibirMenu.hpp"
#include "../../../../../libs/io/IO.hpp"
#include <iostream>
using namespace std;
namespace Hotelaria {
    class ControladorInterfaceReserva : public ExibirMenu {
    public:
        // Construtor dos servicosReserva
        ControladorInterfaceReserva() = default;

        // Acessando servicos
        void exibirMenu() override;

        // Menu CRUD
        void exibirMenuCRUD();
    };
}
#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSRESERVA_H