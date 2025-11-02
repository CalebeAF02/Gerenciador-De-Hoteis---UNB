//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOSPEDE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOSPEDE_H


#include "Hospede.hpp"

#include "../utilitarios/TextoApresentacao.hpp"
#include "InterfaceApresentacaoExibirMenu.hpp"
#include "PersistenciaHospede.hpp"
#include "InterfaceFabricaGerenciavel.hpp"
#include "SolicitacaoHospedagem.hpp"
#include "PersistenciaSolicitacaoHospedagem.hpp"
#include "FabricaGerenciavel.hpp"

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
