//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOSPEDE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOSPEDE_H


#include "Hospede.h"

#include "../utilitarios/TextoApresentacao.h"

#include "InterfaceFabricaGerenciavel.h"
#include "FabricaGerenciavel.h"

#include <vector>
#include <limits>
#include <fstream>

using namespace std;

class ServicosHospede
{
private:
    bool executando = true;

public:
    // Construtor dos ServicosHospede
    ServicosHospede() = default;

    // Solicitacao de Hospedagem para Gerente
    void opcoesDeHospedagem();
    void solicitandoHospedagem();

    void statusDaSolicitandoHospedagem() const;

    // Confirmar que e um Hospede
    void acessandoHospede();

    // Acessando servicos
    void exibirCentralDeServicosHospedes();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOSPEDE_H