#ifndef TESTSRESERVA_H
#define TESTSRESERVA_H

#include "InterfaceDeTeste.hpp"
#include "Reserva.hpp"
#include "Data.hpp"
#include "Dinheiro.hpp"
#include "Codigo.hpp"
#include <string>

class TestesReserva : public InterfaceDeTeste {
public:
    void executar() override;

    string nomeDoTeste() const override;
};

#endif // TESTSRESERVA_H