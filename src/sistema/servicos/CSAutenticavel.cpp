//
// Created by caleb on 01/11/2025.
//

#include "CSAutenticavel.hpp"

bool CSAutenticavel::autenticar(Email &emailCopia, Senha &senhaCopia) {
    PersistenciaGerente persistencia;
    bool gerenteLogado = persistencia.autenticarGerente(emailCopia.getValor(), senhaCopia.getValor());

    if (gerenteLogado) {
        this->estaLogado = true;
        cout << "Login realizado com sucesso!\n";
        return true;
    } else {
        cout << "Erro: Usuario nao encontrado ou senha incorreta!\n";
        return false;
    }
};