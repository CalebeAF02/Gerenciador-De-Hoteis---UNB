#ifndef TESTSRESERVA_HPP
#define TESTSRESERVA_HPP

#include "../../libs/teste/InterfaceDeTestes.hpp"
#include <string>

using namespace Teste;
using namespace Hotelaria;

// A classe TestsReserva testa a integração da Entidade Reserva.
class TesteReserva : public InterfaceDeTeste {
public:
    TesteReserva() = default;

    // O metodo principal que contém a lógica de teste de integração
    void executar() override;
};

#endif // TESTSRESERVA_HPP