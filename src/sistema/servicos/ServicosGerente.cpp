//
// Created by caleb on 10/10/2025.
//
#include "ServicosGerente.h"


void ServicosGerente::acessandoGerente()
{
    string opcao = "";

    while (executando == true)
    {
        TextoApresentacao::MostrarTituloEmCaixa("Faca o acesso para liberar os servicos");

        TextoApresentacao::MostrarOpcao("Voltar", 0);

        TextoApresentacao::MostrarOpcao("Criar Gerente", 1);
        TextoApresentacao::MostrarOpcao("Fazer Login", 2);

        opcao = TextoApresentacao::RecebeOpcao();
        if (opcao == "0")
        {
            executando = false;
            cout << "Voltando a selecao de usuario!" << endl;
        }
        else if (opcao == "1")
        {
            criarGerente();
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

void ServicosGerente::criarGerente()
{
    bool criado = false;

    while (!criado) // Enquanto craido esta falso , ele repete
    {
        TextoApresentacao::MostrarTituloEmCaixa("Criando Novo Gerente");

        Gerente gerente;

        bool tudoOK = true;
        cout << "Informe o Nome: " << endl;
        string nomeStr = TextoApresentacao::LerLinha();
        try
        {
            Nome nomeObj(nomeStr);
            gerente.setNome(nomeObj);
        }
        catch (invalid_argument& erro)
        {
            cout << erro.what() << endl;
            tudoOK = false;
        }
        if (tudoOK)
        {
            cout << "Informe o Email: " << endl;
            string emailStr = TextoApresentacao::LerLinha();
            try
            {
                Email emailObj(emailStr);
                gerente.setEmail(emailObj);
            }
            catch (invalid_argument& erro)
            {
                cout << erro.what() << endl;
                tudoOK = false;
            }
        }
        if (tudoOK)
        {
            cout << "Informe o Ramal: " << endl;
            string ramal = TextoApresentacao::LerLinha();
            try
            {
                Ramal ramalObj(ramal);
                gerente.setRamal(ramalObj);
            }
            catch (invalid_argument& erro)
            {
                cout << erro.what() << endl;
                tudoOK = false;
            }
        }
        if (tudoOK)
        {
            cout << "Informe o Senha: " << endl;
            string senha = TextoApresentacao::LerLinha();
            try
            {
                Senha senhaObj(senha);
                gerente.setSenha(senhaObj);
            }
            catch (invalid_argument& erro)
            {
                cout << erro.what() << endl;
                tudoOK = false;
            }
        }
        if (tudoOK)
        {
            cout << "Gerente Cadastrado" << endl;
            criado = true;
            vector<Gerente> gerentes = lerGerentes(); // criar o vetor gerentes e armazena na listaGerentes .
            gerentes.push_back(gerente); //  coloca o novo na listaGerentes.
            armazenarGerentes(gerentes);
            // coloca os Gerentes da listaGerentes que esta na memoria para o arquivo Dados_Gerentes.tsv .
        }
        else
        {
            cout << "Gerente nao cadastrado" << endl;
        }
    }
};

vector<Gerente> ServicosGerente::lerGerentes()
{
    vector<Gerente> listaGerentes; // Vetor para COnstruir OBJETOS - GERENTE

    ifstream arquivoLendo("Dados_Gerentes.txt");
    if (arquivoLendo.is_open())
    {
        string linha;
        while (getline(arquivoLendo, linha)) // ler linha , do aqruivo e guarda na linha .
        {
            //cout << "|"<< linha << "|"<< endl; // Debuguer linha
            Gerente gDados;
            gDados.setTSV(linha);
            listaGerentes.push_back(gDados);
        }
        arquivoLendo.close();
    }

    //cout << "Quantidade de Gerrentes na listaGerentes :" << listaGerentes.size() << endl; // Apresenta a qntd da lista
    return listaGerentes;
}

void ServicosGerente::armazenarGerentes(vector<Gerente> gerentes)
{
    ofstream arquivo("Dados_Gerentes.txt");
    if (arquivo.is_open())
    {
        for (int i = 0; i < gerentes.size(); i++)
        {
            arquivo << gerentes[i].getTSV() << endl;;
        }
        arquivo.close();
    }
}


bool ServicosGerente::fazerLoginGerente(string emailCopia, string senhaCopia)
{
    vector<Gerente> gerentes = lerGerentes(); // criar o vetor gerentes e armazena na listaGerentes .
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
            cout << "Informe o Email: " << endl;
            emailCopia = TextoApresentacao::LerLinha();
        }
        if (tudoOK)
        {
            cout << "Informe o Senha: " << endl;
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
        TextoApresentacao::MostrarTituloPergunta("Selecione a opcao desejada");

        TextoApresentacao::MostrarOpcao("Sair", 0);
        cout << endl;
        TextoApresentacao::MostrarOpcao("Gerencie Gerentes", 1);
        TextoApresentacao::MostrarOpcao("Gerencie Hospedes", 2);
        TextoApresentacao::MostrarOpcao("Gerencie Hoteis", 3);
        TextoApresentacao::MostrarOpcao("Gerencie Quartos", 4);
        TextoApresentacao::MostrarOpcao("Gerencie Reservas", 5);

        opcao = TextoApresentacao::RecebeOpcao();
        if (opcao == "0")
        {
            this->gerenteEstaLogado = false;
            cout << "Voce Saiu da Central de servicos e foi deslogado!" << endl;
        }
        else if (opcao == "1")
        {
            exibirCentralDeServicosGerentes();
        }
        else if (opcao == "2")
        {
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
    while (this->getGerenteEstaLogado())
    {
        TextoApresentacao::MostrarTituloEmCaixa("Seja bem vindo a central de servicos");

        string opcao = "";
        TextoApresentacao::MostrarTituloPergunta("Selecione a opcao desejada");

        TextoApresentacao::MostrarOpcao("Sair", 0);
        cout << endl;
        TextoApresentacao::MostrarOpcao("Criar Gerente", 1);
        TextoApresentacao::MostrarOpcao("Editar Gerente", 2);
        TextoApresentacao::MostrarOpcao("Listar Gerente", 3);
        TextoApresentacao::MostrarOpcao("Excluir Gerente", 4);

        opcao = TextoApresentacao::RecebeOpcao();
        if (opcao == "0")
        {
            this->gerenteEstaLogado = false;
            cout << "Voce Saiu da Central de servicos e foi deslogado!" << endl;
        }
        else if (opcao == "1")
        {
            criarGerente();
        }
        else if (opcao == "2")
        {
        }
        else if (opcao == "3")
        {
        }
        else if (opcao == "4")
        {
        }
        else
        {
            cout << "Opcao Invalida!" << endl;
        }
    };
}
