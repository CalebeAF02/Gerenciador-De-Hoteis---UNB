//
// Created by caleb on 14/11/2025.
//

#include "ControladoraApresentacaoAutenticavel.hpp"

namespace Hotelaria {
    void ControladoraApresentacaoAutenticavel::setControladoraServicoAutenticavel(
        InterfaceServicoAutenticavel *servico) {
        this->servico = servico;
    }

    void ControladoraApresentacaoAutenticavel::setEstaAutenticado(bool estaAutenticado) {
        this->estaAutenticado = estaAutenticado;
    }

    bool ControladoraApresentacaoAutenticavel::getEstaAutenticado() {
        return estaAutenticado;
    }

    InterfaceServicoAutenticavel *ControladoraApresentacaoAutenticavel::getHacke() {
        return this->servico;
    }

    bool ControladoraApresentacaoAutenticavel::autenticar() {
        bool lacoLogin = false;
        bool resultado = false;

        while (!lacoLogin) {
            string emailCopia;
            string senhaCopia;

            Formato::TituloEmCaixa("Logando como Gerente");

            IO::Print("Informe o Email: ");
            emailCopia = IO::LerLinha();

            IO::Print("Informe a Senha: ");
            senhaCopia = IO::LerLinha();

            try {
                Email emalObj(emailCopia);
                Senha senhaObj(senhaCopia);

                resultado = servico->autenticar(emalObj, senhaObj);
                IO::Println("Debug----------------------");
                if (resultado) {
                    this->setEstaAutenticado(true);
                }

                if (!resultado) {
                    IO::Println("Gerente nao cadastrado");
                    IO::tentarNovamente();
                }
                lacoLogin = true;
            } catch (invalid_argument &erro) {
                cout << "Erro: " << erro.what() << endl;
                IO::tentarNovamente();
            }
        }
        return resultado; // Informar resultado da autenticação.
    }
}