#include "TestsEndereco.hpp"
#include <iostream>
#include <vector>

void TestsEndereco::executar() {
    testarEnderecosValidos();
    testarEnderecosComCaracteresInvalidos();
    testarEnderecosComInicioOuFimInvalido();
    testarEnderecosMuitoLongos();
}

void TestsEndereco::testarEnderecosValidos() {
    std::vector<std::string> enderecos;
    enderecos.push_back("Rua das Flores, 123");
    enderecos.push_back("Av. Brasil - Bloco A");
    enderecos.push_back("Praca Central 45");
    enderecos.push_back("Rua Joao Goulart, 789");
    enderecos.push_back("Alameda dos Anjos - Casa 10");

    for (std::size_t i = 0; i < enderecos.size(); ++i) {
        std::string endereco = enderecos[i];
        apresentacaoTeste(endereco);
        try {
            Endereco e(endereco);
            checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
        } catch (std::invalid_argument &ex) {
            checaResultado(DEVE_DAR_CERTO, apresentacaoErro(ex));
        }
    }
}

void TestsEndereco::testarEnderecosComCaracteresInvalidos() {
    std::vector<std::string> enderecos;
    enderecos.push_back("Rua das Flores @ 123");
    enderecos.push_back("Av. Brasil # Bloco A");
    enderecos.push_back("Praca Central * 45");
    enderecos.push_back("Rua Joao Goulart ! 789");

    for (std::size_t i = 0; i < enderecos.size(); ++i) {
        std::string endereco = enderecos[i];
        apresentacaoTeste(endereco);
        try {
            Endereco e(endereco);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &ex) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(ex));
        }
    }
}

void TestsEndereco::testarEnderecosComInicioOuFimInvalido() {
    std::vector<std::string> enderecos;
    enderecos.push_back(".Rua das Flores");
    enderecos.push_back("Rua das Flores.");
    enderecos.push_back("-Av. Brasil");
    enderecos.push_back("Praca Central-");

    for (std::size_t i = 0; i < enderecos.size(); ++i) {
        std::string endereco = enderecos[i];
        apresentacaoTeste(endereco);
        try {
            Endereco e(endereco);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &ex) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(ex));
        }
    }
}

void TestsEndereco::testarEnderecosMuitoLongos() {
    std::vector<std::string> enderecos;
    enderecos.push_back(std::string(101, 'A'));
    enderecos.push_back("Rua " + std::string(97, 'B'));

    for (std::size_t i = 0; i < enderecos.size(); ++i) {
        std::string endereco = enderecos[i];
        apresentacaoTeste(endereco);
        try {
            Endereco e(endereco);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &ex) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(ex));
        }
    }
}