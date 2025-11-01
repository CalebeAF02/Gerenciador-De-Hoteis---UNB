//
// Created by caleb on 10/10/2025.
//

#include "ControladorInterfaceGerenteAutenticavel.h"

#include "FabricaGerenciavel.h"
#include "GerenteGerenciavel.h"
#include "HospedeGerenciavel.h"
#include "Menu.h"
#include "ServicosHospede.h"
#include "ServicosHotel.h"
#include "ServicosQuarto.h"
#include "ServicosReserva.h"
#include "sqlite3.h"

void ControladorInterfaceGerenteAutenticavel::exibirMenu() {
    Menu menu;

    const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
    const int OPCAO_GERENCIE_GERENTES = menu.adcionarItens("Gerencie Gerentes");
    const int OPCAO_GERENCIE_HOSPEDES = menu.adcionarItens("Gerencie Hospedes");
    const int OPCAO_GERENCIE_HOTEIS = menu.adcionarItens("Gerencie Hoteis");
    const int OPCAO_GERENCIE_QUARTOS = menu.adcionarItens("Gerencie Quartos");
    const int OPCAO_GERENCIE_RESERVAS = menu.adcionarItens("Gerencie Reservas");
    const int OPCAO_AVALIAR_SOLICITACOES = menu.adcionarItens("Avaliar Solicitacoes de Hospedagem");

    while (this->getEstaLogado()) {
        int opcao = menu.executa("Seja bem vindo a central de servicos");

        if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
            this->sair();
            cout << "Voce Saiu da Central de servicos e foi deslogado!\n";
        } else if (opcao == OPCAO_GERENCIE_GERENTES) {
            exibirMenuCRUDGerentes();
        } else if (opcao == OPCAO_GERENCIE_HOSPEDES) {
            ServicosHospede servicosHospede;
            servicosHospede.exibirMenuCRUD();
        } else if (opcao == OPCAO_GERENCIE_HOTEIS) {
            ServicosHotel servicosHotel;
            servicosHotel.exibirMenuCRUD();
        } else if (opcao == OPCAO_GERENCIE_QUARTOS) {
            ServicosQuarto servicosQuarto;
            servicosQuarto.exibirMenuCRUD();
        } else if (opcao == OPCAO_GERENCIE_RESERVAS) {
            ServicosReserva servicosReserva;
            servicosReserva.exibirMenuCRUD();
        } else if (opcao == OPCAO_AVALIAR_SOLICITACOES) {
            ServicosHospede servicosHospede;
            servicosHospede.avaliarSolicitacoes();
        } else {
            cout << "Opcao Invalida!" << endl;
        }
    };
}

void ControladorInterfaceGerenteAutenticavel::exibirMenuCRUDGerentes() {
    bool status = true;
    while (this->getEstaLogado()) {
        FabricaGerenciavel<GerenteGerenciavel> fabrica;
        fabrica.executarMenu(status);
        if (status == false) {
            break;
        }
    };
}


void ControladorInterfaceGerenteAutenticavel::fazerLogin() {
    bool lacoLogin = false;
    string emailCopia = "";
    string senhaCopia = "";

    while (!lacoLogin) // Enquanto esta falso , ele repete
    {
        TextoApresentacao::MostrarTituloEmCaixa("Logando com Gerente");

        bool tudoOK = true;
        if (tudoOK) {
            cout << "Informe o Email: \n";
            emailCopia = TextoApresentacao::LerLinha();
        }
        if (tudoOK) {
            cout << "Informe o Senha: \n";
            senhaCopia = TextoApresentacao::LerLinha();
        }
        if (tudoOK) {
            Email emailObj(emailCopia);
            Senha senhaObj(senhaCopia);

            // chama servico
            if (autenticar(emailObj, senhaObj)) {
                lacoLogin = true;
            } else {
                TextoApresentacao::MostrarOpcao("Voltar", 0);
                TextoApresentacao::MostrarOpcao("Tentar novamente", 1);
                string opcao = TextoApresentacao::LerLinha();
                if (opcao == "0") {
                    break;
                } else if (opcao == "1") {
                    lacoLogin = false;
                }
            }
        } else {
            cout << "Gerente nao cadastrado" << endl;
        }
    }
};

/*
void ServicosGerente::excluirMeuCadastro()
{
    if (!gerenteEstaLogado)
    {
        cout << "Voce precisa estar logado para excluir seu cadastro.\n";
        return;
    }
    PersistenciaGerente persistencia;
    bool sucesso = persistencia.excluirPorEmailDoBD(logGerente);

    if (sucesso)
    {
        gerenteEstaLogado = false;
        logGerente = nullptr;
        executando = false; // ou redireciona para menu principal
    }
    else
    {
        cout << "Nao foi possivel excluir seu cadastro.\n";
    }
}
*/