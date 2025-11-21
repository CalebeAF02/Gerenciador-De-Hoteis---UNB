//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CSHOSPEDAGEM_HPP
#define Hotelaria_UnB_TP1_CSHOSPEDAGEM_HPP

#include "InterfaceServicoHospede.hpp"
#include "InterfacePersistenciaHospede.hpp"
#include "ControladoraPersistenciaHospede.hpp"

#include "FabricaGerenciavel.hpp"

#include "Utils.hpp"
#include "Tabela.hpp"
#include "IO.hpp"

#include <iostream>

using namespace std;
using namespace Utils;
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    class ControladoraServicoHospede : public InterfaceServicoHospede {
    private:
        InterfacePersistenciaHospede *persistencia = nullptr;

    public:
        void setControladoraPersistencia(InterfacePersistenciaHospede *persistencia) override;

        bool criar(const Hospede &hospede) override;

        bool editar(const Email &email, const Hospede &hospedeAtualizado) override;

        bool remover(const int &id) override;

        vector<HospedeDTO> listarTodos() override;

        optional<HospedeDTO> pesquisar(const int &id) override;
    };
}

#endif //Hotelaria_UnB_TP1_CSHOSPEDAGEM_HPP