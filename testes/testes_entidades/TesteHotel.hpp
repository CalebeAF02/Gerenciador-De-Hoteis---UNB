#ifndef TESTSHOTEL_HPP
#define TESTSHOTEL_HPP

#include "InterfaceDeTestes.hpp"
#include <string>

// A classe TestsHotel testa a integração da Entidade Hotel.
class TesteHotel : public InterfaceDeTeste {
public:
    TesteHotel() = default;

    // O metodo principal que contém a lógica de teste de integração
    void executar() override;
};

#endif // TESTESHOTEL_HPP