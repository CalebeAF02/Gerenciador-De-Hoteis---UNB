#include "TextoApresentacao.h"

#include <algorithm>
#include <limits>

void TextoApresentacao::RepetirCaracter(int qntCaracteres, char c) {
    int i = 0;
    while (i < (qntCaracteres)) {
        cout << c;

        i++;
    }
};

void TextoApresentacao::MostrarTituloEmCaixa(string apresentacao) {
    RepetirCaracter(apresentacao.length() + 2 + (2 * 4), '-');

    cout << endl << "|";
    RepetirCaracter(4, ' ');
    RepetirCaracter(apresentacao.length(), ' ');
    RepetirCaracter(4, ' ');
    cout << "|" << endl;

    RepetirCaracter(1, '|');
    RepetirCaracter(4, ' ');
    cout << apresentacao;
    RepetirCaracter(4, ' ');
    RepetirCaracter(1, '|');

    cout << endl << "|";
    RepetirCaracter(4, ' ');
    RepetirCaracter(apresentacao.length(), ' ');
    RepetirCaracter(4, ' ');
    cout << "|" << endl;

    RepetirCaracter(apresentacao.length() + 2 + (2 * 4), '-');

    cout << endl;
};

void TextoApresentacao::MostrarTituloPergunta(string pergunta) {
    cout << pergunta << endl;
};

void TextoApresentacao::MostrarTituloRetorno(string retorno) {
    cout << retorno << endl;
};

void TextoApresentacao::MostrarOpcaoEmCaixa(const string &texto, int numero) {
    cout << "------------------------------\n";
    cout << "| [" << numero << "] " << texto << "\n";
    cout << "------------------------------\n";
};

void TextoApresentacao::MostrarOpcaoEmCaixa(string texto, string numero) {
    cout << "------------------------------\n";
    cout << "| [" << numero << "] " << texto << "\n";
    cout << "------------------------------\n";
};

void TextoApresentacao::MostrarOpcao(string texto, int numero) {
    cout << "[" << numero << "] " << texto << "\n";
};

string TextoApresentacao::RecebeOpcao() {
    cout << endl << "Opcao: ";
    string opcao = LerLinha();
    return opcao;
};

string TextoApresentacao::LerLinha() {
    string valor = "";
    getline(cin, valor);
    return valor;
};