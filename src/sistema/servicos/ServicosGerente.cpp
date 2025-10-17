//
// Created by caleb on 10/10/2025.
//

#include "ServicosGerente.h"

#include "ServicosHospede.h"

void ServicosGerente::acessandoGerente()
{
    string opcao = "";

    while (executando == true)
    {
        TextoApresentacao::MostrarTituloEmCaixa("Faca o acesso para liberar os servicos");

        TextoApresentacao::MostrarOpcaoEmCaixa("Voltar", 0);

        TextoApresentacao::MostrarOpcaoEmCaixa("Criar Gerente", 1);
        TextoApresentacao::MostrarOpcaoEmCaixa("Fazer Login", 2);

        opcao = TextoApresentacao::RecebeOpcao();
        if (opcao == "0")
        {
            executando = false;
            cout << "Voltando a selecao de usuario!" << endl;
        }
        else if (opcao == "1")
        {
            FabricaGerenteGerenciavel fabrica;
            unique_ptr<InterfaceGerenciavel> objeto = fabrica.criar();
            objeto->criar(); // apenas cria o gerente, sem abrir o menu
        }
        else if (opcao == "2")
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
    while (this->getGerenteEstaLogado())
    {
        TextoApresentacao::MostrarTituloEmCaixa("Seja bem vindo a central de servicos");

        string opcao = "";
        TextoApresentacao::MostrarTituloPergunta("Selecione a opcao desejada:\n");

        TextoApresentacao::MostrarOpcaoEmCaixa("Sair", 0);
        TextoApresentacao::MostrarOpcaoEmCaixa("Gerencie Gerentes", 1);
        TextoApresentacao::MostrarOpcaoEmCaixa("Gerencie Hospedes", 2);
        TextoApresentacao::MostrarOpcaoEmCaixa("Gerencie Hoteis", 3);
        TextoApresentacao::MostrarOpcaoEmCaixa("Gerencie Quartos", 4);
        TextoApresentacao::MostrarOpcaoEmCaixa("Gerencie Reservas", 5);

        opcao = TextoApresentacao::RecebeOpcao();
        if (opcao == "0")
        {
            this->gerenteEstaLogado = false;
            cout << "Voce Saiu da Central de servicos e foi deslogado!\n";
        }
        else if (opcao == "1")
        {
            exibirCentralDeServicosGerentes();
        }
        else if (opcao == "2")
        {
            //ServicosHospede::exibirCentralDeServicosHospedes();
        }
        else if (opcao == "3")
        {
        }
        else if (opcao == "4")
        {
        }
        else if (opcao == "5")
        {
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
        if (status)
        {
            TextoApresentacao::MostrarTituloEmCaixa("CRUD Gerente");
            FabricaGerenteGerenciavel fabrica;
            executarMenu(fabrica, status);
        }
        else
        {
            this->gerenteEstaLogado = false;
        }
    };
}
