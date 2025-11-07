//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSEMAIL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSEMAIL_H

#include "Email.hpp"
#include <vector>
#include <string>

#include "InterfaceDeTestes.hpp"
#include  "ConsoleIO.hpp"

class TesteEmail : public InterfaceDeTeste {
public:
    void executar() override;

    // Retorna o nome do grupo de testes.
    string nomeDoTeste() const override {
        return "Teste de Dominio: Email";
    }
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSEMAIL_H