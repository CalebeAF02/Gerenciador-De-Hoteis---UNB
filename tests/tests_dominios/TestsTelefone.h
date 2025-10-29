//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSTELEFONE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSTELEFONE_H

#include "TestsBase.h"
#include "Telefone.h"
#include <vector>
#include <string>

class TestsTelefone : public TestsBase
{
public:
    void executar() override;
    std::string nome() const override { return "TestsTelefone"; }

private:
    void testarTelefonesValidos();
    void testarTelefonesComFormatoInvalido();
    void testarTelefonesComPrefixoInvalido();
    void testarTelefonesComCaracteresInvalidos();
    void testarTelefonesComDigitosInvalidos();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSTELEFONE_H