//
// Created by caleb on 09/11/2025.
//

#include "Linha.hpp"

namespace VisualizadorDeTabela {
    vector<shared_ptr<Atributo> > Linha::getAtributos() {
        return atributos;
    };

    void Linha::atributo(string nome, string valor) {
        shared_ptr<Atributo> atributo = make_shared<Atributo>(nome, valor);

        bool ja_existe = false;
        for (shared_ptr<Atributo> &a: atributos) {
            if (nome == a->getNome()) {
                a->setValor(valor);
                ja_existe = true;
                break;
            }
        }
        if (!ja_existe) {
            atributos.push_back(atributo);
        }
    }

    void Linha::atributo(string nome, int valor) {
        atributo(nome, to_string(valor));
    }
}