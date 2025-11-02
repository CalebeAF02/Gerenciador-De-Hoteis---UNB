//
// Created by caleb on 19/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAGERENCIAVEL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAGERENCIAVEL_H
#include <memory>

#include "Menu.hpp"
#include "TextoApresentacao.hpp"

using namespace std;

template <typename T>
class FabricaGerenciavel
{
public:
    shared_ptr<T> criar()
    {
        //shared_ptr == Classe de compartilhamento de ponteiros por referencia
        //make_shared == criar um objeto de ponteiro compartilhado
        shared_ptr<T> objeto = make_shared<T>();
        // objeto == FabricaGerenciavel do tipo T.
        // se T == GerenteGerenciavel ; Estou criando umafabrica de gerente gerenciavel.
        objeto->criar();
        return objeto;
    }

    void ler()
    {
        //shared_ptr == Classe de compartilhamento de ponteiros por referencia
        //make_shared == criar um objeto de ponteiro compartilhado
        shared_ptr<T> objeto = make_shared<T>();
        // objeto == FabricaGerenciavel do tipo T.
        // se T == GerenteGerenciavel ; Estou criando umafabrica de gerente gerenciavel.
        objeto->ler();
    }

    void atualizar()
    {
        //shared_ptr == Classe de compartilhamento de ponteiros por referencia
        //make_shared == criar um objeto de ponteiro compartilhado
        shared_ptr<T> objeto = make_shared<T>();
        // objeto == FabricaGerenciavel do tipo T.
        // se T == GerenteGerenciavel ; Estou criando umafabrica de gerente gerenciavel.
        objeto->atualizar();
    }

    bool remover()
    {
        //shared_ptr == Classe de compartilhamento de ponteiros por referencia
        //make_shared == criar um objeto de ponteiro compartilhado
        shared_ptr<T> objeto = make_shared<T>();
        // objeto == FabricaGerenciavel do tipo T.
        // se T == GerenteGerenciavel ; Estou criando umafabrica de gerente gerenciavel.
        bool status = objeto->remover();
        return status;
    }

    void executarMenu(bool& status)
    {
        Menu menu;

        const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
        const int OPCAO_CRIAR = menu.adcionarItens("criar");
        const int OPCAO_LER = menu.adcionarItens("Ler Gerentes");
        const int OPCAO_ATUALIZAR = menu.adcionarItens("Atualizar");
        const int OPCAO_REMOVER = menu.adcionarItens("Remover");

        int opcao = menu.executa("Voce Entrou na central de servicos");

        if (opcao == OPCAO_VOLTAR_AO_SISTEMA)
        {
            status = false;
            cout << "Voce Saiu da Central de servicos!" << endl;
            return;
        }
        else if (opcao == OPCAO_CRIAR) criar();
        else if (opcao == OPCAO_LER) ler();
        else if (opcao == OPCAO_ATUALIZAR) atualizar();
        else if (opcao == OPCAO_REMOVER) remover();
    }
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAGERENCIAVEL_H
