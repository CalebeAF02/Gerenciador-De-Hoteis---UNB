#ifndef VALIDAR_EMAIL_INCLUDE
#define VALIDAR_EMAIL_INCLUDE

#include <string>
#include <stdexcept>

using namespace std;

// Funcao estatica para validar email em hotel e pessoa
class ValidarEmail : public exception
{
public:
    static void validar(string valor);
};
#endif