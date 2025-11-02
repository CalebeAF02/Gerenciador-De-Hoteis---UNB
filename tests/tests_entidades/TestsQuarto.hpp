#ifndef TESTSQUARTO_H
#define TESTSQUARTO_H

#include "InterfaceDeTeste.hpp"
#include "Quarto.hpp"
#include "Numero.hpp"
#include "Capacidade.hpp"
#include "Dinheiro.hpp"
#include "Ramal.hpp"
#include <string>

class TestsQuarto : public InterfaceDeTeste {
public:
    void executar() override;

    string nomeDoTeste() const override { return "TestsQuarto"; }

private:
    void testarNumero();

    void testarNumeroInvalido();

    void testarCapacidade();

    void testarCapacidadeInvalida();

    void testarDiaria();

    void testarDiariaInvalida();

    void testarRamal();

    void testarRamalInvalido();

    void testarConstrucaoCompleta();

    void testarConstrucaoInvalida();

    void testarGetters();
};

#endif // TESTSQUARTO_H
