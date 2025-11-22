//
// Created by caleb on 14/11/2025.
//

#ifndef Hotelaria_UnB_TP1_CAA_HPP
#define Hotelaria_UnB_TP1_CAA_HPP

#include "InterfaceApresentacaoAutenticavel.hpp"
#include "InterfaceServicoAutenticavel.hpp"
#include "Email.hpp"
#include "Senha.hpp"

#include "Utils.hpp"
#include "Menu.hpp"
#include "Tabela.hpp"
#include "IO.hpp"

#include <string>
#include <iostream>
#include <optional>
#include <vector>

using namespace std;
using namespace Utils;
using namespace VisualizadorDeMenu;
using namespace VisualizadorDeTabela;

namespace Hotelaria {
    class ControladoraApresentacaoAutenticavel : public InterfaceApresentacaoAutenticavel {
    private:
        InterfaceServicoAutenticavel *servico;

        bool estaAutenticado = false;

        string gerente_email;

    public:
        void setControladoraServicoAutenticavel(InterfaceServicoAutenticavel *servico) override;

        void setEmailDoGerente(const string &email) override;

        string getEmailDOGerente() override;

        void setEstaAutenticado(bool estaAutenticado) override;

        bool getEstaAutenticado() override;

        bool autenticar() override;

        InterfaceServicoAutenticavel *getHacke() override;
    };
}

#endif //Hotelaria_UnB_TP1_CAA_HPP