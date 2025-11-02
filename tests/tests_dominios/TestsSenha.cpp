#include "TestsSenha.hpp"
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
    vector<string> senhas = {
        "a1#Bz", // minúscula, dígito, especial, maiúscula, sem sequência inválida
        "B2$a", // maiúscula, dígito, especial, minúscula
        "c3%D" // minúscula, dígito, especial, maiúscula
    };

    for (const string &senha: senhas) {
        apresentacaoTeste(senha);
        try {
            Senha s(senha);
            checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
        }
    }
}

void TestsSenha::testarSenhasMuitoCurtas() {
    vector<string> senhas = {
        "a1#B", // 4 caracteres
        "A1$", // 3 caracteres
        "b2#", // 3 caracteres
        "C3@" // 3 caracteres
    };

    for (const string &senha: senhas) {
        apresentacaoTeste(senha);
        try {
            Senha s(senha);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsSenha::testarSenhasSemMaiuscula() {
    vector<string> senhas = {
        "a1#bz",
        "c2@xy",
        "m3%no"
    };

    for (const string &senha: senhas) {
        apresentacaoTeste(senha);
        try {
            Senha s(senha);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsSenha::testarSenhasSemMinuscula() {
    vector<string> senhas = {
        "A1#BZ",
        "C2@XY",
        "M3%NO"
    };

    for (const string &senha: senhas) {
        apresentacaoTeste(senha);
        try {
            Senha s(senha);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsSenha::testarSenhasSemDigito() {
    vector<string> senhas = {
        "a#BZx",
        "C@XYz",
        "M%NOa"
    };

    for (const string &senha: senhas) {
        apresentacaoTeste(senha);
        try {
            Senha s(senha);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsSenha::testarSenhasSemEspecial() {
    vector<string> senhas = {
        "a1BZx",
        "C2XYz",
        "M3NOa"
    };

    for (const string &senha: senhas) {
        apresentacaoTeste(senha);
        try {
            Senha s(senha);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsSenha::testarSenhasComSequenciaDeLetras() {
    vector<string> senhas = {
        "aB#c1", // letras seguidas
        "xY@z2"
    };

    for (const string &senha: senhas) {
        apresentacaoTeste(senha);
        try {
            Senha s(senha);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsSenha::testarSenhasComSequenciaDeDigitos() {
    vector<string> senhas = {
        "a12#B", // dígitos seguidos
        "C34@d"
    };

    for (const string &senha: senhas) {
        apresentacaoTeste(senha);
        try {
            Senha s(senha);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}