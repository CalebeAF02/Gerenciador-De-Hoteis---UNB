//
// Created by caleb on 20/09/2025.
//

#include "testes_validadores.h"

#include <iostream>
#include <ostream>

#include "../dominios/Gerente.h"

void TesteValidadores::testarEntradas() {
    cout << "              ----------------              " << endl;
    cout << "              | Testes Nomes |              " << endl;
    cout << "              ----------------              " << endl << endl;

    Gerente g1;

    testarValidadorNome(DEVE_DAR_ERRADO, &g1, "");
    testarValidadorNome(DEVE_DAR_ERRADO, &g1, "Cb");
    testarValidadorNome(DEVE_DAR_ERRADO, &g1, "Calebe Alves Freitas Madeira Alves");
    testarValidadorNome(DEVE_DAR_ERRADO, &g1, "Calebe  Alves");
    testarValidadorNome(DEVE_DAR_ERRADO, &g1, "calebe alves");
    testarValidadorNome(DEVE_DAR_ERRADO, &g1, "Calebe alves");
    testarValidadorNome(DEVE_DAR_ERRADO, &g1, "Calebe@alves");
    testarValidadorNome(DEVE_DAR_ERRADO, &g1, "Calebe Alves ");

    testarValidadorNome(DEVE_DAR_CERTO, &g1, "Luan Freitas");
    testarValidadorNome(DEVE_DAR_CERTO, &g1, "Kaio Rodrigues");

    cout << "              -----------------             " << endl;
    cout << "              | Testes Emails |             " << endl;
    cout << "              -----------------             " << endl << endl;

    testarValidadorEmail(&g1, "");
    testarValidadorEmail(&g1, "Cb@gmail.com");
    testarValidadorEmail(&g1, "cb@gmail.com");
    testarValidadorEmail(&g1, "calebeclvescreitascadeiraclves@gmail.com");
    testarValidadorEmail(&g1, "calebe clves@gmail.com");
    testarValidadorEmail(&g1, "calebe  clves@gmail.com");
    testarValidadorEmail(&g1, "calebeclves@citex.eb.mil.com");
    testarValidadorEmail(&g1, "calebeclves@centrointegrado.eb.mil.com");
    testarValidadorEmail(&g1, ".cb@gmail.com");
    testarValidadorEmail(&g1, ".-cb@gmail.com");
    testarValidadorEmail(&g1, ".c--b@gmail.com");
    testarValidadorEmail(&g1, ".c..b@gmail.com");

    testarValidadorEmail(&g1, "luanfreitas@gmai.com");
    testarValidadorEmail(&g1, "kaiorodrigues@gmail.com");



}

void TesteValidadores::testarValidadorNome(int esperando_resultado, Pessoa *ptr,string nome) {
    cout << "Teste Para Validar " << endl << "Entrada: " << nome << endl;
    int temp =0;
    try {
        ptr->setNome(nome);
        cout << "----------------------OK----------------------" << endl;
        cout << "Entrada Valida! "<< endl;
        cout << "----------------------------------------------" << endl;

        temp = DEVE_DAR_CERTO;

    } catch (invalid_argument &erro ) {
        cout << "---------------------ERRO---------------------" << endl;
        cout << erro.what() << endl;
        cout << "----------------------------------------------" << endl;

        temp = DEVE_DAR_ERRADO;
    }

    if (esperando_resultado == DEVE_DAR_CERTO) {
        cout << "Esperando: Validacao CORRETA" << endl;
    }else if (esperando_resultado == DEVE_DAR_ERRADO){
        cout << "Esperando: Validacao ERRADA" << endl;
    }

    if (esperando_resultado == temp) {
        cout << "Resultado: OK" << endl<<endl;
    }else{
        cout << "Resultado: PROBLEMA NA VALIDACAO DO PROGRAMADOR" << endl<<endl;
    }
}

void TesteValidadores::testarValidadorEmail(Pessoa *ptr,string email) {
    cout << "Teste Para Validar " << endl << "Entrada: " << email << endl;

    try {
        ptr->setEmail(email);
        cout << "----------------------OK----------------------" << endl;
        cout << "Entrada Valida! "<< endl;
        cout << "----------------------------------------------" << endl<<endl;

    } catch (invalid_argument &erro ) {
        cout << "---------------------ERRO---------------------" << endl;
        cout << erro.what() << endl;
        cout << "----------------------------------------------" << endl<<endl;

    }
}
