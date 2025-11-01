#include "TestsCodigo.h"
#include <iostream>
#include <vector>

void TestsCodigo::executar() {
    testarCodigosValidos();
    testarCodigosComCaracteresInvalidos();
    testarCodigosComEspacos();
    testarCodigosMuitoCurtos();
    testarCodigosMuitoLongos();
}

void TestsCodigo::testarCodigosValidos() {
    std::vector<std::string> codigos;
    codigos.push_back("ABC123");
    codigos.push_back("X9Y8Z7");
    codigos.push_back("Codigo01");
    codigos.push_back("A1B2C3");
    codigos.push_back("ZXC987");

    for (std::size_t i = 0; i < codigos.size(); ++i) {
        std::string codigo = codigos[i];
        apresentacaoTeste(codigo);
        try {
            Codigo c(codigo);
            checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
        }
    }
}

void TestsCodigo::testarCodigosComCaracteresInvalidos() {
    std::vector<std::string> codigos;
    codigos.push_back("ABC@123");
    codigos.push_back("X9Y#Z7");
    codigos.push_back("Codigo!");
    codigos.push_back("A1B2*C3");
    codigos.push_back("ZXC$987");

    for (std::size_t i = 0; i < codigos.size(); ++i) {
        std::string codigo = codigos[i];
        apresentacaoTeste(codigo);
        try {
            Codigo c(codigo);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsCodigo::testarCodigosComEspacos() {
    std::vector<std::string> codigos;
    codigos.push_back("ABC 123");
    codigos.push_back(" X9Y8Z7");
    codigos.push_back("Codigo 01");
    codigos.push_back("A1B2 C3");
    codigos.push_back("ZXC987 ");

    for (std::size_t i = 0; i < codigos.size(); ++i) {
        std::string codigo = codigos[i];
        apresentacaoTeste(codigo);
        try {
            Codigo c(codigo);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsCodigo::testarCodigosMuitoCurtos() {
    std::vector<std::string> codigos;
    codigos.push_back("A1");
    codigos.push_back("X9");
    codigos.push_back("C0");
    codigos.push_back("Z");
    codigos.push_back("1");

    for (std::size_t i = 0; i < codigos.size(); ++i) {
        std::string codigo = codigos[i];
        apresentacaoTeste(codigo);
        try {
            Codigo c(codigo);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsCodigo::testarCodigosMuitoLongos() {
    std::vector<std::string> codigos;
    codigos.push_back("ABC123XYZ789DEF456");
    codigos.push_back(std::string(25, 'A'));

    for (std::size_t i = 0; i < codigos.size(); ++i) {
        std::string codigo = codigos[i];
        apresentacaoTeste(codigo);
        try {
            Codigo c(codigo);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}