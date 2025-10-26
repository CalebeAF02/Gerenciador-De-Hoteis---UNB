//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCAPACIDADE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCAPACIDADE_H

#include "../interface_tests/TestsBase.h"
#include "../../dominios/Capacidade.h"
#include <vector>

class TestsCapacidade : public TestsBase
{
public:
    void executar() override;
    std::string nome() const override { return "TestsCapacidade"; }

private:
    void testarCapacidadesValidas();
    void testarCapacidadesNegativas();
    void testarCapacidadesZero();
    void testarCapacidadesMuitoAltas();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCAPACIDADE_H