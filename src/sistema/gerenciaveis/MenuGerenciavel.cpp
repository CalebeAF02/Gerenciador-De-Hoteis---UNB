//
// Created by caleb on 16/10/2025.
//

#include "MenuGerenciavel.h"
#include "TextoApresentacao.h"

void executarMenu(InterfaceFabricaGerenciavel& fabrica, bool& status)
{
    auto objeto = fabrica.criar();

    std::string opcao;

    TextoApresentacao::MostrarOpcao("Sair", 0);
    TextoApresentacao::MostrarOpcao("Criar", 1);
    TextoApresentacao::MostrarOpcao("Ler", 2);
    TextoApresentacao::MostrarOpcao("Atualizar", 3);
    TextoApresentacao::MostrarOpcao("Excluir", 4);

    std::cout << "Escolha: ";
    std::getline(std::cin, opcao);

    if (opcao == "1") objeto->criar();
    else if (opcao == "2") objeto->ler();
    else if (opcao == "3") objeto->atualizar();
    else if (opcao == "4") objeto->excluir();
    else if (opcao == "0")
    {
        status = false;
        cout << "Voce Saiu da Central de servicos e foi deslogado!" << endl;
        return;
    };
}
