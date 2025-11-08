//
// Created by caleb on 10/10/2025.
//

#include "ControladorInterfaceGerenteAutenticavel.hpp"

#include "FabricaGerenciavel.hpp"
#include "Menu.hpp"
#include "ControladorInterfaceHospede.hpp"
#include "ControladorInterfaceHotel.hpp"
#include "ControladorInterfaceQuarto.hpp"
#include "ControladorInterfaceReserva.hpp"
#include "sqlite3.h"

void ControladorInterfaceGerenteAutenticavel::fazerLogin() {
    bool lacoLogin = false;

    while (!lacoLogin) {
        string emailCopia;
        string senhaCopia;

        ConsoleFormatter::MostrarTituloEmCaixa("Logando com Gerente");

        cout << "Informe o Email: \n";
        emailCopia = ConsoleIO::LerLinha();

        cout << "Informe a Senha: \n";
        senhaCopia = ConsoleIO::LerLinha();

        try {
            Email emailObj(emailCopia);
            Senha senhaObj(senhaCopia);

            if (autenticar(emailObj, senhaObj)) {
                lacoLogin = true;
            } else {
                cout << "Gerente nao cadastrado" << endl;
                ConsoleFormatter::MostrarSubOpcao("Voltar", 0);
                ConsoleFormatter::MostrarSubOpcao("Tentar novamente", 1);
                string opcao = ConsoleIO::LerLinha();
                if (opcao == "0") break;
            }
        } catch (invalid_argument &erro) {
            cout << "Erro: " << erro.what() << endl;
            ConsoleFormatter::MostrarSubOpcao("Voltar", 0);
            ConsoleFormatter::MostrarSubOpcao("Tentar novamente", 1);
            string opcao = ConsoleIO::LerLinha();
            if (opcao == "0") break;
        }
    }
}

/*
void ServicosGerente::excluirMeuCadastro()
{
    if (!gerenteEstaLogado)
    {
        cout << "Voce precisa estar logado para excluir seu cadastro.\n";
        return;
    }
    PersistenciaGerente persistencia;
    bool sucesso = persistencia.excluirPorEmailDoBD(logGerente);

    if (sucesso)
    {
        gerenteEstaLogado = false;
        logGerente = nullptr;
        executando = false; // ou redireciona para menu principal
    }
    else
    {
        cout << "Nao foi possivel excluir seu cadastro.\n";
    }
}
*/