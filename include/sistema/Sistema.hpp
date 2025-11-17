//
// Created by caleb on 28/09/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H
#define GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H

#include "ControladorInterfaceGerente.hpp"
#include "ControladorInterfaceHospede.hpp"
#include "ControladorInterfaceHotel.hpp"
#include "ControladorInterfaceQuarto.hpp"
#include "ControladorInterfaceReserva.hpp"

#include "../../libs/menu/Menu.hpp"

#include "../../libs/formato/Formato.hpp"
#include <iostream>
#include <string>
#include "ControladoraApresentacaoAcessoGerente.hpp"
#include "ControladoraApresentacaoAcessoHospede.hpp"
#include "sqlite3.h"

using namespace std;

namespace Hotelaria {
    class Sistema {
    private:
        bool executando = true;
        ControladoraApresentacaoAcessoGerente contoladoraApresentacaoAcessoGerente;
        ControladoraApresentacaoAcessoHospede contoladoraApresentacaoAcessoHospede;

        void exibirMenu();

        bool getExecutandoSistema();

        void sair();
    public:
        void iniciar();
    };
}
#endif //GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H