#ifndef VALIDAR_STRING_INCLUDE
#define VALIDAR_STRING_INCLUDE

#include <string>

using namespace std;

class ValidarString : public exception
{
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
#endif