//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCAPACIDADE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCAPACIDADE_H

#include "Capacidade.hpp"
#include <vector>

#include "InterfaceDeTestes.hpp"
#include  "ConsoleIO.hpp"

using namespace std;

class TesteCapacidade : public InterfaceDeTeste {
public:
    void executar() override;

    // Retorna o nome do grupo de testes.
    string nomeDoTeste() const override {
        return "Teste de Dominio: Capacidade";
    }
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCAPACIDADE_H