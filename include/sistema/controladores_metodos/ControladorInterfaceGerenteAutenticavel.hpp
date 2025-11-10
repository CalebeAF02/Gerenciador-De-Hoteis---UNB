//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSGERENTE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSGERENTE_H

#include "../interfaces/apresentacoes/InterfaceApresentacaoAutenticavel.hpp"
#include "ServicoAutenticavel.hpp"
#include "Pessoa.hpp"
#include "Gerente.hpp"

#include "../utilitarios/console/Formato.hpp"
#include "InterfaceFabricaGerenciavel.hpp"
#include "FabricaGerenciavel.hpp"
#include "IO.hpp"

#include "../controladores_entidades/ControladorInterfaceHospede.hpp"

using namespace std;

class ControladorInterfaceGerenteAutenticavel : public InterfaceApresentacaoAutenticavel, public ServicoAutenticavel {
private:
    bool executando = true;

public:
    // Construtor dos servicosGerente
    ControladorInterfaceGerenteAutenticavel() = default;

    // Fazer Login
    void fazerLogin() override;

    // metudo para excluir
    //void excluirMeuCadastro();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSGERENTE_H