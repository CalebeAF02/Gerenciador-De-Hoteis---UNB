#ifndef TESTSSENHA_H
#define TESTSSENHA_H

#include "InterfaceDeTestes.hpp"
#include "Senha.hpp"
#include <vector>
#include <string>
#include  "IO.hpp"

class TesteSenha : public InterfaceDeTeste {
public:
    void executar() override;
};

#endif // TESTSSENHA_H