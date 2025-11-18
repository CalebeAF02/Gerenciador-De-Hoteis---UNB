//
// Created by caleb on 16/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAHOSPEDE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAHOSPEDE_H

#include <vector>
#include "sqlite3.h"
#include "Hospede.hpp"

using namespace std;
namespace Hotelaria {
    class PersistenciaHospede {
        string caminho = "Dados_Hospedes.txt";

    public:
        vector<Hospede *> listar();

        bool criar(Hospede &gerente);
    };
}

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAHOSPEDE_H