#include "TesteGerente.hpp"
#include "SmokeTeste.hpp"

//------------------------------------------------------------------------------------------------------------------
void TesteGerente::executar() {
    SmokeTeste smoke_teste;
    Gerente gerente1; // Instância da Entidade a ser testada

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE ENTIDADE: GERENTE (ATRIBUICAO DE DOMINIOS)");

    // =========================================================================
    // 1. ATRIBUIÇÃO DE NOME
    // =========================================================================
    const string nomeStr = "Calebe Alves";
    ConsoleFormatter::MostrarSeparadorCategoria("1. Atribuicao de Nome Valido");

    // O LAMBDA agora testa se o metodo da ENTIDADE (setNome) aceita o Domínio.
    smoke_teste.testarEntidade(
        InterfaceDeTeste::DEVE_DAR_CERTO, // Espera sucesso
        nomeStr,
        "Gerente - Nome", // Indica que a falha é no Gerente (integração)
        // O lambda tenta setar o Nome no objeto gerente1
        [&gerente1, &nomeStr]() { gerente1.setNome(Nome(nomeStr)); }
    );

    // =========================================================================
    // 2. ATRIBUIÇÃO DE EMAIL
    // =========================================================================
    const string emailStr = "adm.123@gmail.com";
    ConsoleFormatter::MostrarSeparadorCategoria("2. Atribuicao de Email Valido");

    smoke_teste.testarEntidade(
        InterfaceDeTeste::DEVE_DAR_CERTO,
        emailStr,
        "Gerente - Email",
        // O lambda tenta setar o Email no objeto gerente1
        [&gerente1, &emailStr]() { gerente1.setEmail(Email(emailStr)); }
    );

    // ... CONTINUE ASSIM PARA RAMAL E SENHA ...

    // =========================================================================
    // 3. ATRIBUIÇÃO DE RAMAL (Usando um valor válido de 2 dígitos)
    // =========================================================================
    // 🚨 Ramal deve ser 2 dígitos, 00-50. Corrigindo o valor de teste.
    const string ramalStr = "49";
    ConsoleFormatter::MostrarSeparadorCategoria("3. Atribuicao de Ramal Valido (00-50)");

    smoke_teste.testarEntidade(
        InterfaceDeTeste::DEVE_DAR_CERTO,
        ramalStr,
        "Gerente - Ramal",
        // O lambda tenta setar o Ramal no objeto gerente1
        [&gerente1, &ramalStr]() { gerente1.setRamal(Ramal(ramalStr)); }
    );

    // =========================================================================
    // 4. ATRIBUIÇÃO DE SENHA
    // =========================================================================
    const string senhaStr = "A1!b2";
    ConsoleFormatter::MostrarSeparadorCategoria("4. Atribuicao de Senha Valida");

    smoke_teste.testarEntidade(
        InterfaceDeTeste::DEVE_DAR_CERTO,
        senhaStr,
        "Gerente - Senha",
        // O lambda tenta setar a Senha no objeto gerente1
        [&gerente1, &senhaStr]() { gerente1.setSenha(Senha(senhaStr)); }
    );
}

//------------------------------------------------------------------------------------------------------------------