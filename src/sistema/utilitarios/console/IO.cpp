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
bool IO::tentarNovamente() {
    while (true) {
        IO::Println("Deseja :");
        Formato::OpcaoSimples("Voltar", 0);
        Formato::OpcaoSimples("Tentar novamente", 1);
        string opcaoSTR = IO::LerLinha();
        try {
            int opcaoINT = stoi(opcaoSTR);
            if (opcaoINT == 0) {
                return false;
            } else if (opcaoINT == 1) {
                return true;
            } else {
                IO::Println("Erro: Opcao Invalida (somente 0 ou 1).");
            }
        } catch (const invalid_argument &erro) {
            IO::Println("Erro: Numero fora do limite. Por favor, digite 0 ou 1.");
        }
    }
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