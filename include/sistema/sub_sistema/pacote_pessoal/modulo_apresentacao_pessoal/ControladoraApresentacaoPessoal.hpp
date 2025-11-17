//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CAP_HPP
#define Hotelaria_UnB_TP1_CAP_HPP

#include "InterfaceApresentacaoPessoal.hpp"
#include "IO.hpp"
#include <iostream>

using namespace std;

namespace Hotelaria {
    class ControladoraApresentacaoPessoal : public InterfaceApresentacaoPessoal {
    private:
        // Códigos dos serviços.

        const static int INCLUIR = 1;
        const static int REMOVER = 2;
        const static int PESQUISAR = 3;
        const static int EDITAR = 4;
        const static int RETORNAR = 5;

        InterfaceServicoPessoal *controladora_servico_pessoal; // Referência para servidor.

    public:
        void executar(const Email);

        void setControladoraServicoPessoal(InterfaceServicoPessoal *) override;
    };
}

#endif //Hotelaria_UnB_TP1_CAP_HPP