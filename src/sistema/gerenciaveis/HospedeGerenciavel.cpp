//
// Created by caleb on 16/10/2025.
//

#include "../../../include/sistema/gerenciaveis/HospedeGerenciavel.h"

void HospedeGerenciavel::criar()
{
    bool criado = false;
    bool tudoOK = true;

    while (!criado) // Enquanto craido esta falso , ele repete
    {
        Hospede* hospede = new Hospede();

        if (hospede)
        {
            //Preencher atribultos com validação
            if (tudoOK == false)
            {
                cout << "\nRetornando...\n\n";
                break;
            }

            TextoApresentacao::MostrarTituloEmCaixa("Criando Novo Hospede");

            cout << "Informe o Nome: " << endl;
            string nomeStr = TextoApresentacao::LerLinha();
            try
            {
                hospede->setNome(Nome(nomeStr));
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
                    hospede->setEmail(Email(emailStr));
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
                string enderecoStr = TextoApresentacao::LerLinha();
                try
                {
                    hospede->setEndereco(Endereco(enderecoStr));
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
                string cartaoStr = TextoApresentacao::LerLinha();
                try
                {
                    ;
                    hospede->setCartao(Cartao(cartaoStr));
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

                PersistenciaHospede dao;
                dao.criar(*hospede);

                criado = true;
                cout << "Hospede cadastrado!\n";
                // coloca os Hospedes da listaGerentes que esta na memoria para o arquivo Dados_Gerentes.tsv .
            }
            else
            {
                cout << "Ops* Hospede nao cadastrado!\n";
            }
            delete hospede; // Liberar o ponteiro da memoria.
        }
    }
};

void HospedeGerenciavel::ler()
{
    vector<Hospede*> listaHospedes = dao.listar(); // Vetor para Construir OBJETOS - HOSPEDE

    if (listaHospedes.empty())
    {
        cout << "Nenhum hospede cadastrado.\n";
        return;
    }

    TextoApresentacao::MostrarTituloEmCaixa("Lista de Gerentes");

    for (const auto& g : listaHospedes)
    {
        cout << "Nome: " << g->getNome() << endl;
        cout << "Email: " << g->getEmail() << endl;
        cout << "Endereco: " << g->getEndereco() << endl;
        cout << "Cartao: " << g->getCartao() << endl;
        cout << "-----------------------------\n";
    }
}

void HospedeGerenciavel::atualizar()
{
    // TODO: implementar lógica de edição
    std::cout << "Função atualizar ainda não implementada.\n";
}

bool HospedeGerenciavel::remover()
{
    cout << "Informe o Email: \n";
    string emailStr = TextoApresentacao::LerLinha();
    bool status = true; //dao.excluirPorEmail(emailStr);

    if (status == true)
    {
        cout << "Foi excluido com sucesso!\n";
    }
    else
    {
        cout << "Gerente nao encontrado!\n";
    }
    return status;
}