#include <iostream>
#include <string>


#include "dominios/Data.h"
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
#include "utilitarios/Servicos.h"
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
    TextoApresentacao::MostrarTituloEmCaixa("Seja bem vindo ao gerenciador de hoteis");

    TextoApresentacao::MostrarTituloPergunta("Selecione a opcao");

    TextoApresentacao::MostrarOpcao("Criar gerente", 1);
    TextoApresentacao::MostrarOpcao("Fazer Login", 2);

    string opcao = "";
    Servicos servicos;

    do
    {
        opcao = TextoApresentacao::RecebeOpcao();
        if (opcao == "1")
        {
            servicos.criarGerente();
        }
        else if (opcao == "2")
        {
            servicos.loginGerente();
            cout << "Insira seu Email!" << endl;
        }
        else
        {
            cout << "Opcao Invalida!" << endl;
        }
    }
    while (opcao != "1" && opcao != "2");
#endif


    return 0;
}
