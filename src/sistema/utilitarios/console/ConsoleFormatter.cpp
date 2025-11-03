#include "ConsoleFormatter.hpp"

#include <algorithm>
#include <limits>

void ConsoleFormatter::RepetirCaracter(int qntCaracteres, char c) {
    int i = 0;
    while (i < (qntCaracteres)) {
        cout << c;

        i++;
    }
};

// 1. Mostrar Título em Caixa (Versão centralizada)
void ConsoleFormatter::MostrarTituloEmCaixa(const string &titulo) {
    const int LARGURA = 50;

    cout << "\n";
    RepetirCaracter(LARGURA, '=');
    cout << "\n";

    // Centraliza o texto dentro da largura
    int padding_total = LARGURA - titulo.length() - 2; // -2 para as bordas
    int padding_esq = padding_total / 2;
    int padding_dir = padding_total - padding_esq;

    cout << "|";
    RepetirCaracter(padding_esq, ' ');
    cout << titulo;
    RepetirCaracter(padding_dir, ' ');
    cout << "|" << endl;

    RepetirCaracter(LARGURA, '=');
    cout << "\n\n";
};

// 2. Separador de Categoria (Para Testes Válidos/Inválidos)
void ConsoleFormatter::MostrarSeparadorCategoria(const string &titulo) {
    const int LARGURA = 70; // Mais largo, ideal para o relatório de teste

    cout << "\n";
    RepetirCaracter(LARGURA, '-');
    cout << "\n";

    // Centralização
    int padding_total = LARGURA - titulo.length() - 2;
    int padding_esq = padding_total / 2;
    int padding_dir = padding_total - padding_esq;

    cout << "|";
    RepetirCaracter(padding_esq, ' ');
    cout << titulo;
    RepetirCaracter(padding_dir, ' ');
    cout << "|" << endl;

    RepetirCaracter(LARGURA, '-');
    cout << "\n";
};

void ConsoleFormatter::MostrarOpcaoEmCaixa(const string &texto, int numero) {
    cout << "------------------------------\n";
    cout << "| [" << numero << "] " << texto << "\n";
    cout << "------------------------------\n";
};

void ConsoleFormatter::MostrarOpcaoEmCaixa(const string &texto, const string &numero) {
    cout << "------------------------------\n";
    cout << "| [" << numero << "] " << texto << "\n";
    cout << "------------------------------\n";
};

void ConsoleFormatter::MostrarOpcaoSimples(const string &texto, int numero) {
    cout << "[" << numero << "] " << texto << "\n";
};

// 4. Separador simples (para usar entre testes individuais ou seções curtas)
void ConsoleFormatter::MostrarSeparadorDeTeste() {
    cout << "--------------------------------------------------------\n";
}