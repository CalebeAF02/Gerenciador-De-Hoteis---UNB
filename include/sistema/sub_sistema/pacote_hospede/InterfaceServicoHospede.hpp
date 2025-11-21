//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_ISHOSPEDAGEM_HPP
#define Hotelaria_UnB_TP1_ISHOSPEDAGEM_HPP

#include "InterfacePersistenciaHospede.hpp"
#include "HospedeDTO.hpp"
#include "Hospede.hpp"

#include "Menu.hpp"
#include "IO.hpp"

#include <iostream>
#include <optional>

using namespace std;
using namespace VisualizadorDeMenu;

namespace Hotelaria {
    class InterfaceServicoHospede {
    public:
        virtual void setControladoraPersistencia(InterfacePersistenciaHospede *persistencia) = 0;

        virtual bool criar(const Hospede &hospede) = 0;

        virtual bool editar(const Email &email, const Hospede &hospedeAtualizado) = 0;

        virtual bool remover(const int &id) = 0;

        virtual vector<HospedeDTO> listarTodos() = 0;

        virtual optional<HospedeDTO> pesquisar(const int &id) = 0;

        virtual ~InterfaceServicoHospede() = default;
    };
}

#endif //Hotelaria_UnB_TP1_ISHOSPEDAGEM_HPP