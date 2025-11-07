//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSDINHEIRO_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSDINHEIRO_H

#include "Dinheiro.hpp"
#include <vector>

#include "InterfaceDeTestes.hpp"
#include  "ConsoleIO.hpp"

class TesteDinheiro : public InterfaceDeTeste {
public:
    void executar() override;

    // Retorna o nome do grupo de testes.
    string nomeDoTeste() const override {
        return "Teste de Dominio: Dinheiro";
    }
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSDINHEIRO_H