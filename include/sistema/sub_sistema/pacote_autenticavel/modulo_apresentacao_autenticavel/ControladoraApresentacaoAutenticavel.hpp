//
// Created by caleb on 14/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_CAA_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_CAA_HPP

#include "../InterfaceServicoAutenticavel.hpp"
#include "../InterfaceApresentacaoAutenticavel.hpp"

#include "Email.hpp"
#include "Senha.hpp"
#include "../../../../../libs/io/IO.hpp"
#include <iostream>
using namespace std;

namespace Hotelaria {
    class ControladoraApresentacaoAutenticavel : public InterfaceApresentacaoAutenticavel {
    private:
        InterfaceServicoAutenticavel *controladora_servico_autenticavel; // Referência para servidor.
        bool estaAutenticado = false;
    public:
        void sair() override;

        bool autenticar(Email*) override;

        void setControladoraServicoAutenticavel(InterfaceServicoAutenticavel*) override;

        void setEstaAutenticado(bool estaAutenticado) override;

        bool getEstaAutenticado() override;

        InterfaceServicoAutenticavel* getHacke();
    };

    void inline ControladoraApresentacaoAutenticavel::setControladoraServicoAutenticavel(InterfaceServicoAutenticavel *controladora_servico_autenticavel) {
        this->controladora_servico_autenticavel = controladora_servico_autenticavel;
    }
    inline void ControladoraApresentacaoAutenticavel::setEstaAutenticado(bool estaAutenticado) {
        this->estaAutenticado = estaAutenticado;
    }
    inline bool ControladoraApresentacaoAutenticavel::getEstaAutenticado() {
        return estaAutenticado;
    }
    inline void ControladoraApresentacaoAutenticavel::sair() {
        this->estaAutenticado = false;
    }

    inline InterfaceServicoAutenticavel *ControladoraApresentacaoAutenticavel::getHacke() {
        return this->controladora_servico_autenticavel;
    }
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_CAA_HPP