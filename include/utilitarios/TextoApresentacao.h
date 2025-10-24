#ifndef TEXTO_APRESENTACAO_INCLUDE
#define TEXTO_APRESENTACAO_INCLUDE

#include <iostream>
#include <ostream>

using namespace std;

class TextoApresentacao
{
public:
    static void RepetirCaracter(int qntCaracteres, char c);
    static void MostrarTituloEmCaixa(string apresentcao);
    static void MostrarTituloPergunta(string pergunta);
    static void MostrarOpcaoEmCaixa(const string& texto, int numero);
    static void MostrarOpcaoEmCaixa(string texto, string numero);
    static void MostrarOpcao(string opcao, int valor);
    static string RecebeOpcao();
    static string LerLinha();
};

#endif