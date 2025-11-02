//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCODIGOS_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCODIGOS_H

#include "Codigo.hpp"
#include <vector>
#include <string>

#include "InterfaceDeTeste.hpp"

class TestsCodigo : public InterfaceDeTeste {
public:
    void executar() override;

    string nomeDoTeste() const override { return "TestsCodigo"; }

private:
    void testarCodigosValidos();

    void testarCodigosComCaracteresInvalidos();

    void testarCodigosComEspacos();

    void testarCodigosMuitoCurtos();

    void testarCodigosMuitoLongos();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCODIGOS_H
