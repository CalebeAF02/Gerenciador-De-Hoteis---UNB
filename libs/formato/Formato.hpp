#ifndef TEXTO_APRESENTACAO_INCLUDE
#define TEXTO_APRESENTACAO_INCLUDE

#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

// Classe responsável APENAS pela formatação visual de strings no terminal (caixas, títulos, separadores).
namespace  Formato {
    // Função auxiliar para repetir caracteres (herdada do seu projeto original)
    void RepetirCaracter(int qntCaracteres, char c);

    string RepetirCaracterMesmaLinha(int qntCaracteres, char c);


    // 1. Caixas principais (para Títulos de Módulos, Menus)
    void TituloEmCaixa(const string &titulo);

    // 2. Separador de categorias (para VÁLIDOS/INVÁLIDOS nos Testes Unitários)
    void SeparadorDeCategoria(const string &titulo);

    // 3. Opções de menu (já em uso na sua controladora)
    void OpcaoEmCaixa(const string &texto, const int &numero);

    void OpcaoEmCaixa(const string &texto, const string &numero);

    // 4. Opcao Simples
    void OpcaoSimples(const string &texto, const int &numero);
};

#endif