#include "TesteHotel.hpp"
#include "SmokeTeste.hpp"
#include "sistema/entidades/Hotel.hpp"
#include "sistema/dominios/Nome.hpp"
#include "sistema/dominios/Endereco.hpp"
#include "sistema/dominios/Codigo.hpp"
#include "ConsoleFormatter.hpp"

//------------------------------------------------------------------------------------------------------------------
void TesteHotel::executar() {
    SmokeTeste smoke_teste;
    Hotel hotel1; // Instância da Entidade a ser testada

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE ENTIDADE: HOTEL (ATRIBUICAO DE DOMINIOS)");

    // =========================================================================
    // 1. ATRIBUIÇÃO DE NOME
    // =========================================================================
    const string nomeStr = "Hotel Bandeirantes";
    ConsoleFormatter::MostrarSeparadorCategoria("1. Atribuicao de Nome Valido");

    smoke_teste.testarEntidade(
        InterfaceDeTeste::DEVE_DAR_CERTO,
        nomeStr,
        "Hotel - Nome",
        [&hotel1, &nomeStr]() { hotel1.setNome(Nome(nomeStr)); }
    );

    // =========================================================================
    // 2. ATRIBUIÇÃO DE ENDEREÇO
    // =========================================================================
    const string enderecoStr = "Asa Norte Bloco A 10"; // Endereço de exemplo
    ConsoleFormatter::MostrarSeparadorCategoria("2. Atribuicao de Endereco Valido");

    smoke_teste.testarEntidade(
        InterfaceDeTeste::DEVE_DAR_CERTO,
        enderecoStr,
        "Hotel - Endereco",
        [&hotel1, &enderecoStr]() { hotel1.setEndereco(Endereco(enderecoStr)); }
    );

    // =========================================================================
    // 3. ATRIBUIÇÃO DE CÓDIGO
    // =========================================================================
    // Código deve ter 10 caracteres, letras (a-z) ou dígitos (0-9).
    const string codigoStr = "A1b2C3d4E5";
    ConsoleFormatter::MostrarSeparadorCategoria("3. Atribuicao de Codigo Valido");

    smoke_teste.testarEntidade(
        InterfaceDeTeste::DEVE_DAR_CERTO,
        codigoStr,
        "Hotel - Codigo",
        [&hotel1, &codigoStr]() { hotel1.setCodigo(Codigo(codigoStr)); }
    );
}

//------------------------------------------------------------------------------------------------------------------