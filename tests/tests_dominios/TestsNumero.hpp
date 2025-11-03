//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSNUMERO_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSNUMERO_H

#include "InterfaceDeTeste.hpp"
#include "Numero.hpp"
#include <vector>
#include <string>
#include  "ConsoleIO.hpp"

class TestsNumero : public InterfaceDeTeste {
public:
    void executar() override;

    string nomeDoTeste() const override { return "TestsNumero"; }

private:
    void testarNumerosValidos();

    void testarNumerosNegativos();

    void testarNumerosComLetras();

    void testarNumerosComSimbolos();

    void testarNumerosComEspacos();

    void testarNumerosVazios();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSNUMERO_H