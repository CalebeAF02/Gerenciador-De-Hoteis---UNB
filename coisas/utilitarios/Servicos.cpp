#include "Servicos.h"

void Servicos::criarGerente()
{
    TextoApresentacao::MostrarTituloEmCaixa("Criando Novo Gerente");

    Gerente gerente;

    bool tudoOK = true;

    cout<<"Informe o Nome: "<<endl;
    string nome = "";
    cin>>nome;
    try
    {
        gerente.setNome(nome);
    }
    catch(invalid_argument &erro)
    {
        cout<<erro.what()<<endl;
        tudoOK = false;
    }
    if(tudoOK)
    {
        cout<<"Informe o Email: "<<endl;
        string email = "";
        cin>>email;
        try
        {
            gerente.setEmail(email);
        }
        catch(invalid_argument &erro)
        {
            cout<<erro.what()<<endl;
            tudoOK = false;
        }

    }
};
