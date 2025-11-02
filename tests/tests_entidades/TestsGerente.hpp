#ifndef TESTSGERENTE_H
#define TESTSGERENTE_H

#include "InterfaceDeTeste.hpp"
#include "Gerente.hpp"
#include "Nome.hpp"
#include "Email.hpp"
#include "Senha.hpp"
#include "Ramal.hpp"

#include <string>

class TestsGerente : public InterfaceDeTeste {
public:
    void executar() override;

    string nomeDoTeste() const override { return "TestsGerente"; }

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
