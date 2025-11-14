#include "InterfaceDeTestes.hpp"

int InterfaceDeTeste::contTodalTestes = 0;
int InterfaceDeTeste::contTodalTestesOk = 0;
int InterfaceDeTeste::contTodalTestesProblema = 0;

vector<string> InterfaceDeTeste::listaFalhas;

//-----------------------------------------------------------------------------------------------------------
void InterfaceDeTeste::checaResultado(int esperando_resultado, int resultado_teste) {
    bool sucesso = (esperando_resultado == resultado_teste);

    // 1. Mostrar o resultado do caso (OK ou FALHA)
    cout << " | Resultado Esperado: ";

    if (esperando_resultado == DEVE_DAR_CERTO) {
        cout << "[SUCESSO]";
    } else {
        cout << "[FALHA]";
    }

    // 2. Mostrar o resultado da checagem
    if (sucesso) {
        // Se o que aconteceu é o que era esperado.
        cout << " -> OK (Tudo Certo)!\n" << endl;
        contTodalTestesOk++;
    } else {
        // Se o que aconteceu não é o que era esperado.
        cout << " -> Erro: (PROBLEMA NA VALIDACAO)!\n" << endl;
        contTodalTestesProblema++;
    }
}

//-----------------------------------------------------------------------------------------------------------
void InterfaceDeTeste::apresentacaoTeste(const string &valor) {
    cout << " > Testando entrada: [" << valor << "]";
    contTodalTestes++;
}

void InterfaceDeTeste::apresentacaoTeste(const int &valor) {
    cout << " > Testando entrada: [" << valor << "]";
    contTodalTestes++;
}

//-----------------------------------------------------------------------------------------------------------
void InterfaceDeTeste::registrarFalha(const string &dominio, const string &entrada, const string &erro) {
    string falha = "FALHA: " + dominio + " (Entrada: " + entrada + " | Erro: " + erro + ")";
    listaFalhas.push_back(falha);
}

//-----------------------------------------------------------------------------------------------------------
void InterfaceDeTeste::mostrarRelatorioDeTestes() {
    Formato::TituloEmCaixa("RESUMO GERAL DOS TESTES");
    IO::Println(" > Total de Testes Executados: " + getTestes());
    IO::Println(" > Resultados Corretos (OK):   " + getTestesOk());
    IO::Println(" > Problemas de Validacao:     " + getTestesProblema());
    cout << "----------------------------------------------------------------------" << endl; // Separador
    if (listaFalhas.empty()) {
        IO::Println("STATUS FINAL: SUCESSO EM TODOS OS TESTES UNITARIOS!");
    } else {
        // Exibe a mensagem de falha e os detalhes
        IO::Println(
            "STATUS FINAL: FALHA EM " + to_string(listaFalhas.size()) + " TESTES. REQUER REVISAO.");

        Formato::SeparadorDeCategoria("DETALHES DAS FALHAS");

        for (const auto &falha: listaFalhas) {
            IO::Println("  - " + falha);
        }
    }
    cout << "======================================================================" << endl;
}

//-----------------------------------------------------------------------------------------------------------