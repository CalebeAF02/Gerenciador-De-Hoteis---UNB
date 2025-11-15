#ifndef TESTSSENHA_H
#define TESTSSENHA_H

#include "../../libs/teste/InterfaceDeTestes.hpp"
#include "Senha.hpp"
#include <vector>
#include <string>
#include  "IO.hpp"

using namespace Teste;
class TesteSenha : public InterfaceDeTeste {
public:
    void executar() override;
};

#endif // TESTSSENHA_H