#ifndef TESTSGERENTE_H
#define TESTSGERENTE_H

#include "InterfaceDeTeste.hpp"
#include "Gerente.hpp"
#include "Nome.hpp"
#include "Email.hpp"
#include "Senha.hpp"
#include "Ramal.hpp"

#include <string>

class TestesGerente : public InterfaceDeTeste {
public:
    void executar() override;

    string nomeDoTeste() const override;
};

#endif // TESTSGERENTE_H