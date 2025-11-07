#ifndef TESTSQUARTO_HPP
#define TESTSQUARTO_HPP

#include "InterfaceDeTestes.hpp"
#include <string>

// A classe TestsQuarto testa a integração da Entidade Quarto.
class TesteQuarto : public InterfaceDeTeste {
public:
    TesteQuarto() = default;

    // O metodo principal que contém a lógica de teste de integração
    void executar() override;

    // Retorna o nome do grupo de testes.
    string nomeDoTeste() const override {
        return "Teste de Entidade: Quarto";
    }
};

#endif // TESTSQUARTO_HPP