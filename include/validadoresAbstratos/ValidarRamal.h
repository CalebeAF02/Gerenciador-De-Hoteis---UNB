#ifndef VALIDAR_RAMAL_INCLUDE
#define VALIDAR_RAMAL_INCLUDE

#include <stdexcept>

using namespace std;

// Funcao estatica para validar endereco em hotel e hospede
class ValidarRamal : public exception {
public:
    // Método abstrato: toda classe filha PRECISA implementar
    static void validar(string ramal);
};
#endif
