//
// Created by caleb on 18/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_QUARTODTO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_QUARTODTO_HPP

#include <string>

using namespace std;

namespace Hotelaria {
    class QuartoDTO {
    private:
        int quartoId;
        string numero;
        int capacidade;
        int dinheiro;
        string ramal;

    public:
        QuartoDTO() = default;

        QuartoDTO(int quartoId, string numero, int capacidade, int dinheiro, string ramal) : quartoId(quartoId),
            numero(numero), capacidade(capacidade), dinheiro(dinheiro), ramal(ramal) {
        };

        int getQuartoId() const;

        void setQuartoId(int valor);

        string getNumero() const;

        void setNumero(const string &valor);

        int getCapacidade() const;

        void setCapacidade(const int &valor);

        int getDinheiro() const;

        void setDinheiro(const int &valor);

        string getRamal() const;

        void setRamal(const string &valor);
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_QUARTODTO_HPP