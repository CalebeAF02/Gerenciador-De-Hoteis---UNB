//
// Created by caleb on 28/09/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H
#define GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H

#include "ControladorInterfaceGerente.hpp"
#include "ControladorInterfaceGerenteAutenticavel.hpp"
#include "controladores_entidades/ControladorInterfaceHospede.hpp"
#include "ControladorInterfaceHotel.hpp"
#include "ControladorInterfaceQuarto.hpp"
#include "ControladorInterfaceReserva.hpp"

#include "Menu.hpp"

#include "TextoApresentacao.hpp"
#include <iostream>
#include <string>

#include "sqlite3.h"

using namespace std;

class Sistema {
private:
    bool executando = true;
    ControladorInterfaceGerente controladorGerente;
    ControladorInterfaceHospede controladorHospede;

public:
    void menuSistema() {
        Sistema::rodandoSistema();
    };

    void rodandoSistema();

    bool getExecutandoSistema();

    void exibirMenu();
};

inline bool Sistema::getExecutandoSistema() {
    return executando;
};

#endif //GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H
