//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CAP_HPP
#define Hotelaria_UnB_TP1_CAP_HPP

#include "InterfaceApresentacaoGerente.hpp"
#include "InterfaceServicoGerente.hpp"
#include "Sistema.hpp"

#include "FabricaGerenciavel.hpp"
#include "Utils.hpp"
#include "Menu.hpp"
#include "Tabela.hpp"
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
    class ControladoraApresentacaoGerente : public InterfaceApresentacaoGerente {
    private:
        InterfaceServicoGerente *servico;

        bool executando = true;
        bool estaAutenticado = false;

    public:
        void setControladoraServicoGerente(InterfaceServicoGerente *servico) override;

        void exibirMenuCRUD() override;

        bool criar() override;

        void listar() override;

        void atualizar() override;

        void remover() override;

        void avaliarSolicitacoes() override;
    };
}

#endif //Hotelaria_UnB_TP1_CAP_HPP