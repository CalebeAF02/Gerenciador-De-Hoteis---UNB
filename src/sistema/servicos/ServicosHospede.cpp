//
// Created by caleb on 10/10/2025.
//

#include "ServicosHospede.h"


void ServicosHospede::acessandoHospede()
{
    string opcao = "";

    while (executando == true)
    {
        TextoApresentacao::MostrarTituloEmCaixa("Faca o acesso para liberar os servicos");

        TextoApresentacao::MostrarOpcao("Voltar", 0);

        TextoApresentacao::MostrarOpcao("Criar Hospede", 1);
        TextoApresentacao::MostrarOpcao("Fazer Login", 2);

        opcao = TextoApresentacao::RecebeOpcao();
        if (opcao == "0")
        {
            executando = false;
            cout << "Voltando a selecao de usuario!" << endl;
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
};


void ServicosHospede::criarHospede()
{
    bool criado = false;

    while (!criado) // Enquanto craido esta falso , ele repete
    {
        TextoApresentacao::MostrarTituloEmCaixa("Criando Novo Hospede");

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
            cout << "Hospede Cadastrado" << endl;
            criado = true;
            vector<Hospede> hospedes = lerHospede(); // criar o vetor Hospedes e armazena na listaHospedes .
            hospedes.push_back(hospede); //  coloca o novo na listaHospedes.
            armazenarHospedes(hospedes);
            // coloca os Hospedes da listaHospedes que esta na memoria para o arquivo Dados_Usuarios.tsv .
        }
        else
        {
            cout << "Hospede nao cadastrado" << endl;
        }
    }
};

vector<Hospede> ServicosHospede::lerHospede()
{
    vector<Hospede> listaHospedes; // Vetor para Construir OBJETOS - HOSPEDE

    ifstream arquivoLendo("Dados_Hospedes.txt");
    if (arquivoLendo.is_open())
    {
        string linha;
        while (getline(arquivoLendo, linha)) // ler linha , do aqruivo e guarda na linha .
        {
            //cout << "|"<< linha << "|"<< endl; // Debuguer linha
            Hospede gDados;
            gDados.setTSV(linha);
            listaHospedes.push_back(gDados);
        }
        arquivoLendo.close();
    }

    //cout << "Quantidade de Hospedes na listaHospedes :" << listaHospedes.size() << endl; // Apresenta a qntd da lista
    return listaHospedes;
}

void ServicosHospede::armazenarHospedes(vector<Hospede> hospedes)
{
    ofstream arquivo("Dados_Hospedes.txt");
    if (arquivo.is_open())
    {
        for (int i = 0; i < hospedes.size(); i++)
        {
            arquivo << hospedes[i].getTSV() << endl;;
        }
        arquivo.close();
    }
}


bool ServicosHospede::fazerLoginHospede(string emailCopia)
{
    vector<Hospede> hospedes = lerHospede(); // criar o vetor gerentes e armazena na listaGerentes .
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

    while (!lacoLogin)
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
    }
}


void ServicosHospede::exibirCentralDeServicosHospede()
{
    while (this->getHospedeEstaLogado())
    {
        TextoApresentacao::MostrarTituloEmCaixa("Seja bem vindo a central de servicos");

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
            this->hospedeEstaLogado = false;
            cout << "Voce Saiu da Central de servicos e foi deslogado!" << endl;
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