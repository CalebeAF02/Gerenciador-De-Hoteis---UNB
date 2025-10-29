//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSGERENTES_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSGERENTES_H

#include "../interface_tests/TestsBase.h"
#include "Nome.h"
#include "Email.h"
#include "Senha.h"
#include "Ramal.h"
#include "Gerente.h"

class TestsGerente : public TestsBase
{
public:
    void executar() override;
    std::string nome() const override { return "TestsGerente"; }

private:
    void testarNome();
    void testarEmail();
    void testarSenha();
    void testarRamal();

    void testarNomeInvalido();
    void testarEmailInvalido();
    void testarSenhaInvalida();
    void testarRamalInvalido();

    void testarConstrucaoCompleta();
    void testarConstrucaoInvalida();

    void testarGetters();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSGERENTES_H