#ifndef TESTSHOTEL_H
#define TESTSHOTEL_H

#include "InterfaceDeTeste.hpp"
#include "Hotel.hpp"
#include "Nome.hpp"
#include "Endereco.hpp"
#include "Telefone.hpp"
#include "Codigo.hpp"
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
