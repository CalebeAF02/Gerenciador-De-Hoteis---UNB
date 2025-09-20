//
// Created by caleb on 19/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_VALIDARNOME_H
#define CODIGOS_CLION_TP1_IML_VALIDARNOME_H

#include <string>
#include <stdexcept>

using namespace std;

// Funcao estatica para validar nome em hotel e pessoa
class ValidarNome: public exception {
public:
    // Método abstrato: toda classe filha PRECISA implementar
    static void validarNome(string nome);

    // Sempre que tiver métodos virtuais, destrutor deve ser virtual também
    virtual ~ValidarNome() = default;

};


#endif //CODIGOS_CLION_TP1_IML_VALIDARNOME_H