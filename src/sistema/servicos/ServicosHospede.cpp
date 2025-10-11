//
// Created by caleb on 10/10/2025.
//

#include "ServicosHospede.h"


void ServicosHospede::acessandoHospede()
{
    TextoApresentacao::MostrarTituloEmCaixa("Faca o acesso para liberar os servicos");

    TextoApresentacao::MostrarOpcao("Voltar", 0);

    TextoApresentacao::MostrarOpcao("Criar Hospede", 1);
    TextoApresentacao::MostrarOpcao("Fazer Login", 2);

    string opcao = "";

    do
    {
        opcao = TextoApresentacao::RecebeOpcao();
        if (opcao == "0")
        {
            this->executando = false;
            break;
        }
        else if (opcao == "1")
        {
            criarHospede();
        }
        else if (opcao == "2")
        {
            logandoHospede();
            if (getHospedeEstaLogado())
            {
                cout << "Agora Voce Possui Super-Poderes" << endl;
                exibirCentralDeServicosHospede();
            }
        }
        else
        {
            cout << "Opcao Invalida!" << endl;
        }
    }
    while (opcao != "1" && opcao != "2");
};


void ServicosHospede::criarHospede()
{
    TextoApresentacao::MostrarTituloEmCaixa("Criando Novo Hospede");


    bool criado = false;

    while (!criado) // Enquanto craido esta falso , ele repete
    {
        Hospede hospede;

        bool tudoOK = true;
        cout << "Informe o Nome: " << endl;
        string nomeStr = TextoApresentacao::LerLinha();
        try
        {
            Nome nomeObj(nomeStr);
            hospede.setNome(nomeObj);
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
                hospede.setEmail(emailObj);
            }
            catch (invalid_argument& erro)
            {
                cout << erro.what() << endl;
                tudoOK = false;
            }
        }
        if (tudoOK)
        {
            cout << "Informe o Endereco: " << endl;
            string endereco = TextoApresentacao::LerLinha();
            try
            {
                Endereco enderecoObj(endereco);
                hospede.setEndereco(enderecoObj);
            }
            catch (invalid_argument& erro)
            {
                cout << erro.what() << endl;
                tudoOK = false;
            }
        }
        if (tudoOK)
        {
            cout << "Informe o Cartao: " << endl;
            string cartao = TextoApresentacao::LerLinha();
            try
            {
                Cartao cartaoObj(cartao);
                hospede.setCartao(cartaoObj);
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
            vector<Hospede> gerentes = lerHospede(); // criar o vetor gerentes e armazena na listaGerentes .
            gerentes.push_back(hospede); //  coloca o novo na listaGerentes.
            armazenarHospedes(gerentes);
            // coloca os Gerentes da listaGerentes que esta na memoria para o arquivo Dados_Gerentes.tsv .
        }
        else
        {
            cout << "Gerente nao cadastrado" << endl;
        }
    }
};

vector<Hospede> ServicosHospede::lerHospede()
{
    vector<Hospede> listaGerentes; // Vetor para COnstruir OBJETOS - GERENTE

    ifstream arquivoLendo("Dados_Gerentes.txt");
    if (arquivoLendo.is_open())
    {
        string linha;
        while (getline(arquivoLendo, linha)) // ler linha , do aqruivo e guarda na linha .
        {
            //cout << "|"<< linha << "|"<< endl; // Debuguer linha
            Hospede gDados;
            gDados.setTSV(linha);
            listaGerentes.push_back(gDados);
        }
        arquivoLendo.close();
    }

    //cout << "Quantidade de Gerrentes na listaGerentes :" << listaGerentes.size() << endl; // Apresenta a qntd da lista
    return listaGerentes;
}

void ServicosHospede::armazenarHospedes(vector<Hospede> hospedes)
{
    ofstream arquivo("Dados_Hospede.txt");
    if (arquivo.is_open())
    {
        for (int i = 0; i < hospedes.size(); i++)
        {
            arquivo << hospedes[i].getTSV() << endl;;
        }
        arquivo.close();
    }
}


bool ServicosHospede::fazerLoginHospede(string emailCopia, string senhaCopia)
{
    vector<Hospede> hospedes = lerHospede(); // criar o vetor gerentes e armazena na listaGerentes .
    //cout<<"-------------------"<<endl;
    bool loginOK = false;
    for (int i = 0; i < hospedes.size(); i++)
    {
        if (hospedes[i].getEmail() == emailCopia)
        {
            if (hospedes[i].getCartao() == senhaCopia)
            {
                cout << "Login Realizado com Sucesso" << endl;
                loginOK = true;
                this->hospedeEstaLogado = true;
                this->logHospede = hospedes[i];
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

void ServicosHospede::logandoHospede()
{
    TextoApresentacao::MostrarTituloEmCaixa("Logando com Hospede");
    bool lacoLogin = false;
    string emailCopia = "";
    string senhaCopia = "";

    while (!lacoLogin) // Enquanto esta falso , ele repete
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

            if (fazerLoginHospede(emailCopia, senhaCopia))
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


void ServicosHospede::exibirCentralDeServicosHospede()
{
    TextoApresentacao::MostrarTituloEmCaixa("Seja bem vindo a central de servicos");
    while (this->getHospedeEstaLogado())
    {
        string opcao = "";
        TextoApresentacao::MostrarTituloPergunta("Selecione a opcao desejada");

        TextoApresentacao::MostrarOpcao("Sair", 0);
        cout << endl;
        TextoApresentacao::MostrarOpcao("Criar Hospede", 1);
        TextoApresentacao::MostrarOpcao("Editar Hospede", 2);
        TextoApresentacao::MostrarOpcao("Listar Hospede", 3);
        TextoApresentacao::MostrarOpcao("Excluir Hospede", 4);

        opcao = TextoApresentacao::RecebeOpcao();
        if (opcao == "0")
        {
            this->sairDosServicosHospede();
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


void ServicosHospede::sairDosServicosHospede()
{
    this->hospedeEstaLogado = false;
    cout << "Voce Saiu da Central de servicos e foi deslogado!" << endl;
};
