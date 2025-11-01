//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSGERENTE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSGERENTE_H

#include "../interfaces/apresentacoes/InterfaceApresentacaoAutenticavel.h"
#include "ServicoAutenticavel.h"
#include "Pessoa.h"
#include "Gerente.h"

#include "TextoApresentacao.h"
#include "InterfaceFabricaGerenciavel.h"
#include "FabricaGerenciavel.h"

#include "ServicosHospede.h"

using namespace std;

class ControladorInterfaceGerenteAutenticavel : public InterfaceApresentacaoAutenticavel, public ServicoAutenticavel {
private:
    bool executando = true;

public:
    // Construtor dos servicosGerente
    ControladorInterfaceGerenteAutenticavel() = default;

    // Acessando servicos
    void exibirMenu();

    // Menu CRUD
    void exibirMenuCRUDGerentes();

    // Fazer Login
    void fazerLogin() override;

    // metudo para excluir
    //void excluirMeuCadastro();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSGERENTE_H