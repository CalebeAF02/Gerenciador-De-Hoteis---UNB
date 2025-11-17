//
// Created by caleb on 09/11/2025.
//

#include "Atributo.hpp"

namespace VisualizadorDeTabela {
    string Atributo::getNome() {
        return nome;
    }

    string Atributo::getValor() {
        return valor;
    }

    void Atributo::setNome(string nome) {
        this->nome = nome;
    };

    void Atributo::setValor(string valor) {
        this->valor = valor;
    }
}