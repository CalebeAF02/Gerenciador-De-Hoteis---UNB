//
// Created by caleb on 20/09/2025.
//

#ifndef PROJETOS_CPP_UNB_7_IML_TESTES_VALIDADORES_H
#define PROJETOS_CPP_UNB_7_IML_TESTES_VALIDADORES_H

#include "../../dominios/d_cabecalho/Gerente.h"
#include "../../dominios/d_cabecalho/Hospede.h"
#include "../../dominios/d_cabecalho/Hotel.h"
#include "../../dominios/d_cabecalho/Quarto.h"
#include "../../dominios/d_cabecalho/Reserva.h"
#include "../../Data.h"
#include "../testes/Teste.h"

#include "../val_principais/ValidarInt.h"
#include "../val_principais/ValidarString.h"
#include "../val_abstratos//ValidarNome.h"
#include "../val_abstratos/ValidarEndereco.h"
#include "../val_abstratos/ValidarRamal.h"
#include "../val_abstratos//ValidarDinheiro.h"
#include "../val_abstratos/ValidarCodigo.h"

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