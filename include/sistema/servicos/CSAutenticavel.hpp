//
// Created by caleb on 01/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_CONTROLEINTERFACEUSUARIOAUTENTICAVEL_H
#define GERENCIADOR_DE_HOTEIS_UNB_CONTROLEINTERFACEUSUARIOAUTENTICAVEL_H

#include <iostream>

#include "ISAutenticavel.hpp"
#include "PersistenciaGerente.hpp"
#include "../utilitarios/console/Formato.hpp"

using namespace std;

class CSAutenticavel : public ISAutenticavel {
private:
    bool estaLogado = false;

public:
    bool autenticar(Email &emailCopia, Senha &senhaCopia) override;

    void sair() override;

    bool getEstaLogado() override;
};

inline bool CSAutenticavel::getEstaLogado() {
    return estaLogado;
};

inline void CSAutenticavel::sair() {
    this->estaLogado = false;
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_CONTROLEINTERFACEUSUARIOAUTENTICAVEL_H