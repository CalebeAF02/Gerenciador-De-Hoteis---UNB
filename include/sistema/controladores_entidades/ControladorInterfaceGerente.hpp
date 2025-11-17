//
// Created by caleb on 01/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CONTROLADORINTERFACEGERENTE_H
#define Hotelaria_UnB_TP1_CONTROLADORINTERFACEGERENTE_H

#include "ControladoraApresentacaoAutenticavel.hpp"
#include "ControladorInterfaceHospede.hpp"
#include "ControladorInterfaceHotel.hpp"
#include "ControladorInterfaceQuarto.hpp"
#include "ControladorInterfaceReserva.hpp"
#include "PersistenciaGerente.hpp"
#include "ControladoraServicoAutenticavel.hpp"
#include "../../../libs/io/IO.hpp"
#include "Tabela.hpp"

#include "InterfaceApresentacaoExibirMenu.hpp"
#include "iostream"

using namespace std;
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    class ControladorInterfaceGerente : public ControladoraApresentacaoAutenticavel,
                                        public InterfaceApresentacaoCRUD {
    private:
        PersistenciaGerente persistencia;
        bool executando = true;
        bool estaAutenticado = false;

    public:
        ControladorInterfaceGerente();

        // Menu CRUD
        void exibirMenuCRUD();

        void criar() override;

        void ler() override;

        void atualizar() override;

        void remover() override;
    };
}
#endif //Hotelaria_UnB_TP1_CONTROLADORINTERFACEGERENTE_H