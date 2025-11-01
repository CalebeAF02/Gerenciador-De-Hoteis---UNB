//
// Created by caleb on 01/11/2025.
//

#include "ServicoAutenticavel.h"

bool ServicoAutenticavel::autenticar(Email &emailCopia, Senha &senhaCopia) {
    PersistenciaGerente dao;
    bool gerenteLogado = dao.autenticarGerentePeloBD(emailCopia.getValor(), senhaCopia.getValor());

    if (gerenteLogado) {
        this->estaLogado = true;
        std::cout << "Login realizado com sucesso!\n";
        return true;
    } else {
        std::cout << "Erro: Usuario nao encontrado ou senha incorreta!\n";
        return false;
    }
};