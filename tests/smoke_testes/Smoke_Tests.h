#ifndef SMOKE_TESTS_INCLUDE
#define SMOKE_TESTS_INCLUDE

#include "Gerente.h"
#include "Hospede.h"
#include "Hotel.h"
#include "Quarto.h"
#include "Reserva.h"
#include "Data.h"
#include "InterfaceDeTeste.h"

#include "Capacidade.h"
#include "Cartao.h"
#include "Codigo.h"
#include "Dinheiro.h"
#include "Email.h"
#include "Endereco.h"
#include "Nome.h"
#include "Numero.h"
#include "Ramal.h"
#include "Senha.h"
#include "Telefone.h"

#include "sistema/validadores_principais/ValidarInt.h"
#include "sistema/validadores_principais/ValidarString.h"

#include <iostream>
#include <ostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class SmokeTest
{
public:
    static void testarEntradas();

    // Validadores Principais
    static void testarValidadorString(int esperando_resultado, string s1, string s2);


    // Pessoa: Gerente ou Hospede
    static void testarValidadorNome(int esperando_resultado, Pessoa* ptr, string nome);

    static void testarValidadorEmail(int esperando_resultado, Pessoa* ptr, string email);

    //Gerente
    static void testarValidadorNome(int esperando_resultado, Gerente* ptr, string nome);

    static void testarValidadorEmail(int esperando_resultado, Gerente* ptr, string email);

    static void testarValidadorRamal(int esperando_res, Gerente* ptr, string ramal);

    static void testarValidadorSenha(int esperando_resultado, Gerente* ptr, string senha);

    //Hospede
    static void testarValidadorNome(int esperando_resultado, Hospede* ptr, string nome);

    static void testarValidadorEmail(int esperando_resultado, Hospede* ptr, string email);

    static void testarValidadorCartao(int esperando_res, Hospede* ptr, string Cartao);

    static void testarValidadorEndereco(int esperando_resultado, Hospede* ptr, string endereco);

    //Hotel
    static void testarValidadorNome(int esperando_resultado, Hotel* ptr, string nome);

    static void testarValidadorEndereco(int esperando_resultado, Hotel* ptr, string endereco);

    static void testarValidadorTelefone(int esperando_resultado, Hotel* ptr, string telefone);

    static void testarValidadorCodigo(int esperando_resultado, Hotel* ptr, string codigo);

    //Quarto
    static void testarValidadorNumero(int esperando_resultado, Quarto* ptr, string numero);

    static void testarValidadorCapacidade(int esperando_resultado, Quarto* ptr, int capacidade);

    static void testarValidadorDinheiro(int esperando_resultado, Quarto* ptr, int dinheiro);

    static void testarValidadorRamal(int esperando_resultado, Quarto* ptr, string ramal);

    //Reserva
    static void testarValidadorChegada(int esperando_resultado, Reserva* ptr, string chegada);

    static void testarValidadorPartida(int esperando_resultado, Reserva* ptr, string partida);

    static void testarValidadorDinheiro(int esperando_resultado, Reserva* ptr, int dinheiro);

    static void testarValidadorCodigo(int esperando_resultado, Reserva* ptr, string codigo);

    // Data
    static void testarValidadorDia(int esperando_resultado, Data* ptr, int dia);

    static void testarValidadorMes(int esperando_resultado, Data* ptr, int mes);

    static void testarValidadorAno(int esperando_resultado, Data* ptr, int ano);
};
#endif