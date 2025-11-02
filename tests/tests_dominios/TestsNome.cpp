#include "TestsNome.hpp"

void TestsNome::executar() {
    TextoApresentacao::MostrarTituloEmCaixa("Testes Dominio -> Nome");

    testarNomesValidos();
    testarNomesInvalidos();
    testarNomesComNumeros();
    testarNomesMuitoLongos();
    testarNomesSemMaiusculaInicial();
    testarNomesComEspacoInvalido();
    testarNomesComCaracteresEspeciais();
}

void TestsNome::testarNomesValidos() {
    TextoApresentacao::MostrarTituloPergunta("Testando nomes validos:");
    vector<string> nomes;
    nomes.push_back("João da Silva");
    nomes.push_back("Maria Clara");
    nomes.push_back("Carlos Eduardo");
    nomes.push_back("Ana Beatriz");
    nomes.push_back("Fernanda Lima");

    for (size_t i = 0; i < nomes.size(); ++i) {
        string nome = nomes[i];
        apresentacaoTeste(nome);
        try {
            Nome n(nome);
            checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
        }
    }
    cout << "\n";
}

void TestsNome::testarNomesInvalidos() {
    TextoApresentacao::MostrarTituloPergunta("Testando nomes com símbolos invalidos:");
    vector<string> nomes;
    nomes.push_back("J@o");
    nomes.push_back("Joao#Silva");
    nomes.push_back("Joao!");
    nomes.push_back("Joao..Silva");
    nomes.push_back("Joao--Silva");

    for (size_t i = 0; i < nomes.size(); ++i) {
        string nome = nomes[i];
        apresentacaoTeste(nome);
        try {
            Nome n(nome);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
    cout << "\n";
}

void TestsNome::testarNomesComNumeros() {
    TextoApresentacao::MostrarTituloPergunta("Testando nomes com números:");
    vector<string> nomes;
    nomes.push_back("Joao1");
    nomes.push_back("Maria 2 Clara");
    nomes.push_back("Carlos3Eduardo");
    nomes.push_back("Ana4 Beatriz");
    nomes.push_back("Fernanda5");

    for (size_t i = 0; i < nomes.size(); ++i) {
        string nome = nomes[i];
        apresentacaoTeste(nome);
        try {
            Nome n(nome);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
    cout << "\n";
}

void TestsNome::testarNomesMuitoLongos() {
    TextoApresentacao::MostrarTituloPergunta("Testando nomes muito longos:");
    vector<string> nomes;
    nomes.push_back("Joao da Silva Oliveira Lima Souza Andrade");
    nomes.push_back("Maria Clara de Albuquerque Ferreira Santos");
    nomes.push_back("Carlos Eduardo da Costa e Silva Junior");
    nomes.push_back("Ana Beatriz de Oliveira Lima Souza");
    nomes.push_back("Fernanda Lima de Souza Andrade Ferreira");

    for (size_t i = 0; i < nomes.size(); ++i) {
        string nome = nomes[i];
        apresentacaoTeste(nome);
        try {
            Nome n(nome);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
    cout << "\n";
}

void TestsNome::testarNomesSemMaiusculaInicial() {
    TextoApresentacao::MostrarTituloPergunta("Testando nomes sem maiúscula inicial:");
    vector<string> nomes;
    nomes.push_back("joao da Silva");
    nomes.push_back("maria Clara");
    nomes.push_back("carlos Eduardo");
    nomes.push_back("ana Beatriz");
    nomes.push_back("fernanda Lima");

    for (size_t i = 0; i < nomes.size(); ++i) {
        string nome = nomes[i];
        apresentacaoTeste(nome);
        try {
            Nome n(nome);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
    cout << "\n";
}

void TestsNome::testarNomesComEspacoInvalido() {
    TextoApresentacao::MostrarTituloPergunta("Testando nomes com espaços invalidos:");
    vector<string> nomes;
    nomes.push_back("Joao  da Silva");
    nomes.push_back("Maria   Clara");
    nomes.push_back("Carlos     Eduardo");
    nomes.push_back("Ana  Beatriz");
    nomes.push_back("Fernanda     Lima");

    for (size_t i = 0; i < nomes.size(); ++i) {
        string nome = nomes[i];
        apresentacaoTeste(nome);
        try {
            Nome n(nome);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
    cout << "\n";
}

void TestsNome::testarNomesComCaracteresEspeciais() {
    TextoApresentacao::MostrarTituloPergunta("Testando nomes com caracteres especiais:");
    vector<string> nomes;
    nomes.push_back("Joao@Silva");
    nomes.push_back("Maria#Clara");
    nomes.push_back("Carlos$Eduardo");
    nomes.push_back("Ana%Beatriz");
    nomes.push_back("Fernanda&Lima");

    for (size_t i = 0; i < nomes.size(); ++i) {
        string nome = nomes[i];
        apresentacaoTeste(nome);
        try {
            Nome n(nome);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
    cout << "\n";
}