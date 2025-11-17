//
// Created by caleb on 15/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CONTROLADORAAPRESENTACAOACESSOHOESPEDE_HPP
#define Hotelaria_UnB_TP1_CONTROLADORAAPRESENTACAOACESSOHOESPEDE_HPP

#include "ControladorInterfaceHospede.hpp"
#include "../InterfaceApresentacaoAcesso.hpp"

namespace Hotelaria {
    class ControladoraApresentacaoAcessoHospede : public InterfaceApresentacaoAcesso {
    private:
        InterfaceServicoAcesso *controladora_servico_acesso_hospede;

    public:
        void exibirMenu() override;

        void setControladoraServicoAcesso(InterfaceServicoAcesso *) override;

        // Solicitacao de Hospedagem para Gerente
        void opcoesDeHospedagem();

        void solicitandoHospedagem();

        void statusDaSolicitandoHospedagem() const;
    };
}

#endif //Hotelaria_UnB_TP1_CONTROLADORAAPRESENTACAOACESSOHOESPEDE_HPP