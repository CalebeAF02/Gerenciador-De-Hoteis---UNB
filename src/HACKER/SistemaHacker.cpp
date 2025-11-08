//
// Created by caleb on 08/11/2025.
//

#include "../../include/HACKER/SistemaHacker.hpp"


void SistemaHacker::iniciar() {
    Email emailHK("calebe.2324@gmail.com");
    Senha senhaHK("A1!b2");
    controladorGerente.autenticar(emailHK, senhaHK);
    if (controladorGerente.getEstaLogado()) {
        cout << "Agora Voce Possui Super-Poderes" << endl;
        controladorGerente.exibirMenu();
    }
}