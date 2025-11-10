#ifndef TEXTO_APRESENTACAO_INCLUDE
#define TEXTO_APRESENTACAO_INCLUDE

#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

// Classe responsável APENAS pela formatação visual de strings no terminal (caixas, títulos, separadores).
class Formato {
public:
    // Função auxiliar para repetir caracteres (herdada do seu projeto original)
    static void RepetirCaracter(int qntCaracteres, char c);

    static string RepetirCaracterMesmaLinha(int qntCaracteres, char c);


    // 1. Caixas principais (para Títulos de Módulos, Menus)
    static void TituloEmCaixa(const string &titulo);

    // 2. Separador de categorias (para VÁLIDOS/INVÁLIDOS nos Testes Unitários)
    static void SeparadorDeCategoria(const string &titulo);

    // 3. Opções de menu (já em uso na sua controladora)
    static void OpcaoEmCaixa(const string &texto, const int &numero);

    static void OpcaoEmCaixa(const string &texto, const string &numero);

    // 4. Opcao Simples
    static void OpcaoSimples(const string &texto, const int &numero);

    // 5. Exibir em tabela
    static void TabelaGenerica(
        const string &titulo, // Nome do 1º argumento: titulo
        const vector<string> &headers, // Nome do 2º argumento: headers
        const vector<vector<string> > &data // Nome do 3º argumento: data
    );
};

#endif