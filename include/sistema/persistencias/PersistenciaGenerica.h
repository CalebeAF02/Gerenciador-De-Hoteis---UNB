//
// Created by caleb on 16/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGENERICA_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGENERICA_H

#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

template <typename T>
class PersistenciaGenerica
{
public:
    std::vector<T> ler(const std::string& caminho)
    {
        std::vector<T> lista;
        std::ifstream arquivo(caminho);
        std::string linha;

        while (getline(arquivo, linha))
        {
            T obj;
            obj.setTSV(linha); // reconstrói o objeto
            lista.push_back(obj);
        }

        return lista;
    }

    void salvar(const std::vector<T>& lista, const std::string& caminho)
    {
        std::ofstream arquivo(caminho);
        for (const T& obj : lista)
        {
            arquivo << obj.getTSV() << std::endl;
        }
    }
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGENERICA_H
