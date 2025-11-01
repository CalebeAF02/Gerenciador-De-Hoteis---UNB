#include "TestsSenha.h"
#include <iostream>
#include <vector>

void TestsSenha::executar() {
    testarSenhasValidas();
    testarSenhasMuitoCurtas();
    testarSenhasSemMaiuscula();
    testarSenhasSemMinuscula();
    testarSenhasSemDigito();
    testarSenhasSemEspecial();
    testarSenhasComSequenciaDeLetras();
    testarSenhasComSequenciaDeDigitos();
}

void TestsSenha::testarSenhasValidas() {
    std::vector<std::string> senhas = {
        "a1#Bz", // minúscula, dígito, especial, maiúscula, sem sequência inválida
        "B2$a", // maiúscula, dígito, especial, minúscula
        "c3%D" // minúscula, dígito, especial, maiúscula
    };

    for (const std::string &senha: senhas) {
        apresentacaoTeste(senha);
        try {
            Senha s(senha);
            checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
        }
    }
}

void TestsSenha::testarSenhasMuitoCurtas() {
    std::vector<std::string> senhas = {
        "a1#B", // 4 caracteres
        "A1$", // 3 caracteres
        "b2#", // 3 caracteres
        "C3@" // 3 caracteres
    };

    for (const std::string &senha: senhas) {
        apresentacaoTeste(senha);
        try {
            Senha s(senha);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsSenha::testarSenhasSemMaiuscula() {
    std::vector<std::string> senhas = {
        "a1#bz",
        "c2@xy",
        "m3%no"
    };

    for (const std::string &senha: senhas) {
        apresentacaoTeste(senha);
        try {
            Senha s(senha);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsSenha::testarSenhasSemMinuscula() {
    std::vector<std::string> senhas = {
        "A1#BZ",
        "C2@XY",
        "M3%NO"
    };

    for (const std::string &senha: senhas) {
        apresentacaoTeste(senha);
        try {
            Senha s(senha);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsSenha::testarSenhasSemDigito() {
    std::vector<std::string> senhas = {
        "a#BZx",
        "C@XYz",
        "M%NOa"
    };

    for (const std::string &senha: senhas) {
        apresentacaoTeste(senha);
        try {
            Senha s(senha);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsSenha::testarSenhasSemEspecial() {
    std::vector<std::string> senhas = {
        "a1BZx",
        "C2XYz",
        "M3NOa"
    };

    for (const std::string &senha: senhas) {
        apresentacaoTeste(senha);
        try {
            Senha s(senha);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsSenha::testarSenhasComSequenciaDeLetras() {
    std::vector<std::string> senhas = {
        "aB#c1", // letras seguidas
        "xY@z2"
    };

    for (const std::string &senha: senhas) {
        apresentacaoTeste(senha);
        try {
            Senha s(senha);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsSenha::testarSenhasComSequenciaDeDigitos() {
    std::vector<std::string> senhas = {
        "a12#B", // dígitos seguidos
        "C34@d"
    };

    for (const std::string &senha: senhas) {
        apresentacaoTeste(senha);
        try {
            Senha s(senha);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}