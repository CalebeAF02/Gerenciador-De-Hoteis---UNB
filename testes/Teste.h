//
// Created by caleb on 20/09/2025.
//

#ifndef PROJETOS_CPP_UNB_7_IML_TESTE_H
#define PROJETOS_CPP_UNB_7_IML_TESTE_H

#include <iostream>
#include <ostream>
#include <string>
#include "../dominios/Pessoa.h"
#include "../dominios/Gerente.h"
#include "../dominios/Hospede.h"
#include "../dominios/Hotel.h"
#include "../dominios/Quarto.h"
#include "../dominios/Reserva.h"

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