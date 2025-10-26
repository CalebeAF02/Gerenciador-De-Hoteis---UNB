//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCODIGOS_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCODIGOS_H

#include "../interface_tests/TestsBase.h"
#include "../../dominios/Codigo.h"
#include <vector>
#include <string>

class TestsCodigo : public TestsBase
{
public:
    void executar() override;
    std::string nome() const override { return "TestsCodigo"; }

private:
    void testarCodigosValidos();
    void testarCodigosComCaracteresInvalidos();
    void testarCodigosComEspacos();
    void testarCodigosMuitoCurtos();
    void testarCodigosMuitoLongos();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCODIGOS_H