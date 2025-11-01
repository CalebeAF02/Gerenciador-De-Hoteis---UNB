//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSGERENTE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSGERENTE_H

#include "Pessoa.h"
#include "Gerente.h"

#include "../utilitarios/TextoApresentacao.h"
#include "InterfaceFabricaGerenciavel.h"
#include "FabricaGerenciavel.h"

#include "ServicosHospede.h"
#include "controladores/ControleInterfaceGerenteAutenticavel.h"

using namespace std;

class ServicosGerente : public ControleInterfaceGerenteAutenticavel {
private:
    bool executando = true;

public:
    // Construtor dos servicosGerente
    ServicosGerente() = default;

    // Confirmar que e um gerente
    void exibirMenu();

    // Acessando servicos
    void exibirCentralDeServicos();

    void exibirCentralDeServicosGerentes();

    // metudo para excluir
    //void excluirMeuCadastro();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSGERENTE_H