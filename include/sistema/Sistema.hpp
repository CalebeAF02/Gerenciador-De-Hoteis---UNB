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


// Controladoras de apresentação
#include "ControladoraApresentacaoAcessoGerente.hpp"
#include "ControladoraApresentacaoAcessoHospede.hpp"
#include "ControladoraApresentacaoAutenticavel.hpp"
#include "ControladoraApresentacaoGerente.hpp"
#include "ControladoraApresentacaoHospede.hpp"
#include "ControladoraApresentacaoHotel.hpp"
#include "ControladoraApresentacaoQuarto.hpp"
#include "ControladoraApresentacaoReserva.hpp"

// Controladoras de servico
#include "ControladoraServicoAutenticavel.hpp"
#include "ControladoraServicoGerente.hpp"
#include "ControladoraServicoHospede.hpp"
#include "ControladoraServicoHotel.hpp"
#include "ControladoraServicoQuarto.hpp"
#include "ControladoraServicoReserva.hpp"

// Controladoras de Persistencia
#include "ControladoraPersistenciaAutenticavel.hpp"
#include "ControladoraPersistenciaGerente.hpp"
#include "ControladoraPersistenciaHospede.hpp"
#include "ControladoraPersistenciaHotel.hpp"
#include "ControladoraPersistenciaQuarto.hpp"
#include "ControladoraPersistenciaReserva.hpp"
#include "ControladoraPersistenciaSolicitacaoHospedagem.hpp"


using namespace std;

namespace Hotelaria {
    class ControladoraApresentacaoAcessoGerente;
    class ControladoraApresentacaoAcessoHospede;

    class Sistema {
    private:
        ControladoraApresentacaoAcessoGerente *apresentacao_acesso_gerente;
        ControladoraApresentacaoAcessoHospede *apresentacao_acesso_hospede;
        bool executando = true;
        bool gerente_autenticado = false;
        int gerente_id;

    public:
        Sistema();

        void exibirMenu();

        void iniciar();

        void setGerenteID(int valor);

        void setGerenteAutenticado(bool valor);

        bool getGerenteID();

        bool getGerenteAutenticado();
    };
}
#endif //GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H