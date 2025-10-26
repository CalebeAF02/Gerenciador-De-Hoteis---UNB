//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCARTAO_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCARTAO_H

#include "../interface_tests/TestsBase.h"
#include "../../dominios/Cartao.h"
#include <vector>
#include <string>

class TestsCartao : public TestsBase
{
public:
    void executar() override;
    std::string nome() const override { return "TestsCartao"; }

private:
    void testarCartoesValidos();
    void testarCartoesComMenosDigitos();
    void testarCartoesComMaisDigitos();
    void testarCartoesComLetras();
    void testarCartoesComSimbolos();
    void testarCartoesComEspacos();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCARTAO_H