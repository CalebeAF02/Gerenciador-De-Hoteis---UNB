//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOSPEDE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOSPEDE_H


#include "Hospede.hpp"

#include "../../../../../libs/formato/Formato.hpp"
#include "../../../../../libs/menu/ExibirMenu.hpp"
#include "../modulo_persistencia_hospede/PersistenciaHospede.hpp"
#include "../../pacote_fabrica/InterfaceFabricaGerenciavel.hpp"
#include "SolicitacaoHospedagem.hpp"
#include "../modulo_persistencia_hospede/PersistenciaSolicitacaoHospedagem.hpp"
#include "../../pacote_fabrica/modulo_apresentacao_fabrica/FabricaGerenciavel.hpp"
#include "../../../../../libs/io/IO.hpp"

#include <vector>
#include <limits>
#include <fstream>

using namespace std;
namespace Hotelaria {
    class ControladorInterfaceHospede : public MenuCRUD {
    private:
        PersistenciaHospede persistencia;
        bool executando = true;

    public:
        // Construtor dos ServicosHospede
        ControladorInterfaceHospede() = default;

        void avaliarSolicitacoes();

        // Menu CRUD
        void exibirMenuCRUD();

        void criar() override;

        void ler() override;

        void atualizar() override;

        void remover() override;
    };
}
#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOSPEDE_H