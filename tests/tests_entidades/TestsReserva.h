#ifndef TESTSRESERVA_H
#define TESTSRESERVA_H

#include "InterfaceDeTeste.h"
#include "Reserva.h"
#include "Data.h"
#include "Dinheiro.h"
#include "Codigo.h"
#include <string>

class TestsReserva : public InterfaceDeTeste {
public:
    void executar() override;

    std::string nomeDoTeste() const override { return "TestsReserva"; }

private:
    void testarChegada();

    void testarChegadaInvalida();

    void testarPartida();

    void testarPartidaInvalida();

    void testarDinheiro();

    void testarDinheiroInvalido();

    void testarCodigo();

    void testarCodigoInvalido();

    void testarConstrucaoCompleta();

    void testarConstrucaoInvalida();

    void testarGetters();
};

#endif // TESTSRESERVA_H