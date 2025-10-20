//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSGERENTE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSGERENTE_H

#include "Pessoa.h"
#include "Gerente.h"

#include "../../utilitarios/TextoApresentacao.h"
#include "InterfaceFabricaGerenciavel.h"
#include "FabricaGerenciavel.h"

#include "ServicosHospede.h"

using namespace std;

class ServicosGerente
{
private:
    bool gerenteEstaLogado = false;
    bool executando = true;
    Gerente* logGerente;

public:
    // Construtor dos servicosGerente
    ServicosGerente() = default;

    // Confirmar que é um gerente
    void acessandoGerente();

    // Acessando servicos
    void exibirCentralDeServicos();
    void exibirCentralDeServicosGerentes();

    // Metodos Programados de Login
    void logandoGerente();
    bool fazerLoginGerente(string emailCopia, string senhaCopia);
    bool getGerenteEstaLogado();
};

inline bool ServicosGerente::getGerenteEstaLogado()
{
    return gerenteEstaLogado;
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSGERENTE_H