//
// Created by caleb on 08/11/2025.
//

#include "../../include/HACKER/SistemaHacker.hpp"


void SistemaHacker::iniciar() {
    ConsoleIO::PrintMenssagem("Versao " + Versao::getVersaoCompleta());

    Email emailHK("calebe.2324@gmail.com");
    Senha senhaHK("A1!b2");
    controladorGerente.autenticar(emailHK, senhaHK);
    if (controladorGerente.getEstaLogado()) {
        ConsoleIO::PrintMenssagem("Agora Voce Possui Super-Poderes");
        controladorGerente.exibirMenu();
    }
}