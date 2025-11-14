#include "SmokeTeste.hpp"

//-----------------------------------------------------------------------------------------------------------
void SmokeTeste::testarDominio(
    int esperando_resultado,
    const string &valor_teste,
    const string &dominio,
    function<void()> funcao_validacao
) {
    InterfaceDeTeste::apresentacaoTeste(valor_teste);
    int resultado_obtido_codigo;
    string erro_capturado = "";

    try {
        // EXECUTA O LAMBDA: Tenta criar/validar o objeto do Domínio
        funcao_validacao();
        resultado_obtido_codigo = InterfaceDeTeste::DEVE_DAR_CERTO;
    } catch (invalid_argument &erro) {
        // Se a exceção foi lançada, o Domínio FALHOU (o que pode ser o esperado)
        erro_capturado = erro.what();
        resultado_obtido_codigo = InterfaceDeTeste::DEVE_DAR_ERRADO;
    }

    // --- 1. IMPRIME O QUE OCORREU (EXCLUSIVAMENTE AQUI) ---
    // Faz a impressão da linha "Ocorreu" que você deseja
    if (resultado_obtido_codigo == InterfaceDeTeste::DEVE_DAR_CERTO) {
        IO::Println("\n | Ocorreu: SUCESSO na Validacao");
    } else {
        IO::Println("\n | Ocorreu: ERRO (" + erro_capturado + ")");
    }

    // --- 2. DELEGA A IMPRESSÃO DO RESULTADO E A CONTAGEM AO checaResultado ---
    // Agora checaResultado imprime '| Resultado Esperado: [...] -> OK/PROBLEMA' e faz a contagem.
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_obtido_codigo);

    // --- 3. REGISTRO DE FALHA LÓGICA ---
    bool sucesso_teste = (esperando_resultado == resultado_obtido_codigo);

    if (!sucesso_teste) {
        // Registra falha (a contagem de problemas já é feita dentro de checaResultado)
        InterfaceDeTeste::registrarFalha(dominio, valor_teste, erro_capturado);
    }
}

//-----------------------------------------------------------------------------------------------------------
void SmokeTeste::testarEntidade(
    int esperando_resultado,
    const string &valor_teste,
    const string &entidade,
    function<void()> funcao_validacao
) {
    InterfaceDeTeste::apresentacaoTeste(valor_teste);
    int resultado_obtido_codigo;
    string erro_capturado = "";

    try {
        // EXECUTA O LAMBDA: Tenta criar/validar o objeto do Domínio
        funcao_validacao();
        resultado_obtido_codigo = InterfaceDeTeste::DEVE_DAR_CERTO;
    } catch (invalid_argument &erro) {
        // Se a exceção foi lançada, o Domínio FALHOU (o que pode ser o esperado)
        erro_capturado = erro.what();
        resultado_obtido_codigo = InterfaceDeTeste::DEVE_DAR_ERRADO;
    }

    // --- 1. IMPRIME O QUE OCORREU (EXCLUSIVAMENTE AQUI) ---
    // Faz a impressão da linha "Ocorreu" que você deseja
    if (resultado_obtido_codigo == InterfaceDeTeste::DEVE_DAR_CERTO) {
        IO::Println("\n | Ocorreu: SUCESSO na Validacao");
    } else {
        IO::Println("\n | Ocorreu: ERRO (" + erro_capturado + ")");
    }

    // --- 2. DELEGA A IMPRESSÃO DO RESULTADO E A CONTAGEM AO checaResultado ---
    // Agora checaResultado imprime '| Resultado Esperado: [...] -> OK/PROBLEMA' e faz a contagem.
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_obtido_codigo);

    // --- 3. REGISTRO DE FALHA LÓGICA ---
    bool sucesso_teste = (esperando_resultado == resultado_obtido_codigo);

    if (!sucesso_teste) {
        // Registra falha (a contagem de problemas já é feita dentro de checaResultado)
        InterfaceDeTeste::registrarFalha(entidade, valor_teste, erro_capturado);
    }
};
//-----------------------------------------------------------------------------------------------------------