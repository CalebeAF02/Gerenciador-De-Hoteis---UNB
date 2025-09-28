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
        }
        else
        {
            cout << "Gerente nao cadastrado" << endl;
        }
    }
};
