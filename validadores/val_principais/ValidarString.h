//
// Created by caleb on 10/09/2025.
//

#ifndef CODIGOS_CLION_TP1_IML_DOMINIO_H
#define CODIGOS_CLION_TP1_IML_DOMINIO_H

#include <string>

using namespace std;

class ValidarString : public exception {
public:
    // Método abstrato: toda classe filha PRECISA implementar
    virtual void validar(int tipo, string valor) = 0; // interface pura
    /*
     * Criar
     * Ler
     * Editar
     * Excluir
     */
};

#endif //CODIGOS_CLION_TP1_IML_DOMINIO_H