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

        Formato::TituloEmCaixa("Logando com Gerente");

        IO::Print("Informe o Email: ");
        emailCopia = IO::LerLinha();

        IO::Print("Informe a Senha: ");
        senhaCopia = IO::LerLinha();

        try {
            Email emailObj(emailCopia);
            Senha senhaObj(senhaCopia);

            if (autenticar(emailObj, senhaObj)) {
                lacoLogin = true;
            } else {
                IO::Println("Gerente nao cadastrado");
                IO::tentarNovamente();
            }
        } catch (invalid_argument &erro) {
            cout << "Erro: " << erro.what() << endl;
            IO::tentarNovamente();
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
