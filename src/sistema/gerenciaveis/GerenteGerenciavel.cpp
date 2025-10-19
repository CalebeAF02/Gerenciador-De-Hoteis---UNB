//
// Created by caleb on 16/10/2025.
//

#include "../../../include/sistema/gerenciaveis/GerenteGerenciavel.h"

void GerenteGerenciavel::criar()
{
    bool criado = false;
    bool tudoOK = true;

    while (!criado) // Enquanto craido esta falso , ele repete
    {
        Gerente* gerente = new Gerente();

        if (gerente)
        {
            //Preencher atribultos com validação
            if (tudoOK == false)
            {
                cout << "\nRetornando...\n\n";
                break;
            }

            TextoApresentacao::MostrarTituloEmCaixa("Criando Novo Gerente");

            cout << "Informe o Nome: \n";
            string nomeStr = TextoApresentacao::LerLinha();
            try
            {
                gerente->setNome(Nome(nomeStr));
            }
            catch (invalid_argument& erro)
            {
                cout << erro.what() << endl;
                tudoOK = false;
            }
            if (tudoOK)
            {
                cout << "Informe o Email: \n";
                string emailStr = TextoApresentacao::LerLinha();
                try
                {
                    gerente->setEmail(Email(emailStr));
                }
                catch (invalid_argument& erro)
                {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK)
            {
                cout << "Informe o Ramal: \n";
                string ramalStr = TextoApresentacao::LerLinha();
                try
                {
                    gerente->setRamal(Ramal(ramalStr));
                }
                catch (invalid_argument& erro)
                {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK)
            {
                cout << "Informe o Senha: \n";
                string senhaStr = TextoApresentacao::LerLinha();
                try
                {
                    gerente->setSenha(Senha(senhaStr));
                }
                catch (invalid_argument& erro)
                {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK)
            {
                cout << "Gerente Cadastrado!\n";
                criado = true;

                PersistenciaGerente dao;
                dao.adicionar(*gerente);

                criado = true;
                cout << "Gerente cadastrado!\n";
                // coloca os Gerentes da listaGerentes que esta na memoria para o arquivo Dados_Gerentes.tsv .
            }
            else
            {
                cout << "Ops* Gerente nao cadastrado!\n";
            }
            delete gerente; // Liberar o ponteiro da memoria.
        }
    };
}

void GerenteGerenciavel::ler()
{
    vector<Gerente> listaGerentes = dao.listar();

    if (listaGerentes.empty())
    {
        cout << "Nenhum gerente cadastrado.\n";
        return;
    }

    TextoApresentacao::MostrarTituloEmCaixa("Lista de Gerentes");

    for (const auto& g : listaGerentes)
    {
        cout << "Nome: " << g.getNome() << endl;
        cout << "Email: " << g.getEmail() << endl;
        cout << "Ramal: " << g.getRamal() << endl;
        cout << "-----------------------------\n";
    }
}

void GerenteGerenciavel::atualizar()
{
    // TODO: implementar lógica de edição
    std::cout << "Função atualizar ainda não implementada.\n";
}

void GerenteGerenciavel::excluir()
{
    // TODO: implementar lógica de exclusão
    std::cout << "Função excluir ainda não implementada.\n";
}
