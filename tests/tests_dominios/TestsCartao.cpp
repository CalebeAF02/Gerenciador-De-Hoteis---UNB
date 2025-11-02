#include "TestsCartao.hpp"
#include <iostream>
#include <vector>

void TestsCartao::executar() {
    testarCartoesValidos();
    testarCartoesComMenosDigitos();
    testarCartoesComMaisDigitos();
    testarCartoesComLetras();
    testarCartoesComSimbolos();
    testarCartoesComEspacos();
}

void TestsCartao::testarCartoesValidos() {
    vector<string> cartoes;
    cartoes.push_back("4111111111111111");
    cartoes.push_back("5500000000000004");
    cartoes.push_back("340000000000009");
    cartoes.push_back("6011000000000004");
    cartoes.push_back("3530111333300000");

    for (size_t i = 0; i < cartoes.size(); ++i) {
        string cartao = cartoes[i];
        apresentacaoTeste(cartao);
        try {
            Cartao c(cartao);
            checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
        }
    }
}

void TestsCartao::testarCartoesComMenosDigitos() {
    vector<string> cartoes;
    cartoes.push_back("411111111111");
    cartoes.push_back("55000000");
    cartoes.push_back("1234567890123");

    for (size_t i = 0; i < cartoes.size(); ++i) {
        string cartao = cartoes[i];
        apresentacaoTeste(cartao);
        try {
            Cartao c(cartao);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsCartao::testarCartoesComMaisDigitos() {
    vector<string> cartoes;
    cartoes.push_back("41111111111111112222");
    cartoes.push_back("55000000000000040000");

    for (size_t i = 0; i < cartoes.size(); ++i) {
        string cartao = cartoes[i];
        apresentacaoTeste(cartao);
        try {
            Cartao c(cartao);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsCartao::testarCartoesComLetras() {
    vector<string> cartoes;
    cartoes.push_back("4111a11111111111");
    cartoes.push_back("5500b00000000004");
    cartoes.push_back("abcdabcdabcdabcd");

    for (size_t i = 0; i < cartoes.size(); ++i) {
        string cartao = cartoes[i];
        apresentacaoTeste(cartao);
        try {
            Cartao c(cartao);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsCartao::testarCartoesComSimbolos() {
    vector<string> cartoes;
    cartoes.push_back("4111-1111-1111-1111");
    cartoes.push_back("5500.0000.0000.0004");
    cartoes.push_back("6011@0000#0000$0004");

    for (size_t i = 0; i < cartoes.size(); ++i) {
        string cartao = cartoes[i];
        apresentacaoTeste(cartao);
        try {
            Cartao c(cartao);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsCartao::testarCartoesComEspacos() {
    vector<string> cartoes;
    cartoes.push_back("4111 1111 1111 1111");
    cartoes.push_back("5500 0000 0000 0004");
    cartoes.push_back("6011 0000 0000 0004");

    for (size_t i = 0; i < cartoes.size(); ++i) {
        string cartao = cartoes[i];
        apresentacaoTeste(cartao);
        try {
            Cartao c(cartao);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}