#ifndef TESTSQUARTO_HPP
#define TESTSQUARTO_HPP

#include "../../libs/teste/InterfaceDeTestes.hpp"
#include <string>

using namespace Teste;
// A classe TestsQuarto testa a integração da Entidade Quarto.
class TesteQuarto : public InterfaceDeTeste {
public:
    TesteQuarto() = default;

    // O metodo principal que contém a lógica de teste de integração
    void executar() override;
};

#endif // TESTSQUARTO_HPP