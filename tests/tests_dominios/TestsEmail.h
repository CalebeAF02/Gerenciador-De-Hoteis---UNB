//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSEMAIL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSEMAIL_H

#include "TestsBase.h"
#include "Email.h"
#include <vector>
#include <string>

class TestsEmail : public TestsBase
{
public:
    void executar() override;
    std::string nome() const override { return "TestsEmail"; }

private:
    void testarEmailsValidos();
    void testarEmailsInvalidosFormato();
    void testarEmailsComCaracteresInvalidos();
    void testarEmailsComParteLocalInvalida();
    void testarEmailsComDominioInvalido();
    void testarEmailsMuitoLongos();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSEMAIL_H