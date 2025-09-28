#include "Servicos.h"

#include <limits>

void Servicos::criarGerente()
{
    TextoApresentacao::MostrarTituloEmCaixa("Criando Novo Gerente");


    bool criado = false;

    while (!criado) // Enquanto craido esta falso , ele repete
    {
        Gerente gerente;

        bool tudoOK = true;
        cout << "Informe o Nome: " << endl;
        string nome = TextoApresentacao::LerLinha();
        try
        {
            gerente.setNome(nome);
        }
        catch (invalid_argument& erro)
        {
            cout << erro.what() << endl;
            tudoOK = false;
        }
        if (tudoOK)
        {
            cout << "Informe o Email: " << endl;
            string email = TextoApresentacao::LerLinha();
            try
            {
                gerente.setEmail(email);
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
                gerente.setRamal(ramal);
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
                gerente.setSenha(senha);
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

vector<Gerente> Servicos::lerGerentes()
{
    vector<Gerente> listaGerentes; // Vetor para COnstruir OBJETOS - GERENTE

    ifstream arquivoLendo("Dados_Gerentes.txt");
    if (arquivoLendo.is_open())
    {
        string linha;
        while (getline(arquivoLendo, linha)) // ler linha , do aqruivo e guarda na linha .
        {
            //cout << "|"<< linha << "|"<< endl; // Debuguer linha
            Gerente g4;
            g4.setTSV(linha);
            listaGerentes.push_back(g4);
        }
        arquivoLendo.close();
    }

    //cout << "Quantidade de Gerrentes na listaGerentes :" << listaGerentes.size() << endl; // Apresenta a qntd da lista
    return listaGerentes;
}

void Servicos::armazenarGerentes(vector<Gerente> gerentes)
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


void Servicos::loginGerente()
{
    TextoApresentacao::MostrarTituloEmCaixa("Logue com Gerente");
    bool lacoLogin = false;
    string emailCopia = "";
    string senhaCopia = "";

    while (!lacoLogin) // Enquanto craido esta falso , ele repete
    {
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
                        lacoLogin = true;
                        this->gerenteEstaLogado = true;
                        this->gerenteLogado = gerentes[i];
                    }
                    break;
                }
            }
            if (!loginOK)
            {
                cout << "Erro: Usuario nao encontrado ou senha incorreta!" << endl;
            }
        }
        else
        {
            cout << "Gerente nao cadastrado" << endl;
        }
    }
};

void Servicos::exibirCentralDeServicos()
{
    TextoApresentacao::MostrarTituloEmCaixa("Seja bem vindo a central de servicos");
    while (this->getGerenteEstaLogado())
    {
        string opcao = "";
        TextoApresentacao::MostrarTituloPergunta("Selecione a opcao desejada");

        TextoApresentacao::MostrarOpcao("Sair", 0);
        cout << endl;
        TextoApresentacao::MostrarOpcao("Criar gerente", 1);
        TextoApresentacao::MostrarOpcao("Editar gerente", 2);
        TextoApresentacao::MostrarOpcao("Listar gerente", 3);
        TextoApresentacao::MostrarOpcao("Excluir gerente", 4);

        opcao = TextoApresentacao::RecebeOpcao();
        if (opcao == "0")
        {
            this->sairDosServicos();
        }
        else if (opcao == "1")
        {
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

void Servicos::sairDosServicos()
{
    this->gerenteEstaLogado = false;
    cout << "Voce Saiu da Central de servicos e foi deslogado!" << endl;
};
