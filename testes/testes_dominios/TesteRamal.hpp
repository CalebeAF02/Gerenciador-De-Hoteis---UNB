//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSRAMAL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSRAMAL_H

#include "InterfaceDeTestes.hpp"
#include "Ramal.hpp"
#include <vector>
#include <string>
#include  "ConsoleIO.hpp"

class TesteRamal : public InterfaceDeTeste {
public:
    void executar() override;

    // Retorna o nome do grupo de testes.
    string nomeDoTeste() const override {
        return "Teste de Dominio: Ramal";
    }
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSRAMAL_H