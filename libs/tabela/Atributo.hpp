//
// Created by caleb on 09/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_ATRIBUTO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_ATRIBUTO_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace VisualizadorDeTabela {
    class Atributo {
    private:
        string nome;
        string valor;

    public:
        Atributo() = default;

        Atributo(string nome, string valor) : nome(nome), valor(valor) {
        };

        void setNome(string nome);

        void setValor(string valor);

        string getNome();

        string getValor();
    };

    inline string Atributo::getNome() {
        return nome;
    }

    inline string Atributo::getValor() {
        return valor;
    }
}
#endif //GERENCIADOR_DE_HOTEIS_UNB_ATRIBUTO_HPP