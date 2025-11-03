//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSENDERECO_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSENDERECO_H

#include "InterfaceDeTeste.hpp"
#include "Endereco.hpp"
#include <vector>
#include <string>
#include  "ConsoleIO.hpp"

class TestsEndereco : public InterfaceDeTeste {
public:
    void executar() override;

    string nomeDoTeste() const override { return "TestsEndereco"; }

private:
    void testarEnderecosValidos();

    void testarEnderecosComCaracteresInvalidos();

    void testarEnderecosComInicioOuFimInvalido();

    void testarEnderecosMuitoLongos();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSENDERECO_H