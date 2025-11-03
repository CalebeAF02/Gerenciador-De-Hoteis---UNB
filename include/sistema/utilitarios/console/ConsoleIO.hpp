//
// Created by caleb on 02/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_CONSOLEIO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_CONSOLEIO_HPP

#include <iostream>
#include <string>
#include <limits> // Para clear/ignore do buffer se necessário

using namespace std;

// Classe responsável pela manipulação de entrada e saída de dados simples.
class ConsoleIO {
public:
    // Métodos de Input
    static string LerLinha();

    static string ReceberOpcao();

    // Métodos de Output Simples
    // Usaremos PrintMensagem(string) para imprimir mensagens genéricas (perguntas, retornos, etc.)
    static void PrintMensagem(const string &mensagem);

    // Podemos manter um PrintLine simples para quebras de linha ou debugging
    static void PrintLine(const string &texto);

    static void PrintLine(int numero);
};

#endif //GERENCIADOR_DE_HOTEIS_UNB_CONSOLEIO_HPP