#include "Quarto.hpp"

namespace Hotelaria {
    Quarto::Quarto(Numero numero, Capacidade capacidade, Dinheiro diaria, Ramal ramal) {
        setNumero(numero);
        setCapacidade(capacidade);
        setDiaria(diaria);
        setRamal(ramal);
    }
    void Quarto::setNumero(const Numero &newNumero) {
        this->numero = newNumero;
    }
    void Quarto::setCapacidade(const Capacidade &newCapacidade) {
        this->capacidade = newCapacidade;
    }
    void Quarto::setDiaria(const Dinheiro &newDiaria) {
        this->diaria = newDiaria;
    }

    void Quarto::setRamal(const Ramal &newRamal) {
        this->ramal = newRamal;
    }

    //Get
    string Quarto::getNumero() const {
        return numero.getValor();
    }

    int Quarto::getCapacidade() const {
        return capacidade.getValor();
    }

    int Quarto::getDiaria() const {
        return diaria.getValor();
    }

    string Quarto::getRamal() const {
        return ramal.getValor();
    }
}