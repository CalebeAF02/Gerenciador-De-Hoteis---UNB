//
// Created by caleb on 02/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_CONSOLEIO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_CONSOLEIO_HPP

#include <iostream>
#include <string>
#include <limits> // Para clear/ignore do buffer se necessário
#include "../formato/Formato.hpp"

using namespace std;

// Classe responsável pela manipulação de entrada e saída de dados simples.
namespace  IO {
    // Métodos de Input
    string LerLinha();

    // Métodos de Input com texto "Opção: "
    string LerOpcao();

    // Opção para tentar novamente ou sair
    bool tentarNovamente();

    // Métodos de Output Simples
    // Usaremos para imprimir uma mensagens e pular uma linha
    void Println(const string &mensagem);

    // Usaremos para imprimir mensagens na mesma linha
    void Print(const string &mensagem);
};

#endif //GERENCIADOR_DE_HOTEIS_UNB_CONSOLEIO_HPP