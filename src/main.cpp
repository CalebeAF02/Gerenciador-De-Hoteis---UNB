#include <iostream>
#include <string>


#include "../coisas/utilitarios/Data.h"
#include "dominios/Pessoa.h"
#include "dominios/Gerente.h"
#include "dominios/Hospede.h"
#include "dominios/Hotel.h"
#include "dominios/Quarto.h"
#include "testes/Smoke_Tests.h"
#include "validadoresPrincipais/ValidarString.h"
#include "validadoresPrincipais/ValidarInt.h"
#include "validadoresAbstratos/ValidarNome.h"
#include "validadoresAbstratos/ValidarEmail.h"
#include "validadoresAbstratos/ValidarEndereco.h"
#include "validadoresAbstratos/ValidarDinheiro.h"
#include "validadoresAbstratos/ValidarCodigo.h"
#include "validadoresAbstratos/ValidarRamal.h"
#include "utilitarios/TextoApresentacao.h"
#include "../include/sistema/Servicos.h"
#include "sistema/SistemaHotel.h"
using namespace std;

#define TESTANDO 0

#define PRODUCAO 1

#define ESTOU_TESTANDO PRODUCAO

int main()
{
#if ESTOU_TESTANDO == TESTANDO
    SmokeTest::testarEntradas();
#endif

#if ESTOU_TESTANDO == PRODUCAO
    SistemaHotel sistema;
    while (sistema.getExecutando())
    {
        sistema.rodandoSistema();
    }
#endif


    return 0;
}

