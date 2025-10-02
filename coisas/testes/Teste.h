#ifndef TESTE_INCLUDE
#define TESTE_INCLUDE

#include <iostream>
#include <ostream>
#include <string>
#include "../entidades/Pessoa.h"
#include "../entidades/Gerente.h"
#include "../entidades/Hospede.h"
#include "../entidades/Hotel.h"
#include "../entidades/Quarto.h"
#include "../entidades/Reserva.h"

using namespace std;

class Teste
{
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
    static int apresentacaoErro(string erro);

    static void setTestes(int contTodalTestes);

    static void setTestesOk(int contTodalTestesOk);

    static void setTestesProblema(int contTodalTestesProblema);

    static int getTestes();

    static int getTestesOk();

    static int getTestesProblema();
};
#endif