//
// Created by caleb on 01/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORINTERFACEGERENTE_H
#define GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORINTERFACEGERENTE_H

#include "ControladorInterfaceGerenteAutenticavel.hpp"
#include "ControladorInterfaceHospede.hpp"
#include "ControladorInterfaceHotel.hpp"
#include "ControladorInterfaceQuarto.hpp"
#include "ControladorInterfaceReserva.hpp"
#include "ConsoleIO.hpp"
#include "Tabela.hpp"

#include "InterfaceApresentacaoExibirMenu.hpp"
#include "iostream"

using namespace std;
using namespace VisualizadorDeTabela;

class ControladorInterfaceGerente : public ControladorInterfaceGerenteAutenticavel,
                                    public InterfaceApresentacaoExibirMenu,
                                    public InterfaceApresentacaoCRUD {
private:
    PersistenciaGerente persistencia;
    bool executando = true;

public:
    // Acessando servicos
    void exibirMenu() override;

    // Menu CRUD
    void exibirMenuCRUD();
    void criar() override;
    void ler() override;
    void atualizar() override;
    bool remover() override;
};


#endif //GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORINTERFACEGERENTE_H