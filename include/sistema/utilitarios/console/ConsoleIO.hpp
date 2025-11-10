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

    // Métodos de Input com texto "Opção: "
    static string LerOpcao();

    // Métodos de Output Simples
    // Usaremos PrintMensagem(string) para imprimir mensagens genéricas
    static void PrintMenssagem(const string &mensagem);

    // Usaremos para imprimir perguntas linha por linha
    static void Pergunta(const string &mensagem);

    // Usaremos para imprimir prguntas na mesma linha
    static void SubPergunta(const string &mensagem);
};

#endif //GERENCIADOR_DE_HOTEIS_UNB_CONSOLEIO_HPP