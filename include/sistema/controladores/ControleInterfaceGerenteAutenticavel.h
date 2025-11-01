//
// Created by caleb on 01/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_CONTROLEINTERFACEUSUARIOAUTENTICAVEL_H
#define GERENCIADOR_DE_HOTEIS_UNB_CONTROLEINTERFACEUSUARIOAUTENTICAVEL_H

#include <iostream>

#include "InterfaceApresentacaoAutenticavel.h"
#include "PersistenciaGerente.h"
#include "TextoApresentacao.h"

using namespace std;

class ControleInterfaceGerenteAutenticavel : public InterfaceApresentacaoAutenticavel {
private:
    bool estaLogado = false;

public:
    bool autenticar(Email &emailCopia, Senha &senhaCopia) override;

    void fazerLogin();

    void sair();

    bool getEstaLogado();
};

inline bool ControleInterfaceGerenteAutenticavel::getEstaLogado() {
    return estaLogado;
};

inline void ControleInterfaceGerenteAutenticavel::sair() {
    this->estaLogado = false;
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_CONTROLEINTERFACEUSUARIOAUTENTICAVEL_H