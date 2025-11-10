//
// Created by caleb on 02/11/2025.
//

#include "IO.hpp"

//-----------------------------------------------------------------------------------------------------------
string IO::LerLinha() {
    string valor = "";
    // Limpa o buffer antes de ler, para evitar lixo (importante em C++ com cin/getline misturado)
    if (cin.rdbuf()->in_avail() > 0) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    getline(cin, valor);
    return valor;
}

//-----------------------------------------------------------------------------------------------------------
string IO::LerOpcao() {
    cout << "Opcao: ";
    return LerLinha();
}

//-----------------------------------------------------------------------------------------------------------
void IO::Println(const string &mensagem) {
    cout << mensagem << endl;
}

//-----------------------------------------------------------------------------------------------------------
void IO::Print(const string &pergunta) {
    cout << pergunta;
}

//-----------------------------------------------------------------------------------------------------------