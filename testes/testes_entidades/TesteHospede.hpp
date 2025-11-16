#ifndef TESTESHOSPEDE_HPP
#define TESTESHOSPEDE_HPP

#include "../../libs/teste/InterfaceDeTestes.hpp"
#include <string>

using namespace Teste;
using namespace Hotelaria;

class TesteHospede : public InterfaceDeTeste {
public:
    TesteHospede() = default;

    // O metodo principal que contém a lógica de teste de integração
    void executar() override;
};

#endif // TESTESHOSPEDE_HPP