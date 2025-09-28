#include "../dominios/Quarto.h"

using namespace std;

void Quarto::validar(int tipo, const string valor)
{
    switch (tipo)
    {
    case TIPO_NUMERO:
        {
            validarNumero(valor);
            break;
        }
    case TIPO_RAMAL:
        {
            ValidarRamal::validar(valor);
            break;
        };
    };
};

void Quarto::validar(int tipo, const int valor)
{
    switch (tipo)
    {
    case TIPO_CAPACIDADE:
        {
            validarCapacidade(valor);
            break;
        };
    case TIPO_DIARIA:
        {
            validarDiaria(valor);
        }
    };
};

void Quarto::validarNumero(const string valor)
{
    if (valor.length() == 3)
    {
        if ((isdigit(valor[0]) || isdigit(valor[1]) || isdigit(valor[2])) == false)
        {
            throw invalid_argument("Erro: Numero invalido! Digite um valores do tipo numerico.");
        }
        else
        {
            if (valor[0] < '1' && valor[1] < '1' && valor[2] < '1')
            {
                throw invalid_argument("Erro: Digite um valor entre 001 e 999");
            }
        }
    }
    else
    {
        throw invalid_argument("Erro: Formato de Numero invalido! Digite um valor entre 001 e 999");
    }
};

void Quarto::validarCapacidade(const int valor)
{
    if (valor < 1 || valor > 4)
    {
        throw invalid_argument("Erro: Capacidade invalida! Digite um valor entre 1 e 4");
    }
    else
    {
        //cou << "Senha: Valida! " << endl;
    }
};

void Quarto::validarDiaria(const int valor)
{
    if (valor == 80000 || valor == 120000)
    {
        ValidarDinheiro::validar(valor);
    }
    else
    {
        throw invalid_argument("Erro: Valor da diaria invalido. Valorres: Quarto1= R$800,00 e Quarto2= R$1.200,00 !");
    }
}