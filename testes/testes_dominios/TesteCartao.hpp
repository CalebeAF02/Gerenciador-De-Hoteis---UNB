//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCARTAO_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCARTAO_H

#include "Cartao.hpp"
#include <vector>
#include <string>

#include "InterfaceDeTestes.hpp"
#include  "ConsoleIO.hpp"

class TesteCartao : public InterfaceDeTeste {
public:
    void executar() override;

    // Retorna o nome do grupo de testes.
    string nomeDoTeste() const override {
        return "Teste de Dominio: Cartao";
    }
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCARTAO_H