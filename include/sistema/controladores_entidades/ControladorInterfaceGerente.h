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

#include "InterfaceApresentacaoExibirMenu.h"
#include "iostream"

using namespace std;

class ControladorInterfaceGerente : public ControladorInterfaceGerenteAutenticavel,
                                    public InterfaceApresentacaoExibirMenu,
                                    public InterfaceApresentacaoCRUD {
private:
    Gerente *gerenteLogado;
    PersistenciaGerente dao;
    bool executando = true;

public:
    // Acessando servicos
    void exibirMenu() override;

    // Menu CRUD
    void exibirMenuCRUDGerentes();

    // Metods CRUD
    void criar() override;

    void ler() override;

    void atualizar() override;

    bool remover() override;

    void setGerenteLogado(Gerente *gerente) {
        this->gerenteLogado = gerente;
    }
};


#endif //GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORINTERFACEGERENTE_H