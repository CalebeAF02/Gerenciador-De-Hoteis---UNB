#pragma once

#include <string>
#include <stdexcept>

using namespace std;

// Funcao estatica para validar endereco em hotel e hospede
class ValidarEndereco: public exception{
public:
    static void validar(string endereco);
};