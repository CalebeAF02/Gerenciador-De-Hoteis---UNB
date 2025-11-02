#include "TestsEmail.hpp"
#include <iostream>
#include <vector>

void TestsEmail::executar() {
    testarEmailsValidos();
    testarEmailsInvalidosFormato();
    testarEmailsComCaracteresInvalidos();
    testarEmailsComParteLocalInvalida();
    testarEmailsComDominioInvalido();
    testarEmailsMuitoLongos();
}

void TestsEmail::testarEmailsValidos() {
    vector<string> emails;
    emails.push_back("joao.silva@empresa.com");
    emails.push_back("maria-clara@ufc.br");
    emails.push_back("user123@dominio.net");
    emails.push_back("a.b-c@sub.dominio.org");
    emails.push_back("nome@site.com.br");

    for (size_t i = 0; i < emails.size(); ++i) {
        string email = emails[i];
        apresentacaoTeste(email);
        try {
            Email e(email);
            checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
        } catch (invalid_argument &ex) {
            checaResultado(DEVE_DAR_CERTO, apresentacaoErro(ex));
        }
    }
}

void TestsEmail::testarEmailsInvalidosFormato() {
    vector<string> emails;
    emails.push_back("joao.silvaempresa.com");
    emails.push_back("joao@.com");
    emails.push_back("@empresa.com");
    emails.push_back("joao@");
    emails.push_back("joao@empresa");

    for (size_t i = 0; i < emails.size(); ++i) {
        string email = emails[i];
        apresentacaoTeste(email);
        try {
            Email e(email);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &ex) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(ex));
        }
    }
}

void TestsEmail::testarEmailsComCaracteresInvalidos() {
    vector<string> emails;
    emails.push_back("joao!@empresa.com");
    emails.push_back("maria#clara@ufc.br");
    emails.push_back("user$123@dominio.net");
    emails.push_back("a%bc@sub.dominio.org");

    for (size_t i = 0; i < emails.size(); ++i) {
        string email = emails[i];
        apresentacaoTeste(email);
        try {
            Email e(email);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &ex) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(ex));
        }
    }
}

void TestsEmail::testarEmailsComParteLocalInvalida() {
    vector<string> emails;
    emails.push_back(".joao@empresa.com");
    emails.push_back("joao.@empresa.com");
    emails.push_back("-maria@ufc.br");
    emails.push_back("maria-@ufc.br");
    emails.push_back("joao..silva@empresa.com");

    for (size_t i = 0; i < emails.size(); ++i) {
        string email = emails[i];
        apresentacaoTeste(email);
        try {
            Email e(email);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &ex) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(ex));
        }
    }
}

void TestsEmail::testarEmailsComDominioInvalido() {
    vector<string> emails;
    emails.push_back("joao@-empresa.com");
    emails.push_back("joao@empresa-.com");
    emails.push_back("joao@empresa..com");
    emails.push_back("joao@empresa@com");
    emails.push_back("joao@.com.br");

    for (size_t i = 0; i < emails.size(); ++i) {
        string email = emails[i];
        apresentacaoTeste(email);
        try {
            Email e(email);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &ex) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(ex));
        }
    }
}

void TestsEmail::testarEmailsMuitoLongos() {
    string parteLocal = string(65, 'a');
    string dominio = string(256, 'b');

    vector<string> emails;
    emails.push_back(parteLocal + "@empresa.com");
    emails.push_back("joao@" + dominio + ".com");

    for (size_t i = 0; i < emails.size(); ++i) {
        string email = emails[i];
        apresentacaoTeste(email);
        try {
            Email e(email);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (invalid_argument &ex) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(ex));
        }
    }
}