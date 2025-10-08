#include "testes/Smoke_Tests.h"
#include "sistema/SistemaHotel.h"

#include <iostream>
#include <string>

#include "TextoApresentacao.h"

using namespace std;

#define TESTANDO 0

#define PRODUCAO 1

#define ESTOU_TESTANDO TESTANDO

int main()
{

    /*
     * Edições a fazer :
     *
     * Funcionalidades do sistema
     *
     * Conta = LER; EDITAR; EXCLUIR;
     * Hotel = LER; EDITAR; EXCLUIR; CRIAR; LISTAR(Dados de todos os hoteis;
     * Quarto = LER; EDITAR; EXCLUIR; CRIAR; LISTAR(Dados de todos os quartos;
     * Reserva = LER; EDITAR; EXCLUIR; CRIAR; LISTAR(Dados de todos as reservas;
     * Hospede = LER; EDITAR; EXCLUIR; CRIAR; LISTAR(Dados de todos os hospedes;
     *
     * 1) Não pode haver conflitos nas reservas!
     *
     * 2) Não pode editar as informações em CODIGO, que apresenta chave de registro "PK"!
     *
     * 3) Não permite exclusões que gerem inconcistencias!
     *
     */
#if ESTOU_TESTANDO == TESTANDO
    SmokeTest::testarEntradas();
    SistemaHotel sistema;

    TextoApresentacao::MostrarTituloEmCaixa("Login Programado");
    cout<<"Entrada :"<<"calebe@gmail.com"<<endl<<"Senha :"<<"A1#a1"<<endl<<endl;
    if (sistema.fazerLogin("calebe@gmail.com", "A1#a1"))
    {
        cout<<endl;
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