#include <iostream>
#include <string>

#include "dominios/Data.h"
#include "dominios/Pessoa.h"
#include "dominios/Gerente.h"
#include "dominios/Hospede.h"
#include "dominios/Hotel.h"
#include "dominios/Quarto.h"
#include "../testes/TestesValidates.h"
#include "validadoresPrincipais/ValidarString.h"
#include "validadoresPrincipais/ValidarInt.h"
#include "validadoresAbstratos/ValidarNome.h"
#include "validadoresAbstratos/ValidarEmail.h"
#include "validadoresAbstratos/ValidarEndereco.h"
#include "validadoresAbstratos/ValidarDinheiro.h"
#include "validadoresAbstratos/ValidarCodigo.h"
#include "validadoresAbstratos/ValidarRamal.h"

using namespace std;

int Teste::contTodalTestes = 0;
int Teste::contTodalTestesOk = 0;
int Teste::contTodalTestesProblema = 0;

int main() {
    TesteValidadores::testarEntradas();

    system("pause");
    return 0;
}