//
// Created by caleb on 28/09/2025.
//

#include "../../include/sistema/SistemaHotel.h"

#include "TextoApresentacao.h"
#include "sistema/Servicos.h"

void SistemaHotel::rodandoSistema()
{
    TextoApresentacao::MostrarTituloEmCaixa("Seja bem vindo ao gerenciador de hoteis");
    TextoApresentacao::MostrarTituloPergunta("Selecione a opcao");

    TextoApresentacao::MostrarOpcao("Sair", 0);
    cout << endl;
    TextoApresentacao::MostrarOpcao("Criar gerente", 1);
    TextoApresentacao::MostrarOpcao("Fazer Login", 2);

    string opcao = "";

    do
    {
        opcao = TextoApresentacao::RecebeOpcao();
        if (opcao == "0")
        {
            executando = false;
            break;
        }
        else if (opcao == "1")
        {
            servicos.criarGerente();
        }
        else if (opcao == "2")
        {
            servicos.loginGerente();
            if (servicos.getGerenteEstaLogado())
            {
                cout << "Agora Voce Possui Super-Poderes" << endl;
                servicos.exibirCentralDeServicos();
            }
        }
        else
        {
            cout << "Opcao Invalida!" << endl;
        }
    }
    while (opcao != "1" && opcao != "2");
};

bool SistemaHotel::fazerLogin(string copiaLogin, string senhaLogin)
{
    return servicos.fazerLogin(copiaLogin, senhaLogin);
};

void SistemaHotel::menuSistema()
{
    servicos.exibirCentralDeServicos();
};
