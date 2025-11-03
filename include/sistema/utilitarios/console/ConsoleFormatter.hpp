#ifndef TEXTO_APRESENTACAO_INCLUDE
#define TEXTO_APRESENTACAO_INCLUDE

#include <iostream>
#include <ostream>

using namespace std;

// Classe responsável APENAS pela formatação visual de strings no terminal (caixas, títulos, separadores).
class ConsoleFormatter {
private:
    // Função auxiliar para repetir caracteres (herdada do seu projeto original)
    static void RepetirCaracter(int qntCaracteres, char c);

public:
    // 1. Caixas principais (para Títulos de Módulos, Menus)
    static void MostrarTituloEmCaixa(const string &titulo);

    // 2. Separador de categorias (para VÁLIDOS/INVÁLIDOS nos Testes Unitários)
    static void MostrarSeparadorCategoria(const string &titulo);

    // 3. Opções de menu (já em uso na sua controladora)
    static void MostrarOpcaoEmCaixa(const string &texto, int numero);

    static void MostrarOpcaoEmCaixa(const string &texto, const string &numero);

    static void MostrarOpcaoSimples(const string &texto, int numero);

    // 4. Utilitário para resumo de teste
    static void MostrarSeparadorDeTeste();
};

#endif