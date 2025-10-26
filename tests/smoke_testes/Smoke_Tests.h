#ifndef SMOKE_TESTS_INCLUDE
#define SMOKE_TESTS_INCLUDE

#include "../entidades/Gerente.h"
#include "../entidades/Hospede.h"
#include "../entidades/Hotel.h"
#include "../entidades/Quarto.h"
#include "../entidades/Reserva.h"
#include "../../include/utilitarios/Data.h"
#include "interface_tests/InterfaceDeTeste.h"

#include "dominios/Capacidade.h"
#include "dominios/Cartao.h"
#include "dominios/Codigo.h"
#include "dominios/Dinheiro.h"
#include "dominios/Email.h"
#include "dominios/Endereco.h"
#include "dominios/Nome.h"
#include "dominios/Numero.h"
#include "dominios/Ramal.h"
#include "dominios/Senha.h"
#include "dominios/Telefone.h"

#include "../validadores_principais/ValidarInt.h"
#include "../validadores_principais/ValidarString.h"

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