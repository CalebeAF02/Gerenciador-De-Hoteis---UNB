//
// Created by caleb on 16/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAHOSPEDE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAHOSPEDE_H

#include "PersistenciaGenerica.h"
#include "Hospede.h"

using namespace std;

class PersistenciaHospede
{
    string caminho = "Dados_Hospedes.txt";
    PersistenciaGenerica<Hospede> dao;

public:
    vector<Hospede> listar()
    {
        return dao.ler(caminho);
    }

    void salvarTodos(const vector<Hospede>& lista)
    {
        dao.salvar(lista, caminho);
    }

    void adicionar(const Hospede& novo)
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
                      [&](const Hospede& g) { return g.getEmail() == email; }),
            lista.end()
        );
        salvarTodos(lista);
    }

    void editarPorEmail(const string& email, const Hospede& atualizado)
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

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAHOSPEDE_H