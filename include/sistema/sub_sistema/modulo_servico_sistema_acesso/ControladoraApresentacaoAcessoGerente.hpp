//
// Created by caleb on 14/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_CAI_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_CAI_HPP

#include "../../../../libs/io/IO.hpp"
#include <iostream>
#include "Menu.hpp"
#include "InterfaceApresentacaoAcesso.hpp"
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
        ControladorInterfaceGerente controladorGerente;
    public:
        void exibirMenu() override;

    };
}


#endif //GERENCIADOR_DE_HOTEIS_UNB_CAI_HPP