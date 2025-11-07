#ifndef TESTE_INCLUDE
#define TESTE_INCLUDE

#include <iostream>
#include <string>
#include <vector>
#include "../entidades/Pessoa.hpp"
#include "../entidades/Gerente.hpp"
#include "../entidades/Hospede.hpp"
#include "../entidades/Hotel.hpp"
#include "../entidades/Quarto.hpp"
#include "../entidades/Reserva.hpp"
#include "ConsoleFormatter.hpp"
#include "ConsoleIO.hpp"

using namespace std;

class InterfaceDeTeste {
private:
    static int contTodalTestes;
    static int contTodalTestesOk;
    static int contTodalTestesProblema;

    static vector<string> listaFalhas;

public:
    static const int DEVE_DAR_ERRADO = -1;
    static const int DEVE_DAR_CERTO = 1;

    // Métodos virtuais obrigatórios
    virtual void executar() = 0;

    virtual string nomeDoTeste() const = 0;

    virtual ~InterfaceDeTeste() = default;

    // Métodos utilitários (usados pelo SmokeTest)
    static void checaResultado(int esperando_resultado, int resultado_teste);

    static void apresentacaoTeste(string valor);

    static void apresentacaoTeste(int valor);

    // Contadores e registro de falha
    static void setTestes(int contTodalTestes);

    static void setTestesOk(int contTodalTestesOk);

    static void setTestesProblema(int contTodalTestesProblema);

    static void registrarFalha(const string &dominio, const string &entrada, const string &erro);

    static void mostrarSumarioGeral();

    static int getTestes();

    static int getTestesOk();

    static int getTestesProblema();
};

#endif // TESTE_INCLUDE