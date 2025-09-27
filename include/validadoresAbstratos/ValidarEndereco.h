#ifndef VALIDAR_ENDERECO_INCLUDE
#define VALIDAR_ENDERECO_INCLUDE

#include <string>
#include <stdexcept>

using namespace std;

// Funcao estatica para validar endereco em hotel e hospede
class ValidarEndereco: public exception{
public:
    static void validar(string endereco);
};
#endif
