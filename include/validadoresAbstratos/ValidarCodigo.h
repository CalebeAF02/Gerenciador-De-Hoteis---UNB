#pragma once

#include <string>
#include <stdexcept>

using namespace std;

// Funcao estatica para validar endereco em hotel e hospede
class ValidarCodigo: public exception{
public:
    static void validar(string codigo);
};