#ifndef TESTSGERENTE_H
#define TESTSGERENTE_H

#include "../../libs/teste/InterfaceDeTestes.hpp"
#include "Gerente.hpp"
#include "Nome.hpp"
#include "Email.hpp"
#include "Ramal.hpp"
#include "Senha.hpp"

#include "TesteNome.hpp"
#include "TesteEmail.hpp"
#include "TesteRamal.hpp"
#include "TesteSenha.hpp"

#include <string>
using namespace Hotelaria;

class TesteGerente : public InterfaceDeTeste {
public:
    // Utilize a lista de inicialização e valores DUMMY válidos.
    TesteGerente() = default;

    void executar() override;
};

#endif // TESTSGERENTE_H