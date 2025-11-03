//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCARTAO_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCARTAO_H

#include "Cartao.hpp"
#include <vector>
#include <string>

#include "InterfaceDeTeste.hpp"
#include  "ConsoleIO.hpp"

class TestsCartao : public InterfaceDeTeste {
public:
    void executar() override;

    string nomeDoTeste() const override { return "TestsCartao"; }

private:
    void testarCartoesValidos();

    void testarCartoesComMenosDigitos();

    void testarCartoesComMaisDigitos();

    void testarCartoesComLetras();

    void testarCartoesComSimbolos();

    void testarCartoesComEspacos();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCARTAO_H