//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCARTAO_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCARTAO_H

#include "Cartao.hpp"
#include <vector>
#include <string>

#include "../../libs/teste/InterfaceDeTestes.hpp"
#include "../../libs/io/IO.hpp"

using namespace Teste;
using namespace Hotelaria;

class TesteCartao : public InterfaceDeTeste {
public:
    void executar() override;
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSCARTAO_H