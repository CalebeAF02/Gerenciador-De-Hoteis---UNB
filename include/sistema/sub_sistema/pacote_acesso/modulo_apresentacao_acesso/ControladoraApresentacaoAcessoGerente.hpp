//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CAI_HPP
#define Hotelaria_UnB_TP1_CAI_HPP

#include "../../../../../libs/io/IO.hpp"
#include <iostream>
#include "Menu.hpp"
#include "../InterfaceApresentacaoAcesso.hpp"
#include "ControladorInterfaceGerente.hpp"
#include "ControladorInterfaceHospede.hpp"
#include "ControladorInterfaceHotel.hpp"
#include "ControladorInterfaceQuarto.hpp"
#include "ControladorInterfaceReserva.hpp"

using namespace std;
using namespace VisualizadorDeMenu;

namespace Hotelaria {
    class ControladoraApresentacaoAcessoGerente : public InterfaceApresentacaoAcesso {
    private:
        InterfaceServicoAcesso *controladora_servico_acesso_gerente;

        ControladorInterfaceGerente controladorGerente;

    public:
        void exibirMenu() override;

        void setControladoraServicoAcesso(InterfaceServicoAcesso *) override;

        void exibirMenuGerenciador();
    };
}


#endif //Hotelaria_UnB_TP1_CAI_HPP