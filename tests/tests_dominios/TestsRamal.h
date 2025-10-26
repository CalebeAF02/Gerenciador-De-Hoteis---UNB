//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSRAMAL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSRAMAL_H

#include "../interface_tests/TestsBase.h"
#include "../../dominios/Ramal.h"
#include <vector>
#include <string>

class TestsRamal : public TestsBase
{
public:
    void executar() override;
    std::string nome() const override { return "TestsRamal"; }

private:
    void testarRamaisValidos();
    void testarRamaisComMenosDigitos();
    void testarRamaisComMaisDigitos();
    void testarRamaisComLetras();
    void testarRamaisComSimbolos();
    void testarRamaisComEspacos();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSRAMAL_H