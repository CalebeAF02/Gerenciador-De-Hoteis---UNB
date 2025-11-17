//
// Created by caleb on 08/11/2025.
//

#include "SistemaHacker.hpp"

namespace Hotelaria {
    void SistemaHacker::iniciar() {

        IO::Println("Versao " + Versao::getVersaoCompleta());

        Email emailHK;
        emailHK.setValor("calebe.2324@gmail.com");
        Email *emailObj = &emailHK;

        Senha senhaHK("A1!b2");

        bool estaAutenticado = controladorGerente.getHacke()->autenticar(*emailObj, senhaHK);
        controladorGerente.setEstaAutenticado(estaAutenticado);
        if (estaAutenticado) {
            IO::Println("Agora Voce Possui Super-Poderes");
            controladora_apresentacao_acesso_gerente.exibirMenu();
        }

    }
}