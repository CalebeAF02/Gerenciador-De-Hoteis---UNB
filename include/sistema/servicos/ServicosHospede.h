//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOSPEDE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOSPEDE_H


#include "Hospede.h"

#include "TextoApresentacao.h"

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

    // Metodos CRUD -> CRIAR, LER, EDITAR, DELETAR  (ARMAZENAR DADOS Hospede)
    // Criar um Hospede
    void criarHospede();
    // Ler os Gerentes Hospede
    vector<Hospede> lerHospede();
    // Armazenar um Hospede
    void armazenarHospedes(vector<Hospede> hospedes);
    // Deletar um Hospede
    //deletarGerente

    // Confirmar que é um gerente
    void acessandoHospede();

    // Acessando servicos
    void exibirCentralDeServicosHospede();

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