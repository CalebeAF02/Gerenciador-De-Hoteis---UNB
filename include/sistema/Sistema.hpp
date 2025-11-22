//
// Created by caleb on 28/09/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H
#define GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H

#include <iostream>
#include <string>
#include "sqlite3.h"
#include "Menu.hpp"
#include "Formato.hpp"
#include "ControladoraApresentacaoAcessoGerente.hpp"
#include "ControladoraApresentacaoAcessoHospede.hpp"

using namespace std;

namespace Hotelaria {
    class Sistema {
    private:
        bool executando = true;
        ControladoraApresentacaoAcessoGerente *apresentacao_acesso_gerente;
        ControladoraApresentacaoAcessoHospede *apresentacao_acesso_hospede;

    public:
        Sistema(ControladoraApresentacaoAcessoGerente *apresentacao_acesso_gerente,
                ControladoraApresentacaoAcessoHospede *apresentacao_acesso_hospede);

        void exibirMenu();

        void iniciar();
    };
}
#endif //GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H