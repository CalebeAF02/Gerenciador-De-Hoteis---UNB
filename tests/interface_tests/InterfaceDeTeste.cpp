#include "InterfaceDeTeste.hpp"

int InterfaceDeTeste::contTodalTestes = 0;
int InterfaceDeTeste::contTodalTestesOk = 0;
int InterfaceDeTeste::contTodalTestesProblema = 0;

std::vector<std::string> InterfaceDeTeste::listaFalhas;

//-----------------------------------------------------------------------------------------------------------
void InterfaceDeTeste::checaResultado(int esperando_resultado, int resultado_teste) {
    bool sucesso = (esperando_resultado == resultado_teste);

    // 1. Mostrar o resultado do caso (OK ou FALHA)
    cout << "\n | Resultado Esperado: ";

    if (esperando_resultado == DEVE_DAR_CERTO) {
        cout << "[SUCESSO]";
    } else {
        cout << "[FALHA]";
    }

    // 2. Mostrar o resultado da checagem
    if (sucesso) {
        // Se o que aconteceu é o que era esperado.
        cout << " -> OK\n" << endl;
        contTodalTestesOk += 1;
    } else {
        // Se o que aconteceu não é o que era esperado.
        cout << " -> PROBLEMA NA VALIDACAO!\n" << endl;
    }
}

//-----------------------------------------------------------------------------------------------------------
void InterfaceDeTeste::apresentacaoTeste(string valor) {
    cout << "  > Testando entrada: [" << valor << "]";
    contTodalTestes += 1;
}

void InterfaceDeTeste::apresentacaoTeste(int valor) {
    cout << "  > Testando entrada: [" << valor << "]";
    contTodalTestes += 1;
}

//-----------------------------------------------------------------------------------------------------------
// Simplesmente indica que a exceção não foi lançada, retornando o código de sucesso.
int InterfaceDeTeste::apresentacaoSucesso() {
    cout << "\n | Ocorreu: SUCESSO na Validacao";
    return DEVE_DAR_CERTO;
}

//-----------------------------------------------------------------------------------------------------------
// Mostra o erro da exceção e retorna o código de erro.
int InterfaceDeTeste::apresentacaoErro(invalid_argument erro) {
    cout << "\n | Ocorreu: ERRO (" << erro.what() << ")";
    return DEVE_DAR_ERRADO;
}

//-----------------------------------------------------------------------------------------------------------
// Mantendo a sobrecarga para erros genéricos (como o seu teste de string)
int InterfaceDeTeste::apresentacaoErro(string erro) {
    cout << "\n | Ocorreu: ERRO (" << erro << ")";
    return DEVE_DAR_ERRADO;
}

//-----------------------------------------------------------------------------------------------------------
void InterfaceDeTeste::registrarFalha(const std::string &dominio, const std::string &entrada, const std::string &erro) {
    std::string falha = "FALHA: " + dominio + " (Entrada: " + entrada + " | Erro: " + erro + ")";
    listaFalhas.push_back(falha);
}

void InterfaceDeTeste::setTestes(int contTodalTestes) {
    InterfaceDeTeste::contTodalTestes = contTodalTestes;
}

void InterfaceDeTeste::setTestesOk(int contTodalTestesOk) {
    InterfaceDeTeste::contTodalTestesOk = contTodalTestesOk;
}

void InterfaceDeTeste::setTestesProblema(int contTodalTestesProblema) {
    InterfaceDeTeste::contTodalTestesProblema = contTodalTestesProblema;
}

void InterfaceDeTeste::mostrarSumarioGeral() {
    cout << "\n=======================================================" << endl;
    cout << "                 RESUMO GERAL DOS TESTES                 " << endl;
    cout << "=======================================================" << endl;
    cout << "Total de Testes Executados: " << InterfaceDeTeste::getTestes() << endl;
    cout << "Resultados Corretos (OK):   " << InterfaceDeTeste::getTestesOk() << endl;
    cout << "Problemas de Validacao:     " << InterfaceDeTeste::getTestesProblema() << endl;

    cout << "-------------------------------------------------------" << endl; // Separador

    if (listaFalhas.empty()) {
        ConsoleIO::PrintMensagem("STATUS FINAL: SUCESSO EM TODOS OS TESTES UNITARIOS!");
    } else {
        // Exibe a mensagem de falha e os detalhes
        ConsoleIO::PrintMensagem(
            "STATUS FINAL: FALHA EM " + std::to_string(listaFalhas.size()) + " TESTES. REQUER REVISAO.");
        ConsoleFormatter::MostrarSeparadorCategoria("DETALHES DAS FALHAS");
        for (const auto &falha: listaFalhas) {
            ConsoleIO::PrintMensagem("  - " + falha);
        }
    }

    cout << "=======================================================" << endl;
}

//-------------------------------------------------------------------
int InterfaceDeTeste::getTestes() {
    return contTodalTestes;
}

int InterfaceDeTeste::getTestesOk() {
    return contTodalTestesOk;
}

int InterfaceDeTeste::getTestesProblema() {
    return contTodalTestesProblema;
}

//-----------------------------------------------------------------------------------------------------------