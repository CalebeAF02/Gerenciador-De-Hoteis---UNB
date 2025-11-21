//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CARESERVA_HPP
#define Hotelaria_UnB_TP1_CARESERVA_HPP

#include "InterfaceApresentacaoReserva.hpp"
#include "InterfaceServicoReserva.hpp"

#include "Utils.hpp"
#include "Menu.hpp"
#include "ExibirMenu.hpp"
#include "Tabela.hpp"
#include "Formato.hpp"
#include "IO.hpp"

#include <string>
#include <iostream>
#include <optional>
#include <vector>

using namespace std;
using namespace Utils;
using namespace VisualizadorDeMenu;
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    class ControladoraApresentacaoReserva : public InterfaceApresentacaoReserva {
    private:
        InterfaceServicoReserva *servico;

    public:
        void setControladoraServicoReserva(InterfaceServicoReserva *) override;

        void exibirMenuCRUD() override;

        void criar() override;

        void listar() override;

        void atualizar() override;

        void remover() override;
    };
}

#endif //Hotelaria_UnB_TP1_CARESERVA_HPP