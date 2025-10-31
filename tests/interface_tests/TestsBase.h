//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSBASE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSBASE_H

#include <iostream>
#include <string>

class TestsBase
{
public:
    virtual void executar() = 0; // Metodo obrigatorio
    virtual std::string nome() const = 0; // Nome do teste
    virtual ~TestsBase() = default;

protected:
    void checar(bool condicao, const std::string& descricao)
    {
        if (condicao)
        {
            std::cout << "[OK] " << descricao << std::endl;
        }
        else
        {
            std::cout << "[ERRO] " << descricao << std::endl;
        }
    }
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSBASE_H
