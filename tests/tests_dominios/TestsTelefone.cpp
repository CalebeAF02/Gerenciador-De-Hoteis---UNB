#include "TestsTelefone.h"
#include <iostream>
#include <vector>

void TestsTelefone::executar() {
    testarTelefonesValidos();
    testarTelefonesComFormatoInvalido();
    testarTelefonesComPrefixoInvalido();
    testarTelefonesComCaracteresInvalidos();
    testarTelefonesComDigitosInvalidos();
}

void TestsTelefone::testarTelefonesValidos() {
    std::vector<std::string> telefones;
    telefones.push_back("(61) 91234-5678");
    telefones.push_back("(11) 98765-4321");
    telefones.push_back("(85) 99999-0000");
    telefones.push_back("(21) 95555-1234");
    telefones.push_back("(31) 99888-7777");

    for (std::size_t i = 0; i < telefones.size(); ++i) {
        std::string telefone = telefones[i];
        apresentacaoTeste(telefone);
        try {
            Telefone t(telefone);
            checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
        }
    }
}

void TestsTelefone::testarTelefonesComFormatoInvalido() {
    std::vector<std::string> telefones;
    telefones.push_back("61 91234-5678");
    telefones.push_back("(61)91234-5678");
    telefones.push_back("(61)-91234-5678");
    telefones.push_back("(61912345678)");
    telefones.push_back("(61) 912345678");

    for (std::size_t i = 0; i < telefones.size(); ++i) {
        std::string telefone = telefones[i];
        apresentacaoTeste(telefone);
        try {
            Telefone t(telefone);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsTelefone::testarTelefonesComPrefixoInvalido() {
    std::vector<std::string> telefones;
    telefones.push_back("(61) 01234-5678");
    telefones.push_back("(11) 12345-6789");
    telefones.push_back("(85) 03456-7890");
    telefones.push_back("(21) 00000-1234");
    telefones.push_back("(31) 04567-8901");

    for (std::size_t i = 0; i < telefones.size(); ++i) {
        std::string telefone = telefones[i];
        apresentacaoTeste(telefone);
        try {
            Telefone t(telefone);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsTelefone::testarTelefonesComCaracteresInvalidos() {
    std::vector<std::string> telefones;
    telefones.push_back("(61) 91234@5678");
    telefones.push_back("(11) 98765#4321");
    telefones.push_back("(85) 99999*0000");
    telefones.push_back("(21) 95555!1234");

    for (std::size_t i = 0; i < telefones.size(); ++i) {
        std::string telefone = telefones[i];
        apresentacaoTeste(telefone);
        try {
            Telefone t(telefone);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsTelefone::testarTelefonesComDigitosInvalidos() {
    std::vector<std::string> telefones;
    telefones.push_back("(61) 91234-567");
    telefones.push_back("(11) 987654-3210");
    telefones.push_back("(85) 9999-0000");
    telefones.push_back("(21) 9555-1234");

    for (std::size_t i = 0; i < telefones.size(); ++i) {
        std::string telefone = telefones[i];
        apresentacaoTeste(telefone);
        try {
            Telefone t(telefone);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}