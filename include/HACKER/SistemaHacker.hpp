//
// Created by caleb on 08/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_SISTEMAHACKER_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_SISTEMAHACKER_HPP

#include <iostream>
#include "ControladorInterfaceGerente.hpp"
#include "Versao.hpp"

using namespace std;

class SistemaHacker {
private:
    ControladorInterfaceGerente controladorGerente;

public:
    void iniciar();
};


#endif //GERENCIADOR_DE_HOTEIS_UNB_SISTEMAHACKER_HPP