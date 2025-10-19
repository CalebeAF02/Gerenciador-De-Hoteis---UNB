//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOSPEDE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOSPEDE_H


#include "Hospede.h"

#include "../../utilitarios/TextoApresentacao.h"

#include "InterfaceFabricaGerenciavel.h"
#include "FabricaGerenciavel.h"

#include <vector>
#include <limits>
#include <fstream>

using namespace std;

class ServicosHospede
{
private:
    bool hospedeEstaLogado = false;
    bool executando = true;
    Hospede logHospede;

public:
    // Construtor dos ServicosHospede
    ServicosHospede() = default;

    // Solicitação de Hospedagem para Gerente
    void opcoesDeHospedagem();
    void solicitandoHospedagem();
    void statusDaSolicitandoHospedagem();

    // Confirmar que é um Hospede
    void acessandoHospede();

    // Acessando servicos
    void exibirCentralDeServicosHospedes();

    // Metodos Programados de Login
    void logandoHospede();
    bool fazerLoginHospede(string emailCopia);
    bool getHospedeEstaLogado();
};

inline bool ServicosHospede::getHospedeEstaLogado()
{
    return hospedeEstaLogado;
};


#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOSPEDE_H