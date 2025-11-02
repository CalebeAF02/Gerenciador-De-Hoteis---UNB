#include "TestsNumero.hpp"
#include <iostream>
#include <vector>

void TestsNumero::executar() {
    testarNumerosValidos();
    testarNumerosNegativos();
    testarNumerosComLetras();
    testarNumerosComSimbolos();
    testarNumerosComEspacos();
    testarNumerosVazios();
}

void TestsNumero::testarNumerosValidos() {
    vector<string> numeros;
    numeros.push_back("1");
    numeros.push_back("123");
    numeros.push_back("9999");
    numeros.push_back("456");
    numeros.push_back("789");

    for (size_t i = 0; i < numeros.size(); ++i) {
        string numero = numeros[i];
        apresentacaoTeste(numero);
        try {
            Numero n(numero);
            checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
        }
    }
}

void TestsNumero::testarNumerosNegativos() {
    vector<string> numeros;
    numeros.push_back("-1");
    numeros.push_back("-123");
    numeros.push_back("-9999");

    for (size_t i = 0; i < numeros.size(); ++i) {
        string numero = numeros[i];
        apresentacaoTeste(numero);
        try {
            Numero n(numero);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsNumero::testarNumerosComLetras() {
    vector<string> numeros;
    numeros.push_back("12a3");
    numeros.push_back("abc");
    numeros.push_back("9b9c");

    for (size_t i = 0; i < numeros.size(); ++i) {
        string numero = numeros[i];
        apresentacaoTeste(numero);
        try {
            Numero n(numero);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsNumero::testarNumerosComSimbolos() {
    vector<string> numeros;
    numeros.push_back("12@3");
    numeros.push_back("99#9");
    numeros.push_back("!000");
    numeros.push_back("45.67");

    for (size_t i = 0; i < numeros.size(); ++i) {
        string numero = numeros[i];
        apresentacaoTeste(numero);
        try {
            Numero n(numero);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsNumero::testarNumerosComEspacos() {
    vector<string> numeros;
    numeros.push_back(" 123");
    numeros.push_back("12 3");
    numeros.push_back("123 ");
    numeros.push_back("1 2 3 4");

    for (size_t i = 0; i < numeros.size(); ++i) {
        string numero = numeros[i];
        apresentacaoTeste(numero);
        try {
            Numero n(numero);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsNumero::testarNumerosVazios() {
    vector<string> numeros;
    numeros.push_back("");
    numeros.push_back(" ");

    for (size_t i = 0; i < numeros.size(); ++i) {
        string numero = numeros[i];
        apresentacaoTeste(numero);
        try {
            Numero n(numero);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}