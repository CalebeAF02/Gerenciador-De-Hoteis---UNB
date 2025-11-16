//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOSPEDE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOSPEDE_H


#include "Hospede.hpp"

#include "../../../libs/formato/Formato.hpp"
#include "InterfaceApresentacaoExibirMenu.hpp"
#include "PersistenciaHospede.hpp"
#include "InterfaceFabricaGerenciavel.hpp"
#include "SolicitacaoHospedagem.hpp"
#include "PersistenciaSolicitacaoHospedagem.hpp"
#include "FabricaGerenciavel.hpp"
#include "../../../libs/io/IO.hpp"

#include <vector>
#include <limits>
#include <fstream>

using namespace std;
namespace Hotelaria {
    class ControladorInterfaceHospede : public InterfaceApresentacaoCRUD {
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