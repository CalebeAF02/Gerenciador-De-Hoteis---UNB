//
// Created by caleb on 01/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORINTERFACEGERENTE_H
#define GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORINTERFACEGERENTE_H

#include "ControladorInterfaceGerenteAutenticavel.h"
#include "ControladorInterfaceHospede.h"
#include "ControladorInterfaceHotel.h"
#include "ControladorInterfaceQuarto.h"
#include "ControladorInterfaceReserva.h"

#include "GerenteGerenciavel.h"
#include "InterfaceApresentacaoExibirMenu.h"
#include "iostream"

using namespace std;

class ControladorInterfaceGerente : public ControladorInterfaceGerenteAutenticavel,
                                    public InterfaceApresentacaoExibirMenu {
public:
    bool executando = true;

    // Acessando servicos
    void exibirMenu() override;

    // Menu CRUD
    void exibirMenuCRUDGerentes();
};


#endif //GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORINTERFACEGERENTE_H