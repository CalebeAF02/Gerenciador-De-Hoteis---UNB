//
// Created by caleb on 16/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H

#include <vector>

#include "Gerente.h"

using namespace std;

class PersistenciaGerente
{
public:
    vector<Gerente*> listar();

    bool criar(Gerente& gerente);

    bool excluirPorEmail(const std::string& email);
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H