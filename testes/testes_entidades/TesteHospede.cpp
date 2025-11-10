#include "TesteHospede.hpp"
#include "SmokeTeste.hpp"
#include "sistema/entidades/Hospede.hpp" // Sua entidade Hospede
#include "Formato.hpp"

//------------------------------------------------------------------------------------------------------------------
void TesteHospede::executar() {
    SmokeTeste smoke_teste;
    Hospede hospede1; // Instância da Entidade a ser testada

    Formato::TituloEmCaixa("TESTES DE ENTIDADE: HOSPEDE (ATRIBUICAO DE DOMINIOS)");

    // =========================================================================
    // 1. ATRIBUIÇÃO DE NOME (Herdado de Pessoa)
    // =========================================================================
    const string nomeStr = "Maria Eduarda";
    Formato::SeparadorDeCategoria("1. Atribuicao de Nome Valido");

    // Testa se o metodo setNome da Entidade aceita o Domínio Nome válido
    smoke_teste.testarEntidade(
        InterfaceDeTeste::DEVE_DAR_CERTO,
        nomeStr,
        "Hospede - Nome",
        [&hospede1, &nomeStr]() { hospede1.setNome(Nome(nomeStr)); }
    );

    // =========================================================================
    // 2. ATRIBUIÇÃO DE EMAIL (Herdado de Pessoa)
    // =========================================================================
    const string emailStr = "maria.eduarda@hospede.com";
    Formato::SeparadorDeCategoria("2. Atribuicao de Email Valido");

    // Testa se o metodo setEmail da Entidade aceita o Domínio Email válido
    smoke_teste.testarEntidade(
        InterfaceDeTeste::DEVE_DAR_CERTO,
        emailStr,
        "Hospede - Email",
        [&hospede1, &emailStr]() { hospede1.setEmail(Email(emailStr)); }
    );

    // =========================================================================
    // 3. ATRIBUIÇÃO DE ENDEREÇO
    // =========================================================================
    const string enderecoStr = "SHIS QI 01 Bloco A Casa 10"; // Endereço de exemplo
    Formato::SeparadorDeCategoria("3. Atribuicao de Endereco Valido");

    // Testa se o metodo setEndereco da Entidade aceita o Domínio Endereco válido
    smoke_teste.testarEntidade(
        InterfaceDeTeste::DEVE_DAR_CERTO,
        enderecoStr,
        "Hospede - Endereco",
        [&hospede1, &enderecoStr]() { hospede1.setEndereco(Endereco(enderecoStr)); }
    );

    // =========================================================================
    // 4. ATRIBUIÇÃO DE CARTÃO
    // =========================================================================
    // Cartão deve ter 16 dígitos e passar no algoritmo de Luhn
    const string cartaoStr = "4992739871625945"; // Exemplo de um número de 16 dígitos válido (Luhn)
    Formato::SeparadorDeCategoria("4. Atribuicao de Cartao Valido");

    // Testa se o metodo setCartao da Entidade aceita o Domínio Cartao válido
    smoke_teste.testarEntidade(
        InterfaceDeTeste::DEVE_DAR_CERTO,
        cartaoStr,
        "Hospede - Cartao",
        [&hospede1, &cartaoStr]() { hospede1.setCartao(Cartao(cartaoStr)); }
    );
}

//------------------------------------------------------------------------------------------------------------------