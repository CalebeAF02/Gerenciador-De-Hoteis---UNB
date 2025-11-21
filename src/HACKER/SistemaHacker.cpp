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
        /*
        bool estaAutenticado = servico.getHacke()->autenticar(*emailObj, senhaHK);
        servico.setEstaAutenticado(estaAutenticado);
        if (estaAutenticado) {
            IO::Println("Agora Voce Possui Super-Poderes");
            servico.exibirMenu();
        }
        */
    }
}