//
// Created by caleb on 09/11/2025.
//

#ifndef Hotelaria_UnB_TP1_TAMANHOATRIBUTO_HPP
#define Hotelaria_UnB_TP1_TAMANHOATRIBUTO_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace VisualizadorDeTabela {
    class TamanhoAtributo {
    private:
        string nome;
        int tamanho = 0;

    public:
        TamanhoAtributo() = default;

        TamanhoAtributo(string nome, int tamanho) : nome(nome), tamanho(tamanho) {
        };

        void setNome(string nome);

        void setTamanho(int tamanho);

        string getNome();

        int getTamanho();
    };
}

#endif //Hotelaria_UnB_TP1_TAMANHOATRIBUTO_HPP