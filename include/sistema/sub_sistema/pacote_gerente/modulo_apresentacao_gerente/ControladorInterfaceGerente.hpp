//
// Created by caleb on 01/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CONTROLADORINTERFACEGERENTE_H
#define Hotelaria_UnB_TP1_CONTROLADORINTERFACEGERENTE_H

#include "ControladoraApresentacaoAutenticavel.hpp"
#include "../../pacote_hospede/modulo_apresentacao_hospede/ControladorInterfaceHospede.hpp"
#include "../../pacote_hotel/modulo_apresentacao_hotel/ControladorInterfaceHotel.hpp"
#include "../../pacote_quarto/modulo_apresentacao_quarto/ControladorInterfaceQuarto.hpp"
#include "../../pacote_reserva/modulo_apresentacao_reserva/ControladorInterfaceReserva.hpp"
#include "../modulo_persistencia_gerente/PersistenciaGerente.hpp"
#include "ControladoraServicoAutenticavel.hpp"
#include "../../../../../libs/io/IO.hpp"
#include "Tabela.hpp"

#include "../../../../../libs/menu/ExibirMenu.hpp"
#include "iostream"

using namespace std;
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    class ControladorInterfaceGerente : public ControladoraApresentacaoAutenticavel,
                                        public MenuCRUD {
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