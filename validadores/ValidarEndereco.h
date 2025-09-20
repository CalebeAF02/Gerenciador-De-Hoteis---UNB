//
// Created by caleb on 19/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_VALIDARENDERECO_H
#define CODIGOS_CLION_TP1_IML_VALIDARENDERECO_H

#include <string>
#include <stdexcept>

using namespace std;

// Funcao estatica para validar endereco em hotel e hospede
class ValidarEndereco: public exception{
public:
    // Método abstrato: toda classe filha PRECISA implementar
    static void validarEndereco(string endereco);

    // Sempre que tiver métodos virtuais, destrutor deve ser virtual também
    virtual ~ValidarEndereco() = default;

};


#endif //CODIGOS_CLION_TP1_IML_VALIDARENDERECO_H