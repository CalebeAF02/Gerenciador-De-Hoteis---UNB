//
// Created by caleb on 15/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAAPRESENTACAOACESSOHOESPEDE_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAAPRESENTACAOACESSOHOESPEDE_HPP

#include "ControladorInterfaceHospede.hpp"
#include "InterfaceApresentacaoAcesso.hpp"
namespace Hotelaria {
    class ControladoraApresentacaoAcessoHospede : public InterfaceApresentacaoAcesso {
    private:
        //ControladorInterfaceHospede controladorHospede;
    public:
        void exibirMenu() override;

        // Solicitacao de Hospedagem para Gerente
        void opcoesDeHospedagem();

        void solicitandoHospedagem();

        void statusDaSolicitandoHospedagem() const;
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_CONTROLADORAAPRESENTACAOACESSOHOESPEDE_HPP