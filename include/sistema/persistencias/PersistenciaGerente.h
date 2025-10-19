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

    void excluirPorEmail(const string& email)
    {
        auto lista = listar();
        lista.erase(
            remove_if(lista.begin(), lista.end(),
                      [&](const Gerente& g) { return g.getEmail() == email; }),
            lista.end()
        );
        salvarTodos(lista);
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