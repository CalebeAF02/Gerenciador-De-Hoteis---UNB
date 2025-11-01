//
// Created by caleb on 10/10/2025.
//

#include "ControladorInterfaceGerenteAutenticavel.h"

#include "FabricaGerenciavel.h"
#include "Menu.h"
#include "ControladorInterfaceHospede.h"
#include "ControladorInterfaceHotel.h"
#include "ControladorInterfaceQuarto.h"
#include "ControladorInterfaceReserva.h"
#include "sqlite3.h"

void ControladorInterfaceGerenteAutenticavel::fazerLogin() {
    bool lacoLogin = false;

    while (!lacoLogin) // Enquanto esta falso , ele repete
    {
        string emailCopia = "";
        string senhaCopia = "";

        TextoApresentacao::MostrarTituloEmCaixa("Logando com Gerente");

        bool tudoOK = true;
        if (tudoOK) {
            cout << "Informe o Email: \n";
            emailCopia = TextoApresentacao::LerLinha();
        }
        if (tudoOK) {
            cout << "Informe o Senha: \n";
            senhaCopia = TextoApresentacao::LerLinha();
        }
        if (tudoOK) {
            try {
                Email emailObj(emailCopia);
                Senha senhaObj(senhaCopia);
                // chama servico
                if (autenticar(emailObj, senhaObj)) {
                    lacoLogin = true;
                } else {
                    TextoApresentacao::MostrarOpcao("Voltar", 0);
                    TextoApresentacao::MostrarOpcao("Tentar novamente", 1);
                    string opcao = TextoApresentacao::LerLinha();
                    if (opcao == "0") {
                        break;
                    } else if (opcao == "1") {
                        lacoLogin = false;
                    }
                }
            } catch (invalid_argument &erro) {
                TextoApresentacao::MostrarOpcao("Voltar", 0);
                TextoApresentacao::MostrarOpcao("Tentar novamente", 1);
                string opcao = TextoApresentacao::LerLinha();
                if (opcao == "0") {
                    break;
                } else if (opcao == "1") {
                    lacoLogin = false;
                }
            }
        } else {
            cout << "Gerente nao cadastrado" << endl;
        }
    }
};

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