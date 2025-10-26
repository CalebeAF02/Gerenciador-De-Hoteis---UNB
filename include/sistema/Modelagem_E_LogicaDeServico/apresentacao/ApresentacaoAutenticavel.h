//
// Created by caleb on 26/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_APRESENTACAOAUTENTICAVEL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_APRESENTACAOAUTENTICAVEL_H
#include "InterfaceApresentacaoAutenticavel.h"
#include "InterfaceServicoAutenticacao.h"

class ApresentacaoAutenticavel : public InterfaceApresentacaoAutenticavel {
private:
    InterfaceServicoAutenticacao* servicoAutenticacao;

public:
    ApresentacaoAutenticavel(InterfaceServicoAutenticacao* servico);

    void autenticar() override;
    void exibirMenu(const std::string& email) override;
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_APRESENTACAOAUTENTICAVEL_H
