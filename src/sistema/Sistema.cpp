//
// Created by caleb on 28/09/2025.
//

#include "Sistema.h"

void Sistema::rodandoSistema()
{
    string opcao = "";

    while (executando == true)
    {
        TextoApresentacao::MostrarTituloEmCaixa("Seja bem vindo ao gerenciador de hoteis");
        TextoApresentacao::MostrarTituloPergunta("Selecione a opcao");
        cout << endl;
        TextoApresentacao::MostrarOpcao("Sair", 0);
        cout << endl;
        TextoApresentacao::MostrarOpcao("Entrar como Gerente", 1);
        TextoApresentacao::MostrarOpcao("Entrar como Hospede", 2);

        opcao = TextoApresentacao::RecebeOpcao();
        if (opcao == "0")
        {
            executando = false;
            cout << "Encerrando o sistema..." << endl;
        }
        else if (opcao == "1")
        {
            servicosGerente.acessandoGerente();
        }
        else if (opcao == "2")
        {
            servicosHospede.acessandoHospede();
        }
        else
        {
            cout << "Opcao Invalida!" << endl;
        }
    }
};