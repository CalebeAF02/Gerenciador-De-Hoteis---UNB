#ifndef TESTSHOTEL_H
#define TESTSHOTEL_H

#include "InterfaceDeTeste.hpp"
#include "Hotel.hpp"
#include "Nome.hpp"
#include "Endereco.hpp"
#include "Telefone.hpp"
#include "Codigo.hpp"
#include <string>

class TestesHotel : public InterfaceDeTeste {
public:
    void executar() override;

    string nomeDoTeste() const override;
};

#endif // TESTSHOTEL_H