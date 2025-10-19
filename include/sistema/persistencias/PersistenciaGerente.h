//
// Created by caleb on 16/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H

#include "PersistenciaGenerica.h"
#include "Gerente.h"

using namespace std;

class PersistenciaGerente
{
    string caminho = "Dados_Gerentes.txt";
    PersistenciaGenerica<Gerente> dao;

public:
    vector<Gerente> listar()
    {
        return dao.ler(caminho);
    }

    void salvarTodos(const vector<Gerente>& lista)
    {
        dao.salvar(lista, caminho);
    }

    void adicionar(const Gerente& novo)
    {
        auto lista = listar();
        lista.push_back(novo);
        salvarTodos(lista);
    }

    bool excluirPorEmail(const string& email)
    {
        bool status = false;
        vector<Gerente> lista = listar();
        for (int i = 0; i < lista.size(); i++)
        {
            if (email == lista[i].getEmail())
            {
                // eras== apagar;
                // begin == contador
                lista.erase(lista.begin() + i);
                status = true;
                break;
            }
        }
        salvarTodos(lista);
        return status;
    }

    void editarPorEmail(const string& email, const Gerente& atualizado)
    {
        auto lista = listar();
        for (auto& g : lista)
        {
            if (g.getEmail() == email)
            {
                g = atualizado;
                break;
            }
        }
        salvarTodos(lista);
    }
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H