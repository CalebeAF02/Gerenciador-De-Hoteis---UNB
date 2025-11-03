#ifndef TESTSNOME_H
#define TESTSNOME_H

#include "InterfaceDeTeste.hpp"
#include "../../include/sistema/utilitarios/console/ConsoleFormatter.hpp"
#include "Nome.hpp"
#include <vector>
#include <string>
#include  "ConsoleIO.hpp"

class TestsNome : public InterfaceDeTeste {
public:
    void executar() override;

    string nomeDoTeste() const override {
        return "TestsNome";
    }

private:
    void testarNomesValidos();

    void testarNomesInvalidos();

    void testarNomesComNumeros();

    void testarNomesMuitoLongos();

    void testarNomesSemMaiusculaInicial();

    void testarNomesComEspacoInvalido();

    void testarNomesComCaracteresEspeciais();
};

#endif // TESTSNOME_H