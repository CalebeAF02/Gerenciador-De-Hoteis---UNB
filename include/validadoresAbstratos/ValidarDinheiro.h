#ifndef VALIDAR_DINHEIRO_INCLUDE
#define VALIDAR_DINHEIRO_INCLUDE

#include <stdexcept>

using namespace std;

// Funcao estatica para validar endereco em hotel e hospede
class ValidarDinheiro : public exception
{
public:
    static void validar(int dinheiro);
};
#endif