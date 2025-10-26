//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSHOSPEDES_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSHOSPEDES_H

#include "../interface_tests/TestsBase.h"
#include "../../dominios/Nome.h"
#include "../../dominios/Email.h"
#include "../../dominios/Endereco.h"
#include "../../dominios/Cartao.h"
#include "../../entidades/Hospede.h"

class TestsHospede : public TestsBase
{
public:
    void executar() override;
    std::string nome() const override { return "TestsHospede"; }

private:
    void testarNome();
    void testarEmail();
    void testarEndereco();
    void testarCartao();

    void testarNomeInvalido();
    void testarEmailInvalido();
    void testarEnderecoInvalido();
    void testarCartaoInvalido();

    void testarConstrucaoCompleta();
    void testarConstrucaoInvalida();

    void testarGetters();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSHOSPEDES_H