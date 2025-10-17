//
// Created by caleb on 16/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACEGERENCIAVEL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACEGERENCIAVEL_H

class InterfaceGerenciavel
{
public:
    virtual void criar() = 0;
    virtual void ler() = 0;
    virtual void atualizar() = 0;
    virtual void excluir() = 0;
    virtual ~InterfaceGerenciavel() = default;
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_INTERFACEGERENCIAVEL_H
