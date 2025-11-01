#ifndef TESTSQUARTO_H
#define TESTSQUARTO_H

#include "InterfaceDeTeste.h"
#include "Quarto.h"
#include "Numero.h"
#include "Capacidade.h"
#include "Dinheiro.h"
#include "Ramal.h"
#include <string>

class TestsQuarto : public InterfaceDeTeste {
public:
    void executar() override;

    std::string nomeDoTeste() const override { return "TestsQuarto"; }

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