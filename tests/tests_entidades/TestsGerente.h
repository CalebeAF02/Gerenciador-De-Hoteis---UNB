#ifndef TESTSGERENTE_H
#define TESTSGERENTE_H

#include "InterfaceDeTeste.h"
#include "Gerente.h"
#include "Nome.h"
#include "Email.h"
#include "Senha.h"
#include "Ramal.h"

#include <string>

class TestsGerente : public InterfaceDeTeste {
public:
    void executar() override;

    std::string nomeDoTeste() const override { return "TestsGerente"; }

private:
    void testarNome();

    void testarNomeInvalido();

    void testarEmail();

    void testarEmailInvalido();

    void testarSenha();

    void testarSenhaInvalida();

    void testarRamal();

    void testarRamalInvalido();

    void testarConstrucaoCompleta();

    void testarConstrucaoInvalida();

    void testarGetters();
};

#endif // TESTSGERENTE_H