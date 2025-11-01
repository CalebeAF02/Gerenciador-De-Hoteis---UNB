//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOSPEDE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOSPEDE_H


#include "Hospede.h"

#include "../utilitarios/TextoApresentacao.h"
#include "InterfaceApresentacaoExibirMenu.h"
#include "PersistenciaHospede.h"
#include "InterfaceFabricaGerenciavel.h"
#include "SolicitacaoHospedagem.h"
#include "PersistenciaSolicitacaoHospedagem.h"
#include "FabricaGerenciavel.h"

#include <vector>
#include <limits>
#include <fstream>

using namespace std;

class ControladorInterfaceHospede : public InterfaceApresentacaoExibirMenu,
                                    public InterfaceApresentacaoCRUD {
private:
    bool executando = true;
    PersistenciaHospede dao;

public:
    // Construtor dos ServicosHospede
    ControladorInterfaceHospede() = default;

    // Solicitacao de Hospedagem para Gerente
    void opcoesDeHospedagem();

    void solicitandoHospedagem();

    void statusDaSolicitandoHospedagem() const;

    void avaliarSolicitacoes();

    // Acessando servicos
    void exibirMenu() override;

    // Menu CRUD
    void exibirMenuCRUD();

    void criar() override;

    void ler() override;

    void atualizar() override;

    bool remover() override;
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOSPEDE_H