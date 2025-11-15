#include "Formato.hpp"

#include <algorithm>
#include <limits>

#include "../io/IO.hpp"
namespace Formato {
    //-----------------------------------------------------------------------------------------------------------
    string RepetirCaracterMesmaLinha(int qntCaracteres, char c) {
        int i = 0;
        string temp = "";
        while (i < (qntCaracteres)) {
            temp += c;
            i++;
        }
        return temp;
    };

    void RepetirCaracter(int qntCaracteres, char c) {
        int i = 0;
        while (i < (qntCaracteres)) {
            cout << c;

            i++;
        }
    };
    //-----------------------------------------------------------------------------------------------------------
    void TituloEmCaixa(const string &titulo) {
        const int LARGURA = 70; // Mais largo, ideal para o relatório de teste

        cout << "\n";
        RepetirCaracter(LARGURA, '=');
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

        RepetirCaracter(LARGURA, '=');
        cout << "\n";
    };
    //-----------------------------------------------------------------------------------------------------------
    void SeparadorDeCategoria(const string &titulo) {
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
    //-----------------------------------------------------------------------------------------------------------
    void OpcaoEmCaixa(const string &texto, const int &numero) {
        cout << "------------------------------\n";
        cout << "| [" << numero << "] " << texto << "\n";
        cout << "------------------------------\n";
    };

    void OpcaoEmCaixa(const string &texto, const string &numero) {
        cout << "------------------------------\n";
        cout << "| [" << numero << "] " << texto << "\n";
        cout << "------------------------------\n";
    };
    //-----------------------------------------------------------------------------------------------------------
    void OpcaoSimples(const string &texto, const int &numero) {
        cout << "[" << numero << "] " << texto << "\n";
    };
    //-----------------------------------------------------------------------------------------------------------
}