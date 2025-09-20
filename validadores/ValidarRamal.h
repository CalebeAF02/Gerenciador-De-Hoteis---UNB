//
// Created by caleb on 19/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_VALIDARRAMAL_H
#define CODIGOS_CLION_TP1_IML_VALIDARRAMAL_H

#include <stdexcept>

using namespace std;

// Funcao estatica para validar endereco em hotel e hospede
class ValidarRamal: public exception{
public:
    // Método abstrato: toda classe filha PRECISA implementar
    static void validarRamal(int endereco);

    // Sempre que tiver métodos virtuais, destrutor deve ser virtual também
    virtual ~ValidarRamal() = default;

};
#endif //CODIGOS_CLION_TP1_IML_VALIDARRAMAL_H
