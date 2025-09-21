//
// Created by caleb on 20/09/2025.
//

#include "testes_validadores.h"

#include "../dominios/Hospede.h"

void TesteValidadores::testarEntradas() {
    cout << "              ----------------              " << endl;
    cout << "              | Testes Nomes |              " << endl;
    cout << "              ----------------              " << endl << endl;

    Gerente g1;

    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &g1, "");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &g1, "Cb");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &g1, "Calebe Alves Freitas Madeira Alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &g1, "Calebe  Alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &g1, "calebe alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &g1, "Calebe alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &g1, "Calebe@alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &g1, "Calebe Alves ");

    testarValidadorNome(Teste::DEVE_DAR_CERTO, &g1, "Luan Freitas");
    testarValidadorNome(Teste::DEVE_DAR_CERTO, &g1, "Kaio Rodrigues");


    cout << "              -----------------             " << endl;
    cout << "              | Testes Emails |             " << endl;
    cout << "              -----------------             " << endl << endl;

    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &g1, "");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &g1, "Cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &g1,"1234567890123456789012345678901234567890123456789012345678901234567890@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &g1, "calebe clves@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &g1, "calebe  clves@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &g1,"calebeclves@1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.eb.mil.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &g1, ".cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &g1, ".-cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &g1, "c--b@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &g1, "c..b@gmail.com");

    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &g1, "calebeclves@citex.eb.mil.com");
    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &g1, "cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &g1, "luanfreitas@gmai.com");
    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &g1, "kaiorodrigues@gmail.com");


    cout << "              --------------------          " << endl;
    cout << "              | Testes Enderecos |          " << endl;
    cout << "              --------------------          " << endl << endl;

    Hotel h1;

    testarValidadorEndereco(Teste::DEVE_DAR_CERTO, &h1, "");// Vai dar errado
    testarValidadorEndereco(Teste::DEVE_DAR_CERTO, &h1, "Quadra 52, Casa 02, Comercial Del Lago");


    cout << "                ----------------          " << endl;
    cout << "                | Testes Datas |          " << endl;
    cout << "                ----------------          " << endl << endl;

    Data d1;

    testarValidadorDia(Teste::DEVE_DAR_ERRADO, &d1, 40);
    testarValidadorMes(Teste::DEVE_DAR_ERRADO, &d1, 22);
    testarValidadorAno(Teste::DEVE_DAR_ERRADO, &d1, 5000);

    testarValidadorDia(Teste::DEVE_DAR_CERTO, &d1, 23);
    testarValidadorMes(Teste::DEVE_DAR_CERTO, &d1, 3);
    testarValidadorAno(Teste::DEVE_DAR_CERTO, &d1, 2002);

    cout << "                ----------------          " << endl;
    cout << "                | Testes Cartao |          " << endl;
    cout << "                ----------------          " << endl << endl;

    Hospede hospede1;

    //testarValidadorCartao(Teste::DEVE_DAR_ERRADO, &hospede1, "40");

















    cout << "Total de Testes: " << Teste::getTestes() << endl;
    cout << "Total de Testes Ok: " << Teste::getTestesOk() << endl;
    cout << "Total de Testes Problema: " << Teste::getTestesProblema() << endl;

}

//-----------------------------------------------------------------------------------------------------------
void TesteValidadores::testarValidadorNome(int esperando_resultado, Pessoa *ptr, string nome) {
    Teste::apresentacaoTeste(nome);
    int resultado_teste = 0;
    try {
        ptr->setNome(nome);
        resultado_teste = Teste::apresentacaoSucesso();

    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

//-----------------------------------------------------------------------------------------------------------
void TesteValidadores::testarValidadorEmail(int esperando_resultado, Pessoa *ptr, string email) {
    Teste::apresentacaoTeste(email);
    int resultado_teste = 0;
    try {
        ptr->setEmail(email);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
   Teste::checaResultado(esperando_resultado, resultado_teste);

}
//-----------------------------------------------------------------------------------------------------------
void TesteValidadores::testarValidadorEndereco(int esperando_resultado, Hotel *ptr, string endereco) {
    Teste::apresentacaoTeste(endereco);
    int resultado_teste = 0;
    try {
        ptr->setEndereco(endereco);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);

}
//-----------------------------------------------------------------------------------------------------------
void TesteValidadores::testarValidadorDia(int esperando_resultado, Data *ptr, int dia) {
    Teste::apresentacaoTeste(dia);
    int resultado_teste = 0;
    try {
        ptr->setData(dia, Data::JAN, 2000); //(valor, padrao , padrao)
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);

}
void TesteValidadores::testarValidadorMes(int esperando_resultado, Data *ptr, int mes) {
    Teste::apresentacaoTeste(mes);
    int resultado_teste = 0;
    try {
        ptr->setData(1, mes, 2000); //(padrao,valor, padrao)
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);

}
void TesteValidadores::testarValidadorAno(int esperando_resultado, Data *ptr, int ano) {
    Teste::apresentacaoTeste(ano);
    int resultado_teste = 0;
    try {
        ptr->setData(1, Data::JAN, ano); //(padrao, padrao , valor)
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);

}