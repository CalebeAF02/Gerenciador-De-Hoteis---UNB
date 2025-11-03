//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCAPACIDADE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCAPACIDADE_H

#include "Capacidade.hpp"
#include <vector>

#include "InterfaceDeTeste.hpp"
#include  "ConsoleIO.hpp"

class TestsCapacidade : public InterfaceDeTeste {
public:
    void executar() override;

    string nomeDoTeste() const override { return "TestsCapacidade"; }

private:
    void testarCapacidadesValidas();

    void testarCapacidadesNegativas();

    void testarCapacidadesZero();

    void testarCapacidadesMuitoAltas();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCAPACIDADE_H