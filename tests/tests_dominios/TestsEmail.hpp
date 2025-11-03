//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSEMAIL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSEMAIL_H

#include "Email.hpp"
#include <vector>
#include <string>

#include "InterfaceDeTeste.hpp"
#include  "ConsoleIO.hpp"

class TestsEmail : public InterfaceDeTeste {
public:
    void executar() override;

    string nomeDoTeste() const override { return "TestsEmail"; }

private:
    void testarEmailsValidos();

    void testarEmailsInvalidosFormato();

    void testarEmailsComCaracteresInvalidos();

    void testarEmailsComParteLocalInvalida();

    void testarEmailsComDominioInvalido();

    void testarEmailsMuitoLongos();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSEMAIL_H