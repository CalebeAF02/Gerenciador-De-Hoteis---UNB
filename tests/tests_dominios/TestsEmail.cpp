#include "TestsEmail.h"
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
    std::vector<std::string> emails;
    emails.push_back("joao.silva@empresa.com");
    emails.push_back("maria-clara@ufc.br");
    emails.push_back("user123@dominio.net");
    emails.push_back("a.b-c@sub.dominio.org");
    emails.push_back("nome@site.com.br");

    for (std::size_t i = 0; i < emails.size(); ++i) {
        std::string email = emails[i];
        apresentacaoTeste(email);
        try {
            Email e(email);
            checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
        } catch (std::invalid_argument &ex) {
            checaResultado(DEVE_DAR_CERTO, apresentacaoErro(ex));
        }
    }
}

void TestsEmail::testarEmailsInvalidosFormato() {
    std::vector<std::string> emails;
    emails.push_back("joao.silvaempresa.com");
    emails.push_back("joao@.com");
    emails.push_back("@empresa.com");
    emails.push_back("joao@");
    emails.push_back("joao@empresa");

    for (std::size_t i = 0; i < emails.size(); ++i) {
        std::string email = emails[i];
        apresentacaoTeste(email);
        try {
            Email e(email);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &ex) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(ex));
        }
    }
}

void TestsEmail::testarEmailsComCaracteresInvalidos() {
    std::vector<std::string> emails;
    emails.push_back("joao!@empresa.com");
    emails.push_back("maria#clara@ufc.br");
    emails.push_back("user$123@dominio.net");
    emails.push_back("a%bc@sub.dominio.org");

    for (std::size_t i = 0; i < emails.size(); ++i) {
        std::string email = emails[i];
        apresentacaoTeste(email);
        try {
            Email e(email);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &ex) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(ex));
        }
    }
}

void TestsEmail::testarEmailsComParteLocalInvalida() {
    std::vector<std::string> emails;
    emails.push_back(".joao@empresa.com");
    emails.push_back("joao.@empresa.com");
    emails.push_back("-maria@ufc.br");
    emails.push_back("maria-@ufc.br");
    emails.push_back("joao..silva@empresa.com");

    for (std::size_t i = 0; i < emails.size(); ++i) {
        std::string email = emails[i];
        apresentacaoTeste(email);
        try {
            Email e(email);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &ex) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(ex));
        }
    }
}

void TestsEmail::testarEmailsComDominioInvalido() {
    std::vector<std::string> emails;
    emails.push_back("joao@-empresa.com");
    emails.push_back("joao@empresa-.com");
    emails.push_back("joao@empresa..com");
    emails.push_back("joao@empresa@com");
    emails.push_back("joao@.com.br");

    for (std::size_t i = 0; i < emails.size(); ++i) {
        std::string email = emails[i];
        apresentacaoTeste(email);
        try {
            Email e(email);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &ex) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(ex));
        }
    }
}

void TestsEmail::testarEmailsMuitoLongos() {
    std::string parteLocal = std::string(65, 'a');
    std::string dominio = std::string(256, 'b');

    std::vector<std::string> emails;
    emails.push_back(parteLocal + "@empresa.com");
    emails.push_back("joao@" + dominio + ".com");

    for (std::size_t i = 0; i < emails.size(); ++i) {
        std::string email = emails[i];
        apresentacaoTeste(email);
        try {
            Email e(email);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &ex) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(ex));
        }
    }
}