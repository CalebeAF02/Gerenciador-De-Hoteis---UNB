#include "TesteReserva.hpp"
#include "SmokeTeste.hpp"
#include "sistema/entidades/Reserva.hpp"
#include "sistema/dominios/Codigo.hpp"
#include "../../include/sistema/dominios/Data.hpp"
#include "sistema/dominios/Dinheiro.hpp"
#include "ConsoleFormatter.hpp"

//------------------------------------------------------------------------------------------------------------------
void TesteReserva::executar() {
    SmokeTeste smoke_teste;
    Reserva reserva1; // Instância da Entidade a ser testada

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE ENTIDADE: RESERVA (ATRIBUICAO DE DOMINIOS)");

    // =========================================================================
    // 1. ATRIBUIÇÃO DE CÓDIGO
    // =========================================================================
    // Código deve ter 10 caracteres, letras (a-z) ou dígitos (0-9).
    const string codigoStr = "A1b2C3d4E5";
    ConsoleFormatter::MostrarSeparadorCategoria("1. Atribuicao de Codigo Valido");

    smoke_teste.testarEntidade(
        InterfaceDeTeste::DEVE_DAR_CERTO,
        codigoStr,
        "Reserva - Codigo",
        [&reserva1, &codigoStr]() { reserva1.setCodigo(Codigo(codigoStr)); }
    );

    // =========================================================================
    // 2. ATRIBUIÇÃO DE DATA (CHEGADA)
    // =========================================================================
    // Data (dia-mês-ano), dia 1 a 31.
    const string dataChegadaStr = "15/01/2026";
    ConsoleFormatter::MostrarSeparadorCategoria("2. Atribuicao de Data de Chegada Valida");

    smoke_teste.testarEntidade(
        InterfaceDeTeste::DEVE_DAR_CERTO,
        dataChegadaStr,
        "Reserva - Data Chegada",
        // Assume-se que o Domínio Data aceita a string (ex: 15/JAN/2026)
        [&reserva1, &dataChegadaStr]() { reserva1.setChegada(Data(dataChegadaStr)); }
    );

    // =========================================================================
    // 3. ATRIBUIÇÃO DE DATA (Partida)
    // =========================================================================
    // A data de Partida deve ser válida (e posterior à chegada, idealmente)
    const string dataPartidaStr = "20/01/2026";
    ConsoleFormatter::MostrarSeparadorCategoria("3. Atribuicao de Data da Partida Valida");

    smoke_teste.testarEntidade(
        InterfaceDeTeste::DEVE_DAR_CERTO,
        dataPartidaStr,
        "Reserva - Data Partida",
        [&reserva1, &dataPartidaStr]() { reserva1.setPartida(Data(dataPartidaStr)); }
    );

    // =========================================================================
    // 4. ATRIBUIÇÃO DE VALOR (DINHEIRO)
    // =========================================================================
    // Dinheiro é um valor inteiro (ex: 15000 representa R$150,00)
    int DinheiroInt = 75000;

    ConsoleFormatter::MostrarSeparadorCategoria("4. Atribuicao de Valor (Dinheiro) Valido");

    smoke_teste.testarEntidade(
        InterfaceDeTeste::DEVE_DAR_CERTO,
        to_string(DinheiroInt),
        "Reserva - Dinheiro",
        [&reserva1, &DinheiroInt]() { reserva1.setDinheiro(Dinheiro(DinheiroInt)); }
    );
}

//------------------------------------------------------------------------------------------------------------------