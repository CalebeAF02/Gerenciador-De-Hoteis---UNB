//
// Created by caleb on 10/10/2025.
//

#include "ServicosGerente.h"

#include "FabricaGerenciavel.h"
#include "GerenteGerenciavel.h"
#include "../../../include/utilitarios/Menu.h"
#include "ServicosHospede.h"
#include "ServicosHotel.h"
#include "ServicosQuarto.h"
#include "ServicosReserva.h"

void ServicosGerente::acessandoGerente()
{
    Menu menu;

    const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
    const int OPCAO_CRIAR_UM_GERENTE = menu.adcionarItens("Criar Gerente");
    const int OPCAO_FAZER_LOGIN = menu.adcionarItens("Fazer Login");

    while (executando == true)
    {
        int opcao = menu.executa("Faca o acesso para liberar os servicos");

        if (opcao == OPCAO_VOLTAR_AO_SISTEMA)
        {
            executando = false;
            cout << "Voltando a selecao de usuario!" << endl;
        }
        else if (opcao == OPCAO_CRIAR_UM_GERENTE)
        {
            FabricaGerenciavel<GerenteGerenciavel> fabrica;
            fabrica.criar(); // apenas cria o gerente, sem abrir o menu
        }
        else if (opcao == OPCAO_FAZER_LOGIN)
        {
            logandoGerente();
            if (getGerenteEstaLogado())
            {
                cout << "Agora Voce Possui Super-Poderes" << endl;
                exibirCentralDeServicos();
            }
        }
        else
        {
            cout << "Opcao Invalida!" << endl;
        }
    }
};

bool ServicosGerente::fazerLoginGerente(string emailCopia, string senhaCopia)
{
    PersistenciaGerente dao;
    vector<Gerente> gerentes = dao.listar();

    //cout<<"-------------------"<<endl;

    bool loginOK = false;
    for (int i = 0; i < gerentes.size(); i++)
    {
        if (gerentes[i].getEmail() == emailCopia)
        {
            if (gerentes[i].getSenha() == senhaCopia)
            {
                cout << "Login Realizado com Sucesso" << endl;
                loginOK = true;
                this->gerenteEstaLogado = true;
                this->logGerente = gerentes[i];
                return true;
            }
            break;
        }
    }
    if (!loginOK)
    {
        cout << "Erro: Usuario nao encontrado ou senha incorreta!" << endl;
    }
    return false;
};

void ServicosGerente::logandoGerente()
{
    bool lacoLogin = false;
    string emailCopia = "";
    string senhaCopia = "";

    while (!lacoLogin) // Enquanto esta falso , ele repete
    {
        TextoApresentacao::MostrarTituloEmCaixa("Logando com Gerente");

        bool tudoOK = true;
        if (tudoOK)
        {
            cout << "Informe o Email: \n";
            emailCopia = TextoApresentacao::LerLinha();
        }
        if (tudoOK)
        {
            cout << "Informe o Senha: \n";
            senhaCopia = TextoApresentacao::LerLinha();
        }
        if (tudoOK)
        {
            lacoLogin = true;

            if (fazerLoginGerente(emailCopia, senhaCopia))
            {
                lacoLogin = true;
            }
            else
            {
                lacoLogin = false;
            }
        }
        else
        {
            cout << "Gerente nao cadastrado" << endl;
        }
    }
};

void ServicosGerente::exibirCentralDeServicos()
{
    Menu menu;

    const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
    const int OPCAO_GERENCIE_GERENTES = menu.adcionarItens("Gerencie Gerentes");
    const int OPCAO_GERENCIE_HOSPEDES = menu.adcionarItens("Gerencie Hospedes");
    const int OPCAO_GERENCIE_HOTEIS = menu.adcionarItens("Gerencie Hoteis");
    const int OPCAO_GERENCIE_QUARTOS = menu.adcionarItens("Gerencie Quartos");
    const int OPCAO_GERENCIE_RESERVAS = menu.adcionarItens("Gerencie Reservas");

    while (this->getGerenteEstaLogado())
    {
        int opcao = menu.executa("Seja bem vindo a central de servicos");

        if (opcao == OPCAO_VOLTAR_AO_SISTEMA)
        {
            this->gerenteEstaLogado = false;
            cout << "Voce Saiu da Central de servicos e foi deslogado!\n";
        }
        else if (opcao == OPCAO_GERENCIE_GERENTES)
        {
            exibirCentralDeServicosGerentes();
        }
        else if (opcao == OPCAO_GERENCIE_HOSPEDES)
        {
            ServicosHospede servicosHospede;
            servicosHospede.exibirCentralDeServicosHospedes();
        }
        else if (opcao == OPCAO_GERENCIE_HOTEIS)
        {
            //ServicosHotel::exibirCentralDeServicosHotel();
        }
        else if (opcao == OPCAO_GERENCIE_QUARTOS)
        {
            //ServicosQuarto::exibirCentralDeServicosQuartos();
        }
        else if (opcao == OPCAO_GERENCIE_RESERVAS)
        {
            //ServicosReserva::exibirCentralDeServicosReservas();
        }
        else
        {
            cout << "Opcao Invalida!" << endl;
        }
    };
}

void ServicosGerente::exibirCentralDeServicosGerentes()
{
    bool status = true;
    while (this->getGerenteEstaLogado())
    {
        FabricaGerenciavel<GerenteGerenciavel> fabrica;
        fabrica.executarMenu(status);
        if (status == false)
        {
            break;
        }
    };
}