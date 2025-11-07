#ifndef TESTSNOME_HPP
#define TESTSNOME_HPP

#include "InterfaceDeTestes.hpp"
#include <string>

class TesteNome : public InterfaceDeTeste {
public:
    void executar() override;

    // Retorna o nome do grupo de testes.
    string nomeDoTeste() const override {
        return "Teste de Dominio: Nome";
    }
};

#endif // TESTSNOME_HPP