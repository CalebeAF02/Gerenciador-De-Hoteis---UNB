//
// Created by caleb on 28/09/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H
#define GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H

#include "ControladorInterfaceGerente.h"
#include "ControladorInterfaceGerenteAutenticavel.h"
#include "controladores_entidades/ControladorInterfaceHospede.h"
#include "ControladorInterfaceHotel.h"
#include "ControladorInterfaceQuarto.h"
#include "ControladorInterfaceReserva.h"

#include "Menu.h"

#include "TextoApresentacao.h"
#include <iostream>
#include <string>

#include "sqlite3.h"
#include "GerenteGerenciavel.h"

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