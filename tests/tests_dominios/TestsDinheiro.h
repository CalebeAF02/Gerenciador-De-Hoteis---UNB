//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSDINHEIRO_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSDINHEIRO_H

#include "TestsBase.h"
#include "Dinheiro.h"
#include <vector>

class TestsDinheiro : public TestsBase
{
public:
    void executar() override;
    std::string nome() const override { return "TestsDinheiro"; }

private:
    void testarValoresValidos();
    void testarValoresNegativos();
    void testarValoresZero();
    void testarValoresMuitoAltos();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSDINHEIRO_H