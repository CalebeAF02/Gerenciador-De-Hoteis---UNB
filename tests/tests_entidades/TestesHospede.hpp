#ifndef TESTSHOSPEDE_H
#define TESTSHOSPEDE_H

#include "InterfaceDeTeste.hpp"
#include "Hospede.hpp"
#include "Nome.hpp"
#include "Email.hpp"
#include "Endereco.hpp"
#include "Cartao.hpp"
#include <string>

class TestesHospede : public InterfaceDeTeste {
public:
    void executar() override;

    string nomeDoTeste() const override;
};

#endif // TESTSHOSPEDE_H