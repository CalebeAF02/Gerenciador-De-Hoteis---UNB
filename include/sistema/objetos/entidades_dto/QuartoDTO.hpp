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
        string capacidade;
        string dinheiro;
        string ramal;

    public:
        QuartoDTO() = default;

        QuartoDTO(int quartoId, string nome, string email, string dinheiro, string ramal) : quartoId(quartoId), numero(numero), capacidade(capacidade), dinheiro(dinheiro), ramal(ramal) {};

        int getQuartoId() const {
            return quartoId;
        }

        void setQuartoId(int valor) {
            this->quartoId = valor;
        }

        string getNumero() const {
            return numero;
        }

        void setNumero(const string &valor) {
            this->numero = valor;
        }

        string getCapacidade() const {
            return capacidade;
        }

        void setCapacidade(const string &valor) {
            this->capacidade = valor;
        }

        string getDinheiro() const {
            return dinheiro;
        }

        void setDinheiro(const string &valor) {
            this->dinheiro = valor;
        }

        string getRamal() const {
            return ramal;
        }

        void setRamal(const string &valor) {
            this->ramal = valor;
        }
    };
}

#endif //GERENCIADOR_DE_HOTEIS_UNB_QUARTODTO_HPP