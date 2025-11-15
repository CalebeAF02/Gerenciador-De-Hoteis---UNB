//
// Created by caleb on 14/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_CARESERVA_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_CARESERVA_HPP

#include "../../../../libs/formato/Formato.hpp"
#include "InterfaceApresentacaoExibirMenu.hpp"
#include "InterfaceApresentacaoReserva.hpp"
#include "../../../../libs/io/IO.hpp"
#include <iostream>

using namespace std;

class ControladoraApresentacaoReserva : public InterfaceApresentacaoReserva {
public:
    // Construtor dos servicosReserva
    ControladorInterfaceReserva();

    // Acessando servicos
    void exibirMenu();

    // Menu CRUD
    void exibirMenuCRUD();
};

#endif //GERENCIADOR_DE_HOTEIS_UNB_CARESERVA_HPP