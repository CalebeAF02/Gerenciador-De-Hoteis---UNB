#pragma once

#include <stdexcept>

using namespace std;

class ValidarInt : public exception {
public:
    // Método abstrato: toda classe filha PRECISA implementar
    virtual void validar(int tipo, int valor) = 0; // interface pura
};