#include "TestsNome.h"

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
    std::vector<std::string> nomes;
    nomes.push_back("João da Silva");
    nomes.push_back("Maria Clara");
    nomes.push_back("Carlos Eduardo");
    nomes.push_back("Ana Beatriz");
    nomes.push_back("Fernanda Lima");

    for (std::size_t i = 0; i < nomes.size(); ++i) {
        std::string nome = nomes[i];
        apresentacaoTeste(nome);
        try {
            Nome n(nome);
            checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
        }
    }
    std::cout << "\n";
}

void TestsNome::testarNomesInvalidos() {
    TextoApresentacao::MostrarTituloPergunta("Testando nomes com símbolos invalidos:");
    std::vector<std::string> nomes;
    nomes.push_back("J@o");
    nomes.push_back("Joao#Silva");
    nomes.push_back("Joao!");
    nomes.push_back("Joao..Silva");
    nomes.push_back("Joao--Silva");

    for (std::size_t i = 0; i < nomes.size(); ++i) {
        std::string nome = nomes[i];
        apresentacaoTeste(nome);
        try {
            Nome n(nome);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
    std::cout << "\n";
}

void TestsNome::testarNomesComNumeros() {
    TextoApresentacao::MostrarTituloPergunta("Testando nomes com números:");
    std::vector<std::string> nomes;
    nomes.push_back("Joao1");
    nomes.push_back("Maria 2 Clara");
    nomes.push_back("Carlos3Eduardo");
    nomes.push_back("Ana4 Beatriz");
    nomes.push_back("Fernanda5");

    for (std::size_t i = 0; i < nomes.size(); ++i) {
        std::string nome = nomes[i];
        apresentacaoTeste(nome);
        try {
            Nome n(nome);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
    std::cout << "\n";
}

void TestsNome::testarNomesMuitoLongos() {
    TextoApresentacao::MostrarTituloPergunta("Testando nomes muito longos:");
    std::vector<std::string> nomes;
    nomes.push_back("Joao da Silva Oliveira Lima Souza Andrade");
    nomes.push_back("Maria Clara de Albuquerque Ferreira Santos");
    nomes.push_back("Carlos Eduardo da Costa e Silva Junior");
    nomes.push_back("Ana Beatriz de Oliveira Lima Souza");
    nomes.push_back("Fernanda Lima de Souza Andrade Ferreira");

    for (std::size_t i = 0; i < nomes.size(); ++i) {
        std::string nome = nomes[i];
        apresentacaoTeste(nome);
        try {
            Nome n(nome);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
    std::cout << "\n";
}

void TestsNome::testarNomesSemMaiusculaInicial() {
    TextoApresentacao::MostrarTituloPergunta("Testando nomes sem maiúscula inicial:");
    std::vector<std::string> nomes;
    nomes.push_back("joao da Silva");
    nomes.push_back("maria Clara");
    nomes.push_back("carlos Eduardo");
    nomes.push_back("ana Beatriz");
    nomes.push_back("fernanda Lima");

    for (std::size_t i = 0; i < nomes.size(); ++i) {
        std::string nome = nomes[i];
        apresentacaoTeste(nome);
        try {
            Nome n(nome);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
    std::cout << "\n";
}

void TestsNome::testarNomesComEspacoInvalido() {
    TextoApresentacao::MostrarTituloPergunta("Testando nomes com espaços invalidos:");
    std::vector<std::string> nomes;
    nomes.push_back("Joao  da Silva");
    nomes.push_back("Maria   Clara");
    nomes.push_back("Carlos     Eduardo");
    nomes.push_back("Ana  Beatriz");
    nomes.push_back("Fernanda     Lima");

    for (std::size_t i = 0; i < nomes.size(); ++i) {
        std::string nome = nomes[i];
        apresentacaoTeste(nome);
        try {
            Nome n(nome);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
    std::cout << "\n";
}

void TestsNome::testarNomesComCaracteresEspeciais() {
    TextoApresentacao::MostrarTituloPergunta("Testando nomes com caracteres especiais:");
    std::vector<std::string> nomes;
    nomes.push_back("Joao@Silva");
    nomes.push_back("Maria#Clara");
    nomes.push_back("Carlos$Eduardo");
    nomes.push_back("Ana%Beatriz");
    nomes.push_back("Fernanda&Lima");

    for (std::size_t i = 0; i < nomes.size(); ++i) {
        std::string nome = nomes[i];
        apresentacaoTeste(nome);
        try {
            Nome n(nome);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
    std::cout << "\n";
}