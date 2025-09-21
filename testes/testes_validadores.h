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

#include <iostream>
#include <ostream>


class TesteValidadores {
public:
    static void testarEntradas ();
;

    static void testarValidadorNome(int esperando_resultado, Pessoa* ptr, string nome);
    static void testarValidadorEmail(int esperando_resultado, Pessoa* ptr, string email);

    static void testarValidadorCartao(int esperando_res, Hospede* ptr, string Cartao);
    static void testarValidadorEndereco(int esperando_resultado, Hospede* ptr, string endereco);

    static void testarValidadorRamal(int esperando_res, Gerente* ptr, string Cartao);
    static void testarValidadorSenha(int esperando_resultado, Gerente* ptr, string endereco);

    static void testarValidadorNome(int esperando_resultado, Hotel* ptr, string endereco);
    static void testarValidadorEndereco(int esperando_resultado, Hotel* ptr, string endereco);
    static void testarValidadorTelefone(int esperando_resultado, Hotel* ptr, string endereco);
    static void testarValidadorCodigo(int esperando_resultado, Hotel* ptr, string endereco);

    static void testarValidadorNumero(int esperando_resultado, Quarto* ptr, string endereco);
    static void testarValidadorCapacidade(int esperando_resultado, Quarto* ptr, string endereco);
    static void testarValidadorDinheiro(int esperando_resultado, Quarto* ptr, string endereco);
    static void testarValidadorRamal(int esperando_resultado, Quarto* ptr, string endereco);

    static void testarValidadorCegada(int esperando_resultado, Reserva* ptr, string endereco);
    static void testarValidadorPartida(int esperando_resultado, Reserva* ptr, string endereco);
    static void testarValidadorDinheiro(int esperando_resultado, Reserva* ptr, string endereco);
    static void testarValidadorCodigo(int esperando_resultado, Reserva* ptr, string endereco);


    static void testarValidadorDia(int esperando_resultado, Data* ptr, int dia);
    static void testarValidadorMes(int esperando_resultado, Data* ptr, int mes);
    static void testarValidadorAno(int esperando_resultado, Data* ptr, int ano);
};

#endif //PROJETOS_CPP_UNB_7_IML_TESTES_VALIDADORES_H