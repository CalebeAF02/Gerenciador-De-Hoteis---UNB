//
// Created by caleb on 01/11/2025.
//

#include "ControleInterfaceGerenteAutenticavel.h"

bool ControleInterfaceGerenteAutenticavel::autenticar(Email &emailCopia, Senha &senhaCopia) {
    PersistenciaGerente dao;
    bool gerenteLogado = dao.autenticarGerentePeloBD(emailCopia.getValor(), senhaCopia.getValor());

    if (gerenteLogado) {
        this->estaLogado = true;
        std::cout << "Login realizado com sucesso!\n";
        return true;
    } else {
        std::cout << "Erro: Usuario nao encontrado ou senha incorreta!\n";
        return false;
    }
};


void ControleInterfaceGerenteAutenticavel::fazerLogin() {
    bool lacoLogin = false;
    string emailCopia = "";
    string senhaCopia = "";

    while (!lacoLogin) // Enquanto esta falso , ele repete
    {
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
            Email emailObj(emailCopia);
            Senha senhaObj(senhaCopia);
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
        } else {
            cout << "Gerente nao cadastrado" << endl;
        }
    }
};