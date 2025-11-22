//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CAI_HPP
#define Hotelaria_UnB_TP1_CAI_HPP

#include "Sistema.hpp"

#include "InterfaceApresentacaoAcesso.hpp"
#include "ControladoraApresentacaoGerente.hpp"
#include "InterfaceApresentacaoHospede.hpp"
#include "InterfaceApresentacaoHotel.hpp"
#include "InterfaceApresentacaoQuarto.hpp"
#include "InterfaceApresentacaoReserva.hpp"
#include "InterfaceApresentacaoAutenticavel.hpp"

#include "Utils.hpp"
#include "Menu.hpp"
#include "Tabela.hpp"
#include "IO.hpp"

#include <string>
#include <iostream>
#include <optional>
#include <vector>

#include "ControladoraApresentacaoAcessoHospede.hpp"

using namespace std;
using namespace Utils;
using namespace VisualizadorDeMenu;
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    class ControladoraApresentacaoAcessoGerente : public InterfaceApresentacaoAcesso {
    private:
        InterfaceApresentacaoAutenticavel *apresentacao_autenticavel;
        InterfaceApresentacaoGerente *apresentacao_gerente;
        InterfaceApresentacaoHospede *apresentacao_hospede;
        InterfaceApresentacaoHotel *apresentacao_hotel;
        InterfaceApresentacaoQuarto *apresentacao_quarto;
        InterfaceApresentacaoReserva *apresentacao_reserva;
        //InterfaceapresentacaoSolicitacaoHospedagem *apresentacao_solicitacao_hospedagem;

        bool estaAutenticado = false;

    public:
        void setControladoraApresentacao(InterfaceApresentacaoAutenticavel *apresentacao_autenticavel);

        void setControladoraApresentacao(InterfaceApresentacaoGerente *apresentacao_gerente);

        void setControladoraApresentacao(InterfaceApresentacaoHospede *apresentacao_hospede);

        void setControladoraApresentacao(InterfaceApresentacaoHotel *apresentacao_hotel);

        void setControladoraApresentacao(InterfaceApresentacaoQuarto *apresentacao_quarto);

        void setControladoraApresentacao(InterfaceApresentacaoReserva *apresentacao_reserva);


        void exibirMenu() override;

        void exibirMenuGerenciador();

        InterfaceApresentacaoAutenticavel *getServicoHacker();

        void autenticarHacker();
    };
}


#endif //Hotelaria_UnB_TP1_CAI_HPP