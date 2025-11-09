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

#include "InterfaceApresentacaoExibirMenu.hpp"
#include "iostream"

using namespace std;

class ControladorInterfaceGerente : public ControladorInterfaceGerenteAutenticavel,
                                    public InterfaceApresentacaoExibirMenu,
                                    public InterfaceApresentacaoCRUD {
private:
    Gerente *gerenteLogado;
    PersistenciaGerente persistencia;
    bool executando = true;

public:
    // Acessando servicos
    void exibirMenu() override;

    // Chama o Menu crud
    void exibirMenuCRUD();

    // Menu CRUD herdados da interface
    void criar() override;

    void ler() override;

    void atualizar() override;

    bool remover() override;

    void setGerenteLogado(Gerente *gerente) {
        this->gerenteLogado = gerente;
    }
};


#endif //GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORINTERFACEGERENTE_H