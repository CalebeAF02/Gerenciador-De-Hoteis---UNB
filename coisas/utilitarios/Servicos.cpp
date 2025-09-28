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
            gerentes.push_back(gerente);  //  coloca o novo na listaGerentes.
            armazenarGerentes(gerentes); // coloca os Gerentes da listaGerentes que esta na memoria para o arquivo Dados_Gerentes.tsv .
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
            cout << linha << endl;
            Gerente g4;
            g4.setTSV(linha);
            listaGerentes.push_back(g4);
        }
        arquivoLendo.close();
    }

    cout << "Quantidade de Gerrentes na listaGerentes :" << listaGerentes.size() << endl;
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
