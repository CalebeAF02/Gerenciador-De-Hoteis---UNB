//
// Created by caleb on 01/11/2025.
//

#include "ServicoAutenticavel.hpp"

bool ServicoAutenticavel::autenticar(Email &emailCopia, Senha &senhaCopia) {
    PersistenciaGerente dao;
    bool gerenteLogado = dao.autenticarGerentePeloBD(emailCopia.getValor(), senhaCopia.getValor());

    if (gerenteLogado) {
        this->estaLogado = true;
        cout << "Login realizado com sucesso!\n";
        return true;
    } else {
        cout << "Erro: Usuario nao encontrado ou senha incorreta!\n";
        return false;
    }
};