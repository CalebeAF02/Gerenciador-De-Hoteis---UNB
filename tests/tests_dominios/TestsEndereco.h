//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSENDERECO_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSENDERECO_H

#include "../interface_tests/TestsBase.h"
#include "../../dominios/Endereco.h"
#include <vector>
#include <string>

class TestsEndereco : public TestsBase
{
public:
    void executar() override;
    std::string nome() const override { return "TestsEndereco"; }

private:
    void testarEnderecosValidos();
    void testarEnderecosComCaracteresInvalidos();
    void testarEnderecosComInicioOuFimInvalido();
    void testarEnderecosMuitoLongos();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSENDERECO_H