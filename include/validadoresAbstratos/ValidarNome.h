#ifndef VALIDAR_NOME_INCLUDE
#define VALIDAR_NOME_INCLUDE

#include <iostream>
#include <string>

#include <stdexcept>

using namespace std;

// Funcao estatica para validar nome em hotel e pessoa
class ValidarNome : public exception {
public:
    static void validar(const string nome);
};
#endif
