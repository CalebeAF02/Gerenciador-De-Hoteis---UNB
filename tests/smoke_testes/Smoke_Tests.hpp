#ifndef SMOKE_TESTS_INCLUDE
#define SMOKE_TESTS_INCLUDE

#include "Gerente.hpp"
#include "Hospede.hpp"
#include "Hotel.hpp"
#include "Quarto.hpp"
#include "Reserva.hpp"
#include "Data.hpp"
#include "InterfaceDeTeste.hpp"

#include "Capacidade.hpp"
#include "Cartao.hpp"
#include "Codigo.hpp"
#include "Dinheiro.hpp"
#include "Email.hpp"
#include "Endereco.hpp"
#include "Nome.hpp"
#include "Numero.hpp"
#include "Ramal.hpp"
#include "Senha.hpp"
#include "Telefone.hpp"

#include "sistema/validadores_principais/ValidarInt.hpp"
#include "sistema/validadores_principais/ValidarString.hpp"

#include <iostream>
#include <ostream>
#include <vector>
#include <fstream>
#include <string>
#include  "ConsoleIO.hpp"

using namespace std;

class SmokeTest {
public:
    //static void testarEntradas();
    static void testarEntradas();

    // Validadores Principais
    static void testarValidadorString(int esperando_resultado, string s1, string s2);


    // Pessoa: Gerente ou Hospede
    static void testarValidadorNome(int esperando_resultado, Pessoa *ptr, string nome);

    static void testarValidadorEmail(int esperando_resultado, Pessoa *ptr, string email);

    //Gerente
    static void testarValidadorNome(int esperando_resultado, Gerente *ptr, string nome);

    static void testarValidadorEmail(int esperando_resultado, Gerente *ptr, string email);

    static void testarValidadorRamal(int esperando_res, Gerente *ptr, string ramal);

    static void testarValidadorSenha(int esperando_resultado, Gerente *ptr, string senha);

    //Hospede
    static void testarValidadorNome(int esperando_resultado, Hospede *ptr, string nome);

    static void testarValidadorEmail(int esperando_resultado, Hospede *ptr, string email);

    static void testarValidadorCartao(int esperando_res, Hospede *ptr, string Cartao);

    static void testarValidadorEndereco(int esperando_resultado, Hospede *ptr, string endereco);

    //Hotel
    static void testarValidadorNome(int esperando_resultado, Hotel *ptr, string nome);

    static void testarValidadorEndereco(int esperando_resultado, Hotel *ptr, string endereco);

    static void testarValidadorTelefone(int esperando_resultado, Hotel *ptr, string telefone);

    static void testarValidadorCodigo(int esperando_resultado, Hotel *ptr, string codigo);

    //Quarto
    static void testarValidadorNumero(int esperando_resultado, Quarto *ptr, string numero);

    static void testarValidadorCapacidade(int esperando_resultado, Quarto *ptr, int capacidade);

    static void testarValidadorDinheiro(int esperando_resultado, Quarto *ptr, int dinheiro);

    static void testarValidadorRamal(int esperando_resultado, Quarto *ptr, string ramal);

    //Reserva
    static void testarValidadorChegada(int esperando_resultado, Reserva *ptr, string chegada);

    static void testarValidadorPartida(int esperando_resultado, Reserva *ptr, string partida);

    static void testarValidadorDinheiro(int esperando_resultado, Reserva *ptr, int dinheiro);

    static void testarValidadorCodigo(int esperando_resultado, Reserva *ptr, string codigo);

    // Data
    static void testarValidadorDia(int esperando_resultado, Data *ptr, int dia);

    static void testarValidadorMes(int esperando_resultado, Data *ptr, int mes);

    static void testarValidadorAno(int esperando_resultado, Data *ptr, int ano);
};
#endif