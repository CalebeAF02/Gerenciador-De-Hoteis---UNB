//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSQUARTOS_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSQUARTOS_H

#include "../interface_tests/TestsBase.h"
#include "../../dominios/Numero.h"
#include "../../dominios/Capacidade.h"
#include "../../dominios/Dinheiro.h"
#include "../../dominios/Ramal.h"
#include "../../entidades/Quarto.h"

class TestsQuarto : public TestsBase
{
public:
    void executar() override;
    std::string nome() const override { return "TestsQuarto"; }

private:
    void testarNumero();
    void testarCapacidade();
    void testarDiaria();
    void testarRamal();

    void testarNumeroInvalido();
    void testarCapacidadeInvalida();
    void testarDiariaInvalida();
    void testarRamalInvalido();

    void testarConstrucaoCompleta();
    void testarConstrucaoInvalida();

    void testarGetters();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSQUARTOS_H