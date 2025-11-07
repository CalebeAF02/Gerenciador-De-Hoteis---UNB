#ifndef TESTESHOSPEDE_HPP
#define TESTESHOSPEDE_HPP

#include "InterfaceDeTestes.hpp"
#include <string>

class TesteHospede : public InterfaceDeTeste {
public:
    TesteHospede() = default;

    // O metodo principal que contém a lógica de teste de integração
    void executar() override;

    // Retorna o nome do grupo de testes.
    string nomeDoTeste() const override {
        return "Teste de Entidade: Hospede";
    }
};

#endif // TESTESHOSPEDE_HPP