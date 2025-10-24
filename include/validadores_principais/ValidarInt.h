#ifndef VALIDAR_INT_INCLUDE
#define VALIDAR_INT_INCLUDE

#include <stdexcept>

using namespace std;

class ValidarInt : public exception
{
public:
    // Método abstrato: toda classe filha PRECISA implementar
    virtual void validar(int tipo, int valor) = 0; // interface pura
};
#endif