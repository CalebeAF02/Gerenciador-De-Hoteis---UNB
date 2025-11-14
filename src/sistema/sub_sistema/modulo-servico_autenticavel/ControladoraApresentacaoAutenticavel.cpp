//
// Created by caleb on 14/11/2025.
//

#include "ControladoraApresentacaoAutenticavel.hpp"

bool ControladoraApresentacaoAutenticavel::autenticar(Email *email) {
    bool resultado;
    Senha senha;
    string entrada;

    // Solicitar email e senha.
    while (true) {
        try {
            cout << "Digite o email     : ";
            cin >> entrada;
            email->setValor(entrada);
            cout << "Digite a senha     : ";
            cin >> entrada;
            senha.setValor(entrada);
            break;
        } catch (const invalid_argument &exp) {
            cout << endl << "Dado em formato incorreto." << endl;
        }
    }

    resultado = controladora_servico_autenticavel->autenticar(*email, senha); // Solicitar autenticação.

    return resultado; // Informar resultado da autenticação.
}