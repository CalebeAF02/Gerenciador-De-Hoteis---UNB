#include "TestsRamal.h"
#include <iostream>
#include <vector>

void TestsRamal::executar() {
    testarRamaisValidos();
    testarRamaisComMenosDigitos();
    testarRamaisComMaisDigitos();
    testarRamaisComLetras();
    testarRamaisComSimbolos();
    testarRamaisComEspacos();
}

void TestsRamal::testarRamaisValidos() {
    std::vector<std::string> ramais;
    ramais.push_back("0000");
    ramais.push_back("1234");
    ramais.push_back("9999");
    ramais.push_back("0456");
    ramais.push_back("7001");

    for (std::size_t i = 0; i < ramais.size(); ++i) {
        std::string ramal = ramais[i];
        apresentacaoTeste(ramal);
        try {
            Ramal r(ramal);
            checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
        }
    }
}

void TestsRamal::testarRamaisComMenosDigitos() {
    std::vector<std::string> ramais;
    ramais.push_back("0");
    ramais.push_back("12");
    ramais.push_back("123");

    for (std::size_t i = 0; i < ramais.size(); ++i) {
        std::string ramal = ramais[i];
        apresentacaoTeste(ramal);
        try {
            Ramal r(ramal);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsRamal::testarRamaisComMaisDigitos() {
    std::vector<std::string> ramais;
    ramais.push_back("12345");
    ramais.push_back("00001");
    ramais.push_back("99999");

    for (std::size_t i = 0; i < ramais.size(); ++i) {
        std::string ramal = ramais[i];
        apresentacaoTeste(ramal);
        try {
            Ramal r(ramal);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsRamal::testarRamaisComLetras() {
    std::vector<std::string> ramais;
    ramais.push_back("12a4");
    ramais.push_back("abcd");
    ramais.push_back("9b9c");

    for (std::size_t i = 0; i < ramais.size(); ++i) {
        std::string ramal = ramais[i];
        apresentacaoTeste(ramal);
        try {
            Ramal r(ramal);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsRamal::testarRamaisComSimbolos() {
    std::vector<std::string> ramais;
    ramais.push_back("12@4");
    ramais.push_back("99#9");
    ramais.push_back("!000");

    for (std::size_t i = 0; i < ramais.size(); ++i) {
        std::string ramal = ramais[i];
        apresentacaoTeste(ramal);
        try {
            Ramal r(ramal);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsRamal::testarRamaisComEspacos() {
    std::vector<std::string> ramais;
    ramais.push_back(" 123");
    ramais.push_back("12 3");
    ramais.push_back("123 ");
    ramais.push_back("1 2 3 4");

    for (std::size_t i = 0; i < ramais.size(); ++i) {
        std::string ramal = ramais[i];
        apresentacaoTeste(ramal);
        try {
            Ramal r(ramal);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}