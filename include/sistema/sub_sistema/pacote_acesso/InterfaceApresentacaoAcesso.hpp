//
// Created by caleb on 15/11/2025.
//

#ifndef HOTELARIA_UNB_TP1_INTERFACEAPRESENTACAOACESSO_HPP
#define HOTELARIA_UNB_TP1_INTERFACEAPRESENTACAOACESSO_HPP

namespace Hotelaria {
    class InterfaceApresentacaoAcesso {
    public:
        virtual void exibirMenu() = 0;

        virtual void exibirMenuGerenciador() = 0;

        virtual void opcoesDeHospedagem() = 0;

        virtual void solicitandoHospedagem() = 0;

        virtual void statusDaSolicitandoHospedagem() const = 0;

        virtual ~InterfaceApresentacaoAcesso() = default;
    };
}
#endif //HOTELARIA_UNB_TP1_INTERFACEAPRESENTACAOACESSO_HPP