//
// Created by caleb on 14/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_ISP_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_ISP_HPP

#include "Gerente.hpp"
#include "Email.hpp"
#include "../../../../libs/IO/IO.hpp"
#include <iostream>
using namespace std;

class InterfaceServicoPessoal {
public:
    //  por meio dos quais são solicitados os serviços.
    virtual bool incluir(const Gerente) = 0;

    virtual bool remover(const Email email) = 0;

    virtual bool pesquisar(Gerente) = 0;

    virtual bool editar(const Gerente) = 0;

    virtual ~InterfaceServicoPessoal() {
    } //  destrutor virtual.
};

#endif //GERENCIADOR_DE_HOTEIS_UNB_ISP_HPP