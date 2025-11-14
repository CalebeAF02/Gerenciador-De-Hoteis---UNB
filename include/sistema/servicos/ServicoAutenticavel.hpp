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

class ServicoAutenticavel : public ISAutenticavel {
private:
    bool estaLogado = false;

public:
    bool autenticar(Email &emailCopia, Senha &senhaCopia) override;

    void sair() override;

    bool getEstaLogado() override;
};

inline bool ServicoAutenticavel::getEstaLogado() {
    return estaLogado;
};

inline void ServicoAutenticavel::sair() {
    this->estaLogado = false;
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_CONTROLEINTERFACEUSUARIOAUTENTICAVEL_H