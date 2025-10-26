//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSNOME_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSNOME_H

#include "../interface_tests/TestsBase.h"
#include "../../dominios/Nome.h"

class TestsNome : public TestsBase
{
public:
    void executar() override;
    std::string nome() const override { return "TestsNome"; }

private:
    void testarNomesValidos();
    void testarNomesInvalidos();
    void testarNomesComNumeros();
    void testarNomesMuitoLongos();
    void testarNomesSemMaiusculaInicial();
    void testarNomesComEspacoInvalido();
    void testarNomesComCaracteresEspeciais();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSNOME_H