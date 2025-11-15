//
// Created by caleb on 14/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_CSP_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_CSP_HPP

#include "InterfaceServicoPessoal.hpp"
#include "../../../../libs/io/IO.hpp"
#include <iostream>

using namespace std;

class ControladoraServicoPessoal : public InterfaceServicoPessoal {
public:
    //  por meio dos quais são solicitados os serviços.
    bool incluir(const Gerente);

    bool remover(const Email email);

    bool pesquisar(Gerente);

    bool editar(const Gerente);
};

#endif //GERENCIADOR_DE_HOTEIS_UNB_CSP_HPP