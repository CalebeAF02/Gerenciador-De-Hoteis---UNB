//
// Created by caleb on 20/09/2025.
//

#ifndef PROJETOS_CPP_UNB_7_IML_TESTES_VALIDADORES_H
#define PROJETOS_CPP_UNB_7_IML_TESTES_VALIDADORES_H

#include "../dominios/Gerente.h"
#include "../dominios/Hospede.h"
#include "../dominios/Hotel.h"
#include "../dominios/Quarto.h"
#include "../dominios/Reserva.h"
#include "../Data.h"
#include "Teste.h"

#include "../validadores/ValidarInt.h"
#include "../validadores/ValidarString.h"
#include "../validadores/ValidarNome.h"
#include "../validadores/ValidarEndereco.h"
#include "../validadores/ValidarRamal.h"
#include "../validadores/ValidarDinheiro.h"
#include "../validadores/ValidarCodigo.h"

#include <iostream>
#include <ostream>

using namespace std;

class TesteValidadores {
public:
    static void testarEntradas();
    ;

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
    static void testarValidadorChegada(int esperando_resultado, Reserva *ptr, int dia, int mes, int ano);

    static void testarValidadorPartida(int esperando_resultado, Reserva *ptr, int dia, int mes, int ano);

    static void testarValidadorDinheiro(int esperando_resultado, Reserva *ptr, int dinheiro);

    static void testarValidadorCodigo(int esperando_resultado, Reserva *ptr, string codigo);

    // Data
    static void testarValidadorDia(int esperando_resultado, Data *ptr, int dia);

    static void testarValidadorMes(int esperando_resultado, Data *ptr, int mes);

    static void testarValidadorAno(int esperando_resultado, Data *ptr, int ano);
};

#endif //PROJETOS_CPP_UNB_7_IML_TESTES_VALIDADORES_H