#ifndef TESTSNOME_HPP
#define TESTSNOME_HPP

#include "../../libs/teste/InterfaceDeTestes.hpp"
#include <string>

using namespace Teste;
class TesteNome : public InterfaceDeTeste {
public:
    void executar() override;
};

#endif // TESTSNOME_HPP