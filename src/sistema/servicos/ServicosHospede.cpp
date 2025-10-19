//
// Created by caleb on 10/10/2025.
//

#include "ServicosHospede.h"

#include "FabricaGerenciavel.h"
#include "HospedeGerenciavel.h"
#include "Menu.h"
#include "PersistenciaHospede.h"


void ServicosHospede::acessandoHospede()
{
    Menu menu;

    const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
    const int OPCAO_HOSPEDAGENS = menu.adcionarItens("Opcoes de Hospedagem");
    const int OPCAO_CRIAR_SOLOCITACAO_DE_HOSPEDAGEM = menu.adcionarItens("Criar Solicitacao de Hospedagem");
    const int OPCAO_STATUS_DA_SOLICITACAO_DE_HOSPEDAGEM = menu.adcionarItens("Status da Solicitacao de Hospedagem");

    while (executando == true)
    {
        int opcao = menu.executa("Faca o acesso para liberar os servicos");

        if (opcao == OPCAO_VOLTAR_AO_SISTEMA)
        {
            executando = false;
            cout << "Voltando a selecao de usuario!" << endl;
        }
        else if (opcao == OPCAO_HOSPEDAGENS)
        {
            cout << "\nEntrando em Opcoes de Hospedagem\n";
            opcoesDeHospedagem();
        }
        else if (opcao == OPCAO_CRIAR_SOLOCITACAO_DE_HOSPEDAGEM)
        {
            cout << "Crie uma Solicitacao de Hospedagem" << endl;
            solicitandoHospedagem();
        }
        else if (opcao == OPCAO_STATUS_DA_SOLICITACAO_DE_HOSPEDAGEM)
        {
            cout << "Status da Solicitacao de Hospedagem" << endl;
            statusDaSolicitandoHospedagem();
        }
        else
        {
            cout << "Opcao Invalida!" << endl;
        }
    }
};

bool ServicosHospede::fazerLoginHospede(string emailCopia)
{
    PersistenciaHospede dao;
    vector<Hospede> hospedes = dao.listar();

    //cout<<"-------------------"<<endl;

    bool loginOK = false;
    for (int i = 0; i < hospedes.size(); i++)
    {
        if (hospedes[i].getEmail() == emailCopia)
        {
            cout << "Login Realizado com Sucesso!" << endl;
            loginOK = true;
            this->hospedeEstaLogado = true;
            this->logHospede = hospedes[i];
            return true;
        }
        break;
    }
    if (!loginOK)
    {
        cout << "Erro: Usuario nao encontrado!" << endl;
    }
    return false;
};

void ServicosHospede::logandoHospede()
{
    bool lacoLogin = false;
    string emailCopia = "";

    while (!lacoLogin) // Enquanto esta falso , ele repete
    {
        TextoApresentacao::MostrarTituloEmCaixa("Logando com Hospede");

        bool tudoOK = true;
        if (tudoOK)
        {
            cout << "Informe o Email: " << endl;
            emailCopia = TextoApresentacao::LerLinha();
        }
        if (tudoOK)
        {
            lacoLogin = true;

            if (fazerLoginHospede(emailCopia))
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
}

void ServicosHospede::exibirCentralDeServicosHospedes()
{
    bool status = true;
    while (this->getHospedeEstaLogado())
    {
        if (status)
        {
            TextoApresentacao::MostrarTituloEmCaixa("CRUD Gerente");
            FabricaGerenciavel<HospedeGerenciavel> fabrica;
            fabrica.executarMenu(status);
        }
        else
        {
            this->hospedeEstaLogado = false;
        }
    };
}

void ServicosHospede::opcoesDeHospedagem()
{
    return;
}

void ServicosHospede::solicitandoHospedagem()
{
    return;
}

void ServicosHospede::statusDaSolicitandoHospedagem()
{
    return;
}