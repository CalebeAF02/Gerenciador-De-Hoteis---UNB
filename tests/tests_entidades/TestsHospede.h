#ifndef TESTSHOSPEDE_H
#define TESTSHOSPEDE_H

#include "InterfaceDeTeste.h"
#include "Hospede.h"
#include "Nome.h"
#include "Email.h"
#include "Endereco.h"
#include "Cartao.h"
#include <string>

class TestsHospede : public InterfaceDeTeste {
public:
    void executar() override;

    std::string nomeDoTeste() const override { return "TestsHospede"; }

private:
    void testarNome();

    void testarNomeInvalido();

    void testarEmail();

    void testarEmailInvalido();

    void testarEndereco();

    void testarEnderecoInvalido();

    void testarCartao();

    void testarCartaoInvalido();

    void testarConstrucaoCompleta();

    void testarConstrucaoInvalida();

    void testarGetters();
};

#endif // TESTSHOSPEDE_H