//
// Created by caleb on 02/11/2025.
//

#include "ConsoleIO.hpp"

string ConsoleIO::LerLinha() {
    string valor = "";
    // Limpa o buffer antes de ler, para evitar lixo (importante em C++ com cin/getline misturado)
    if (cin.rdbuf()->in_avail() > 0) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    getline(cin, valor);
    return valor;
}

string ConsoleIO::ReceberOpcao() {
    cout << "\nOpcao: ";
    return LerLinha();
}

void ConsoleIO::PrintLine(const string &texto) {
    cout << texto << "\n";
}

// Sobrecarga para Output de número
void ConsoleIO::PrintLine(int numero) {
    cout << numero << "\n";
}

void ConsoleIO::PrintMensagem(const string &mensagem) {
    cout << mensagem << endl;
}