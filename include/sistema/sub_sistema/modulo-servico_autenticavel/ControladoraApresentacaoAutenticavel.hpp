//
// Created by caleb on 14/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_CAA_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_CAA_HPP

#include "InterfaceServicoAutenticavel.hpp"
#include "InterfaceApresentacaoAutenticavel.hpp"

#include "Email.hpp"
#include "Senha.hpp"
#include "IO.hpp"
#include <iostream>
using namespace std;

class ControladoraApresentacaoAutenticavel : public InterfaceApresentacaoAutenticavel {
private:
    InterfaceServicoAutenticavel *controladora_servico_autenticavel; // Referência para servidor.
public:
    bool autenticar(Email*);

    void setControladoraServicoAutenticavel(InterfaceServicoAutenticavel*);
};

void inline ControladoraApresentacaoAutenticavel::setControladoraServicoAutenticavel(
    InterfaceServicoAutenticavel *controladora_servico_autenticavel) {
    this->controladora_servico_autenticavel = controladora_servico_autenticavel;
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_CAA_HPP