//
// Created by caleb on 14/11/2025.
//

#include "ControladoraApresentacaoAutenticavel.hpp"
namespace Hotelaria {
    bool ControladoraApresentacaoAutenticavel::autenticar(Email *emailObj) {
        bool lacoLogin = false;
        bool resultado;

        while (!lacoLogin) {
            string emailCopia;
            string senhaCopia;

            Formato::TituloEmCaixa("Logando com Gerente");

            IO::Print("Informe o Email: ");
            emailCopia = IO::LerLinha();

            IO::Print("Informe a Senha: ");
            senhaCopia = IO::LerLinha();

            try {
                emailObj->setValor(emailCopia);
                Senha senhaObj(senhaCopia);

                resultado = controladora_servico_autenticavel->autenticar(*emailObj, senhaObj); // Solicitar autenticação.

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