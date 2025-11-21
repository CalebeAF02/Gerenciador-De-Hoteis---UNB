//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CSQUARTO_HPP
#define Hotelaria_UnB_TP1_CSQUARTO_HPP

#include "InterfaceServicoQuarto.hpp"
#include "InterfacePersistenciaGerente.hpp"
#include "ControladoraPersistenciaGerente.hpp"

#include "Utils.hpp"
#include "Tabela.hpp"
#include "IO.hpp"

#include <iostream>

using namespace std;
using namespace Utils;
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    class ControladoraServicoQuarto : public InterfaceServicoQuarto {
    private:
        InterfaceServicoQuarto *servico;

    public:
        void exibirMenu();

        void exibirMenuCRUD();

        bool criar(const Quarto &quarto) override;

        bool remover(int id) override;

        bool editar(const int &id, const Quarto &quarto) override;

        vector<QuartoDTO> listarTodos() override;

        optional<QuartoDTO> pesquisar(int id) override;
    };
}

#endif //Hotelaria_UnB_TP1_CSQUARTO_HPP