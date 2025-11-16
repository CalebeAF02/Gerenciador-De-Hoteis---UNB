//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSTELEFONE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSTELEFONE_H

#include "../../libs/teste/InterfaceDeTestes.hpp"
#include "Telefone.hpp"
#include <vector>
#include <string>
#include "../../libs/io/IO.hpp"

using namespace Teste;
using namespace Hotelaria;

class TesteTelefone : public InterfaceDeTeste {
public:
    void executar() override;
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSTELEFONE_H