// NO SEU TestsNome.cpp (Versão Final e Genérica)

#include "TesteNome.hpp"
#include "SmokeTeste.hpp"
#include "sistema/dominios/Nome.hpp" // A classe que será testada
#include "Formato.hpp"
#include <vector>

//------------------------------------------------------------------------------------------------------------------
using namespace std;

void TesteNome::executar() {
    SmokeTeste smoke_teste;

    Formato::TituloEmCaixa("TESTES DE DOMINIO: NOME");

    // =========================================================================
    // 1. CASOS INVÁLIDOS (DEVE_DAR_ERRADO)
    // =========================================================================
    Formato::SeparadorDeCategoria("1. Casos de Invalidade (Tamanho, Símbolo, Espaço, Inicial)");

    vector<string> nomesInvalidos = {
        // Tamanho
        "", "Cb", "Calebe Alves Freitas Madeira Alves",
        // Espaço e Pontuação
        "Calebe  Alves", "Calebe Alves ", "Calebe@alves", "Joao#Silva",
        // Inicial e Minúscula
        "calebe alves", "Maria 2 Clara"
    };

    for (const string &nome: nomesInvalidos) {
        //CHAMA A FUNÇÃO GENÉRICA (usando um lambda para executar a validação)
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_ERRADO,
            string(nome),
            "Nome", // Nome do domínio para o registro de falha
            [&nome]() { Nome n(nome); } // <--- A MÁGICA: O que for colocado aqui será testado
        );
    }

    // =========================================================================
    // 2. CASOS VÁLIDOS (DEVE_DAR_CERTO)
    // =========================================================================
    Formato::SeparadorDeCategoria("2. Casos de Validade");

    vector<string> nomesValidos = {
        "Joao Da Silva", "Maria Clara", "Carlos Eduardo"
    };

    for (const string &nome: nomesValidos) {
        //CHAMA A FUNÇÃO GENÉRICA
        smoke_teste.testarDominio(
            InterfaceDeTeste::DEVE_DAR_CERTO,
            string(nome),
            "Nome",
            [&nome]() { Nome n(nome); } // <--- Tenta criar o Nome
        );
    }
}

//------------------------------------------------------------------------------------------------------------------