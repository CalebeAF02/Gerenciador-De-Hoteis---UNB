//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSNUMERO_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSNUMERO_H

#include "../interface_tests/TestsBase.h"
#include "../../dominios/Numero.h"
#include <vector>
#include <string>

class TestsNumero : public TestsBase
{
public:
    void executar() override;
    std::string nome() const override { return "TestsNumero"; }

private:
    void testarNumerosValidos();
    void testarNumerosNegativos();
    void testarNumerosComLetras();
    void testarNumerosComSimbolos();
    void testarNumerosComEspacos();
    void testarNumerosVazios();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSNUMERO_H