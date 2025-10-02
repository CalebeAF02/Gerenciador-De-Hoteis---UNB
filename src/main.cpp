#include <iostream>
#include <string>


#include "../coisas/utilitarios/Data.h"
#include "../include/entidades/Pessoa.h"
#include "../include/entidades/Gerente.h"
#include "../include/entidades/Hospede.h"
#include "../include/entidades/Hotel.h"
#include "../include/entidades/Quarto.h"
#include "testes/Smoke_Tests.h"
#include "validadores_principais/ValidarString.h"
#include "validadores_principais/ValidarInt.h"
#include "../include/validadores_abstratos/ValidarNome.h"
#include "../include/validadores_abstratos/ValidarEmail.h"
#include "../include/validadores_abstratos/ValidarEndereco.h"
#include "../include/validadores_abstratos/ValidarDinheiro.h"
#include "../include/validadores_abstratos/ValidarCodigo.h"
#include "../include/validadores_abstratos/ValidarRamal.h"
#include "utilitarios/TextoApresentacao.h"
#include "../include/sistema/Servicos.h"
#include "sistema/SistemaHotel.h"
using namespace std;

#define TESTANDO 0

#define PRODUCAO 1

#define ESTOU_TESTANDO TESTANDO

int main()
{
#if ESTOU_TESTANDO == TESTANDO
    SmokeTest::testarEntradas();
    SistemaHotel sistema;

    if (sistema.fazerLogin("calebe@gmail.com", "A1#a1"))
    {
        sistema.menuSistema();
    };

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