#ifndef TESTSQUARTO_H
#define TESTSQUARTO_H

#include "InterfaceDeTeste.hpp"
#include "Quarto.hpp"
#include "Numero.hpp"
#include "Capacidade.hpp"
#include "Dinheiro.hpp"
#include "Ramal.hpp"
#include <string>

class TestesQuarto : public InterfaceDeTeste {
public:
    void executar() override;

    string nomeDoTeste() const override;
};

#endif // TESTSQUARTO_H