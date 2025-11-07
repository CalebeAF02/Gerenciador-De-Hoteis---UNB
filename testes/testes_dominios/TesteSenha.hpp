#ifndef TESTSSENHA_H
#define TESTSSENHA_H

#include "InterfaceDeTestes.hpp"
#include "Senha.hpp"
#include <vector>
#include <string>
#include  "ConsoleIO.hpp"

class TesteSenha : public InterfaceDeTeste {
public:
    void executar() override;

    // Retorna o nome do grupo de testes.
    string nomeDoTeste() const override {
        return "Teste de Dominio: Senha";
    }
};

#endif // TESTSSENHA_H