//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSRESERVAS_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSRESERVAS_H

#include "../interface_tests/TestsBase.h"
#include "../../utilitarios/Data.h"
#include "../../dominios/Dinheiro.h"
#include "../../dominios/Codigo.h"
#include "../../entidades/Reserva.h"

class TestsReserva : public TestsBase
{
public:
    void executar() override;
    std::string nome() const override { return "TestsReserva"; }

private:
    void testarChegada();
    void testarPartida();
    void testarDinheiro();
    void testarCodigo();

    void testarChegadaInvalida();
    void testarPartidaInvalida();
    void testarDinheiroInvalido();
    void testarCodigoInvalido();

    void testarConstrucaoCompleta();
    void testarConstrucaoInvalida();

    void testarGetters();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSRESERVAS_H