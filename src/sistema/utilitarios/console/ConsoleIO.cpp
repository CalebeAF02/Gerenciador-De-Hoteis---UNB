//
// Created by caleb on 02/11/2025.
//

#include "ConsoleIO.hpp"

//-----------------------------------------------------------------------------------------------------------
string ConsoleIO::LerLinha() {
    string valor = "";
    // Limpa o buffer antes de ler, para evitar lixo (importante em C++ com cin/getline misturado)
    if (cin.rdbuf()->in_avail() > 0) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    getline(cin, valor);
    return valor;
}

//-----------------------------------------------------------------------------------------------------------
string ConsoleIO::LerOpcao() {
    cout << "Opcao: ";
    return LerLinha();
}

//-----------------------------------------------------------------------------------------------------------
void ConsoleIO::PrintMenssagem(const string &mensagem) {
    cout << mensagem << endl;
}

//-----------------------------------------------------------------------------------------------------------
void ConsoleIO::Pergunta(const string &pergunta) {
    cout << pergunta << endl;
}

//-----------------------------------------------------------------------------------------------------------
void ConsoleIO::SubPergunta(const string &pergunta) {
    cout << pergunta;
}

//-----------------------------------------------------------------------------------------------------------