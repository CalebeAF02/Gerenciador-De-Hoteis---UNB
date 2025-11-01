//
// Created by caleb on 28/09/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H
#define GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H

#include "ControladorInterfaceGerenteAutenticavel.h"
#include "ServicosHospede.h"
#include "ServicosHotel.h"
#include "ServicosQuarto.h"
#include "ServicosReserva.h"

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
    ControladorInterfaceGerenteAutenticavel controladorGerente;
    ServicosHospede servicosHospede;

public:
    void menuSistema() {
        Sistema::rodandoSistema();
    };

    void rodandoSistema();

    bool getExecutandoSistema();

    // Confirmar que e um gerente
    void exibirMenu();
};

inline bool Sistema::getExecutandoSistema() {
    return executando;
};

#endif //GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H