#include "TestsDinheiro.hpp"
#include <iostream>
#include <vector>

void TestsDinheiro::executar() {
    testarValoresValidos();
    testarValoresNegativos();
    testarValoresZero();
    testarValoresMuitoAltos();
}

void TestsDinheiro::testarValoresValidos() {
    vector<int> valores;
    valores.push_back(1);
    valores.push_back(100);
    valores.push_back(9999);
    valores.push_back(100000);
    valores.push_back(99999999);
    valores.push_back(100000000);

    for (size_t i = 0; i < valores.size(); ++i) {
        int valor = valores[i];
        apresentacaoTeste(valor);
        try {
            Dinheiro d(valor);
            checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
        }
    }
}

void TestsDinheiro::testarValoresNegativos() {
    vector<int> valores;
    valores.push_back(-1);
    valores.push_back(-100);
    valores.push_back(-99999999);

    for (size_t i = 0; i < valores.size(); ++i) {
        int valor = valores[i];
        apresentacaoTeste(valor);
        try {
            Dinheiro d(valor);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsDinheiro::testarValoresZero() {
    apresentacaoTeste(0);
    try {
        Dinheiro d(0);
        checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
    } catch (invalid_argument &e) {
        checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
    }
}

void TestsDinheiro::testarValoresMuitoAltos() {
    vector<int> valores;
    valores.push_back(100000001);
    valores.push_back(500000000);
    valores.push_back(999999999);

    for (size_t i = 0; i < valores.size(); ++i) {
        int valor = valores[i];
        apresentacaoTeste(valor);
        try {
            Dinheiro d(valor);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}