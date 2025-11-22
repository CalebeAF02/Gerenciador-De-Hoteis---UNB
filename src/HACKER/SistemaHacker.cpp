//
// Created by caleb on 08/11/2025.
//

#include "SistemaHacker.hpp"

namespace Hotelaria {
    SistemaHacker::SistemaHacker(ControladoraApresentacaoAcessoGerente *apresentacao_acesso_gerente,
                 ControladoraApresentacaoAcessoHospede *apresentacao_acesso_hospede) {
        this->apresentacao_acesso_gerente = apresentacao_acesso_gerente;
        this->apresentacao_acesso_hospede = apresentacao_acesso_hospede;
    }

    void SistemaHacker::iniciar() {
        IO::Println("Versao " + Versao::getVersaoCompleta());

        Email emailHK;
        emailHK.setValor("calebe.2324@gmail.com");
        Email *emailObj = &emailHK;

        Senha senhaHK("A1!b2");

        bool estaAutenticado = apresentacao_acesso_gerente->getServicoHacker()->getHacke()->autenticar(*emailObj, senhaHK);
        apresentacao_acesso_gerente->autenticarHacker();
        apresentacao_acesso_gerente->getServicoHacker()->setEstaAutenticado(true);
        if (estaAutenticado) {
            IO::Println("Agora Voce Possui Super-Poderes");
            apresentacao_acesso_gerente->exibirMenuGerenciador();
        }
    }
}