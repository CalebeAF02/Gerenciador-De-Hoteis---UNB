#ifndef TESTSNOME_HPP
#define TESTSNOME_HPP

#include "InterfaceDeTestes.hpp"
#include <string>

class TesteNome : public InterfaceDeTeste {
public:
    void executar() override;
};

#endif // TESTSNOME_HPP