//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSHOTEIS_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSHOTEIS_H

#include "../interface_tests/TestsBase.h"
#include "../../dominios/Nome.h"
#include "../../dominios/Endereco.h"
#include "../../dominios/Telefone.h"
#include "../../dominios/Codigo.h"
#include "../../entidades/Hotel.h"

class TestsHotel : public TestsBase
{
public:
    void executar() override;
    std::string nome() const override { return "TestsHotel"; }

private:
    void testarNome();
    void testarEndereco();
    void testarTelefone();
    void testarCodigo();

    void testarNomeInvalido();
    void testarEnderecoInvalido();
    void testarTelefoneInvalido();
    void testarCodigoInvalido();

    void testarConstrucaoCompleta();
    void testarConstrucaoInvalida();

    void testarGetters();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSHOTEIS_H