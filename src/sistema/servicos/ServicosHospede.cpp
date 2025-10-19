//
// Created by caleb on 10/10/2025.
//

#include "ServicosHospede.h"

#include "FabricaHospedeGerenciavel.h"
#include "PersistenciaHospede.h"


void ServicosHospede::acessandoHospede()
{
    string opcao = "";

    while (executando == true)
    {
        TextoApresentacao::MostrarTituloEmCaixa("Faca o acesso para liberar os servicos");

        TextoApresentacao::MostrarOpcaoEmCaixa("Voltar", 0);

        TextoApresentacao::MostrarOpcaoEmCaixa("Opcoes de Hospedagem", 1);
        TextoApresentacao::MostrarOpcaoEmCaixa("Criar Solicitacao de Hospedagem", 2);
        TextoApresentacao::MostrarOpcaoEmCaixa("Status da Solicitacao de Hospedagem", 3);

        opcao = TextoApresentacao::RecebeOpcao();
        if (opcao == "0")
        {
            executando = false;
            cout << "Voltando a selecao de usuario!" << endl;
        }
        else if (opcao == "1")
        {
            cout << "\nEntrando em Opcoes de Hospedagem\n";
            opcoesDeHospedagem();
        }
        else if (opcao == "2")
        {
            cout << "Crie uma Solicitacao de Hospedagem" << endl;
            solicitandoHospedagem();
        }
        else if (opcao == "3")
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
            FabricaHospedeGerenciavel fabrica;
            executarMenu(fabrica, status);
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
