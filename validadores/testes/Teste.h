//
// Created by caleb on 20/09/2025.
//

#ifndef PROJETOS_CPP_UNB_7_IML_TESTE_H
#define PROJETOS_CPP_UNB_7_IML_TESTE_H

#include <iostream>
#include <ostream>
#include <string>
#include "../../dominios/d_cabecalho/Pessoa.h"
#include "../../dominios/d_cabecalho/Gerente.h"
#include "../../dominios/d_cabecalho/Hospede.h"
#include "../../dominios/d_cabecalho/Hotel.h"
#include "../../dominios/d_cabecalho/Quarto.h"
#include "../../dominios/d_cabecalho/Reserva.h"

#include "../testes_validadores/testes_validadores.h"

using namespace std;

class Teste {
private:
    static int contTodalTestes;
    static int contTodalTestesOk;
    static int contTodalTestesProblema;

public:
    static const int DEVE_DAR_ERRADO = -1;
    static const int DEVE_DAR_CERTO = 1;

    static void checaResultado(int esperando_resultado, int resultado_teste);

    static void apresentacaoTeste(string valor);

    static void apresentacaoTeste(int valor);

    static void apresentacaoTesteData(int dia, int mes, int ano);

    static int apresentacaoSucesso();

    static int apresentacaoErro(invalid_argument erro);

    static void setTestes(int contTodalTestes);

    static void setTestesOk(int contTodalTestesOk);

    static void setTestesProblema(int contTodalTestesProblema);

    static int getTestes();

    static int getTestesOk();

    static int getTestesProblema();
};

#endif //PROJETOS_CPP_UNB_7_IML_TESTE_H