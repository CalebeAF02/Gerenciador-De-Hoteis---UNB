#ifndef TESTSHOTEL_H
#define TESTSHOTEL_H

#include "InterfaceDeTeste.h"
#include "Hotel.h"
#include "Nome.h"
#include "Endereco.h"
#include "Telefone.h"
#include "Codigo.h"
#include <string>

class TestsHotel : public InterfaceDeTeste {
public:
    void executar() override;

    std::string nomeDoTeste() const override { return "TestsHotel"; }

private:
    void testarNome();

    void testarNomeInvalido();

    void testarEndereco();

    void testarEnderecoInvalido();

    void testarTelefone();

    void testarTelefoneInvalido();

    void testarCodigo();

    void testarCodigoInvalido();

    void testarConstrucaoCompleta();

    void testarConstrucaoInvalida();

    void testarGetters();
};

#endif // TESTSHOTEL_H