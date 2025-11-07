#ifndef TESTSRESERVA_HPP
#define TESTSRESERVA_HPP

#include "InterfaceDeTestes.hpp"
#include <string>

// A classe TestsReserva testa a integração da Entidade Reserva.
class TesteReserva : public InterfaceDeTeste {
public:
    TesteReserva() = default;

    // O metodo principal que contém a lógica de teste de integração
    void executar() override;

    // Retorna o nome do grupo de testes.
    string nomeDoTeste() const override {
        return "Teste de Entidade: Reserva";
    }
};

#endif // TESTSRESERVA_HPP