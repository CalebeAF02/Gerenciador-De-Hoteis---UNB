//
// Created by caleb on 19/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAGERENCIAVEL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAGERENCIAVEL_H
#include <memory>

#include "../../../libs/menu/Menu.hpp"
#include "../../../libs/formato/Formato.hpp"

using namespace std;
using namespace VisualizadorDeMenu;
template<typename T>
class FabricaGerenciavel {
public:
    shared_ptr<T> criar() {
        //shared_ptr == Classe de compartilhamento de ponteiros por referencia
        //make_shared == criar um objeto de ponteiro compartilhado
        shared_ptr<T> objeto = make_shared<T>();
        // objeto == FabricaGerenciavel do tipo T.
        // se T == GerenteGerenciavel ; Estou criando umafabrica de gerente gerenciavel.
        objeto->criar();
        return objeto;
    }

    void ler() {
        //shared_ptr == Classe de compartilhamento de ponteiros por referencia
        //make_shared == criar um objeto de ponteiro compartilhado
        shared_ptr<T> objeto = make_shared<T>();
        // objeto == FabricaGerenciavel do tipo T.
        // se T == GerenteGerenciavel ; Estou criando umafabrica de gerente gerenciavel.
        objeto->ler();
    }

    void atualizar() {
        //shared_ptr == Classe de compartilhamento de ponteiros por referencia
        //make_shared == criar um objeto de ponteiro compartilhado
        shared_ptr<T> objeto = make_shared<T>();
        // objeto == FabricaGerenciavel do tipo T.
        // se T == GerenteGerenciavel ; Estou criando umafabrica de gerente gerenciavel.
        objeto->atualizar();
    }

    void remover() {
        //shared_ptr == Classe de compartilhamento de ponteiros por referencia
        //make_shared == criar um objeto de ponteiro compartilhado
        shared_ptr<T> objeto = make_shared<T>();
        // objeto == FabricaGerenciavel do tipo T.
        // se T == GerenteGerenciavel ; Estou criando umafabrica de gerente gerenciavel.
        objeto->remover();
    }

    void executarMenu(string tituloStr, bool &executando) {
        Menu menu;

        const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
        const int OPCAO_CRIAR = menu.adcionarItens("criar");
        const int OPCAO_LER = menu.adcionarItens("Ler");
        const int OPCAO_ATUALIZAR = menu.adcionarItens("Atualizar");
        const int OPCAO_REMOVER = menu.adcionarItens("Remover");

        int opcao = menu.executa(tituloStr);

        if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
            executando = false;
            IO::Println("Voce Saiu do Menu CRUD!");
            return;
        } else if (opcao == OPCAO_CRIAR) criar();
        else if (opcao == OPCAO_LER) ler();
        else if (opcao == OPCAO_ATUALIZAR) atualizar();
        else if (opcao == OPCAO_REMOVER) remover();
    }
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_FABRICAGERENCIAVEL_H