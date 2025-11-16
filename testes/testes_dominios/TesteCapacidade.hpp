//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCAPACIDADE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCAPACIDADE_H

#include "Capacidade.hpp"
#include <vector>

#include "../../libs/teste/InterfaceDeTestes.hpp"
#include "../../libs/io/IO.hpp"

using namespace std;

using namespace Teste;
using namespace Hotelaria;

class TesteCapacidade : public InterfaceDeTeste {
public:
    void executar() override;
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCAPACIDADE_H