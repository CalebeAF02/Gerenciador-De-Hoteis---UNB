//
// Created by caleb on 08/11/2025.
//

#include "SistemaHacker.hpp"

#include "ControladoraPersistenciaGerente.hpp"

namespace Hotelaria {
    SistemaHacker::SistemaHacker() {
    }

    void SistemaHacker::iniciar() {
        IO::Println("Versao " + Versao::getVersaoCompleta());

        Email emailHK;
        emailHK.setValor("calebe.2324@gmail.com");
        Email *emailObj = &emailHK;

        Senha senhaHK;
        senhaHK.setValor("A1!b2");


        // Instanciando todas as controladoras
        ControladoraApresentacaoAcessoGerente acessoGerente;
        ControladoraApresentacaoAutenticavel autenticador;
        ControladoraApresentacaoGerente apresentacaoGerente;
        ControladoraApresentacaoHospede apresentacaoHospede;
        ControladoraApresentacaoHotel apresentacaoHotel;
        ControladoraApresentacaoQuarto apresentacaoQuarto;
        ControladoraApresentacaoReserva apresentacaoReserva;

        ControladoraApresentacaoAcessoHospede acessoHospede;

        // Injetando dependências
        acessoGerente.setControladoraApresentacao(&autenticador);
        acessoGerente.setControladoraApresentacao(&apresentacaoGerente);
        acessoGerente.setControladoraApresentacao(&apresentacaoHospede);
        // aqui é válido porque a classe implementa a interface
        acessoGerente.setControladoraApresentacao(&apresentacaoHotel);
        acessoGerente.setControladoraApresentacao(&apresentacaoQuarto);
        acessoGerente.setControladoraApresentacao(&apresentacaoReserva);

        acessoHospede.setControladoraApresentacao(&apresentacaoHospede);

        // Instanciando serviços e persistências
        ControladoraServicoAutenticavel servAutenticavel;
        ControladoraPersistenciaAutenticavel perAutenticavel;
        servAutenticavel.setControladoraPersistencia(&perAutenticavel);
        autenticador.setControladoraServicoAutenticavel(&servAutenticavel);

        ControladoraServicoGerente servGerente;
        ControladoraPersistenciaGerente perGerente;
        servGerente.setControladoraPersistencia(&perGerente);
        apresentacaoGerente.setControladoraServicoGerente(&servGerente);

        ControladoraServicoHospede servHospede;
        ControladoraPersistenciaHospede perHospede;
        servHospede.setControladoraPersistencia(&perHospede);
        apresentacaoHospede.setControladoraServicoHospede(&servHospede);

        ControladoraServicoHotel servHotel;
        ControladoraPersistenciaHotel perHotel;
        servHotel.setControladoraPersistencia(&perHotel);
        apresentacaoHotel.setControladoraServicoHotel(&servHotel);

        ControladoraServicoQuarto servQuarto;
        ControladoraPersistenciaQuarto perQuarto;
        servQuarto.setControladoraPersistencia(&perQuarto);
        apresentacaoQuarto.setControladoraServicoQuarto(&servQuarto);

        ControladoraServicoReserva servReserva;
        ControladoraPersistenciaReserva perReserva;
        servReserva.setControladoraPersistencia(&perReserva);
        apresentacaoReserva.setControladoraServicoReserva(&servReserva);


        ControladoraPersistenciaGerente persistencia_gerente;
        if (!persistencia_gerente.existeEmail(emailObj->getValor())) {
            Gerente gerenteHakeado(Nome("Calebe"), Email("calebe.2324@gmail.com"), Ramal("01"), Senha("A1!b2"));
            persistencia_gerente.inserir(gerenteHakeado);
        }


        bool estaAutenticado = acessoGerente.getServicoHacker()->getHacke()->autenticar(*emailObj, senhaHK);

        IO::Println("@@@ DEBUG !");

        acessoGerente.autenticarHacker();
        acessoGerente.getServicoHacker()->setEstaAutenticado(true);
        if (estaAutenticado) {
            IO::Println("Agora Voce Possui Super-Poderes");
            acessoGerente.exibirMenuGerenciador();
        }
    }
}