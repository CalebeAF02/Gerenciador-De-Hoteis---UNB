#include "TestsCapacidade.hpp"
#include <iostream>
#include <vector>

void TestsCapacidade::executar() {
    testarCapacidadesValidas();
    testarCapacidadesNegativas();
    testarCapacidadesZero();
    testarCapacidadesMuitoAltas();
}

void TestsCapacidade::testarCapacidadesValidas() {
    std::vector<int> capacidades;
    capacidades.push_back(1);
    capacidades.push_back(2);
    capacidades.push_back(4);
    capacidades.push_back(10);
    capacidades.push_back(999);

    for (std::size_t i = 0; i < capacidades.size(); ++i) {
        int capacidade = capacidades[i];
        apresentacaoTeste(capacidade);
        try {
            Capacidade c(capacidade);
            checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
        }
    }
}

void TestsCapacidade::testarCapacidadesNegativas() {
    std::vector<int> capacidades;
    capacidades.push_back(-1);
    capacidades.push_back(-10);
    capacidades.push_back(-999);

    for (std::size_t i = 0; i < capacidades.size(); ++i) {
        int capacidade = capacidades[i];
        apresentacaoTeste(capacidade);
        try {
            Capacidade c(capacidade);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsCapacidade::testarCapacidadesZero() {
    apresentacaoTeste(0);
    try {
        Capacidade c(0);
        checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
    } catch (std::invalid_argument &e) {
        checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
    }
}

void TestsCapacidade::testarCapacidadesMuitoAltas() {
    std::vector<int> capacidades;
    capacidades.push_back(1000);
    capacidades.push_back(5000);
    capacidades.push_back(99999);

    for (std::size_t i = 0; i < capacidades.size(); ++i) {
        int capacidade = capacidades[i];
        apresentacaoTeste(capacidade);
        try {
            Capacidade c(capacidade);
            checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
        }
    }
}