#ifndef TESTSNOME_HPP
#define TESTSNOME_HPP

#include "../../libs/teste/InterfaceDeTestes.hpp"
#include <string>

using namespace Teste;
using namespace Hotelaria;

class TesteNome : public InterfaceDeTeste {
public:
    void executar() override;
};

#endif // TESTSNOME_HPP