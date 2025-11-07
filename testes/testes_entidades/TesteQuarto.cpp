#include "TesteQuarto.hpp"
#include "SmokeTeste.hpp"
#include "sistema/entidades/Quarto.hpp"
#include "sistema/dominios/Numero.hpp"
#include "sistema/dominios/Capacidade.hpp"
#include "sistema/dominios/Dinheiro.hpp"
#include "ConsoleFormatter.hpp"

//------------------------------------------------------------------------------------------------------------------
void TesteQuarto::executar() {
    SmokeTeste smoke_teste;
    Quarto quarto1; // Instância da Entidade a ser testada

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE ENTIDADE: QUARTO (ATRIBUIÇÃO DE DOMÍNIOS)");

    // =========================================================================
    // 1. ATRIBUIÇÃO DE NÚMERO
    // =========================================================================
    const string numeroStr = "101"; // Número de quarto de exemplo (geralmente 3 dígitos)
    ConsoleFormatter::MostrarSeparadorCategoria("1. Atribuicao de Numero Valido");

    smoke_teste.testarEntidade(
            InterfaceDeTeste::DEVE_DAR_CERTO,
            numeroStr,
            "Quarto - Numero",
            [&quarto1, &numeroStr]() { quarto1.setNumero(Numero(numeroStr)); }
        );

    // =========================================================================
    // 2. ATRIBUIÇÃO DE CAPACIDADE
    // =========================================================================
    // Capacidade deve ser 1, 2, 3 ou 4.
    int capacidadeInt = 4;
    ConsoleFormatter::MostrarSeparadorCategoria("2. Atribuicao de Capacidade Valida");

    smoke_teste.testarEntidade(
            InterfaceDeTeste::DEVE_DAR_CERTO,
            to_string(capacidadeInt),
            "Quarto - Capacidade",
            [&quarto1, &capacidadeInt]() { quarto1.setCapacidade(Capacidade(capacidadeInt)); }
        );

    // =========================================================================
    // 3. ATRIBUIÇÃO DE DIÁRIA (DINHEIRO)
    // =========================================================================
    // Dinheiro é um valor inteiro (ex: 15000 representa R$150,00)
    int diariaInt = 25000;

    // NOTA: Para Dinheiro, geralmente se usa um tipo numérico (int), então o teste deve ser adaptado.
    ConsoleFormatter::MostrarSeparadorCategoria("3. Atribuicao de Diaria (Dinheiro) Valida");

    smoke_teste.testarEntidade(
            InterfaceDeTeste::DEVE_DAR_CERTO,
            to_string(diariaInt), // Converte para string apenas para o output do teste
            "Quarto - Dinheiro",
            [&quarto1, &diariaInt]() { quarto1.setDiaria(Dinheiro(diariaInt)); }
        );
    // =========================================================================
    // 4. ATRIBUIÇÃO DE RAMAL (Usando um valor válido de 2 dígitos)
    // =========================================================================
    // 🚨 Ramal deve ser 2 dígitos, 00-50. Corrigindo o valor de teste.
    const string ramalStr = "49";
    ConsoleFormatter::MostrarSeparadorCategoria("3. Atribuicao de Ramal Valido (00-50)");

    smoke_teste.testarEntidade(
            InterfaceDeTeste::DEVE_DAR_CERTO,
            ramalStr,
            "Quarto - Ramal",
            // O lambda tenta setar o Ramal no objeto gerente1
            [&quarto1, &ramalStr]() { quarto1.setRamal(Ramal(ramalStr)); }
        );

}
//------------------------------------------------------------------------------------------------------------------
