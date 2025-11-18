//
// Created by caleb on 08/11/2025.
//

#ifndef Hotelaria_UnB_TP1_SISTEMA_HACKER_HPP
#define Hotelaria_UnB_TP1_SISTEMA_HACKER_HPP

#include <iostream>
#include "Versao.hpp"
#include "ControladoraApresentacaoAcessoGerente.hpp"
#include "ControladorInterfaceGerente.hpp"

using namespace std;
namespace Hotelaria {

    class SistemaHacker {
    private:
        ControladorInterfaceGerente controladorGerente;
        ControladoraApresentacaoAcessoGerente controladora_apresentacao_acesso_gerente;

    public:
        void iniciar();
    };
}


#endif