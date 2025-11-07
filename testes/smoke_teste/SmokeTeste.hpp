#ifndef SMOKE_TESTS_HPP
#define SMOKE_TESTS_HPP

#include "InterfaceDeTestes.hpp"
#include <string>
#include <functional> // Necessário para function
#include <iostream>   // Necessário se você usar cout/cin, mas geralmente já é incluído por ConsoleFormatter
#include <stdexcept>  // Necessário para invalid_argument

class SmokeTeste {
public:
    // =========================================================================
    // 1. TESTAR DOMÍNIO (União da lógica try/catch com output para Domínios)
    // =========================================================================

    // Versão 1 (String): Recebe o valor_teste como string (Implementação no .cpp)
    void testarDominio(
        int esperando_resultado,
        const string &valor_teste,
        const string &dominio,
        function<void()> funcao_validacao
    );

    // Versão 2 (Template): Recebe o valor_teste como Template T (para int, float, etc.)
    template<typename T>
    void testarDominio(
        int esperando_resultado,
        const T &valor_teste, // Agora aceita qualquer tipo (int, float, etc.)
        const string &dominio,
        function<void()> funcao_validacao
    );


    // =========================================================================
    // 2. TESTAR ENTIDADE (União da lógica try/catch com output para Entidades)
    // =========================================================================

    // Versão 1 (String): Recebe o valor_teste como string (Implementação no .cpp)
    void testarEntidade(
        int esperando_resultado,
        const string &valor_teste,
        const string &entidade,
        function<void()> funcao_validacao
    );

    // Versão 2 (Template): Recebe o valor_teste como Template T (para int, float, etc.)
    template<typename T>
    void testarEntidade(
        int esperando_resultado,
        const T &valor_teste, // Agora aceita qualquer tipo (int, float, etc.)
        const string &entidade,
        function<void()> funcao_validacao
    );
};

template<typename T>
void SmokeTeste::testarDominio(
    int esperando_resultado,
    const T &valor_teste,
    const string &dominio,
    function<void()> funcao_validacao
) {
    // Converte o tipo T (int, float, etc.) para string e chama a versão string.
    this->testarDominio(
        esperando_resultado,
        string(valor_teste), // Conversão para string
        dominio,
        funcao_validacao
    );
}

template<typename T>
void SmokeTeste::testarEntidade(
    int esperando_resultado,
    const T &valor_teste,
    const string &entidade,
    function<void()> funcao_validacao
) {
    // Converte o tipo T (int, float, etc.) para string e chama a versão string.
    this->testarEntidade(
        esperando_resultado,
        string(valor_teste), // Conversão para string
        entidade,
        funcao_validacao
    );
}

#endif // SMOKE_TESTS_HPP