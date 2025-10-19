//
// Created by caleb on 16/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGENERICA_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGENERICA_H

#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
class PersistenciaGenerica
{
public:
    vector<T> ler(const std::string& caminho)
    {
        vector<T> lista;
        ifstream arquivo(caminho);
        string linha;

        while (getline(arquivo, linha))
        {
            T obj;
            obj.setTSV(linha); // reconstrói o objeto
            lista.push_back(obj);
        }

        return lista;
    }

    void salvar(const vector<T>& lista, const string& caminho)
    {
        ofstream arquivo(caminho);
        for (const T& obj : lista)
        {
            arquivo << obj.getTSV() << endl;
        }
    }
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGENERICA_H