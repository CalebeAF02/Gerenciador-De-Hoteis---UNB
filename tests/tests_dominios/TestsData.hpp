//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSDATA_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSDATA_H

#include "InterfaceDeTeste.hpp"
#include "Data.hpp"
#include <vector>
#include <string>
#include  "ConsoleIO.hpp"

class TestsData : public InterfaceDeTeste {
public:
    void executar() override;

    string nomeDoTeste() const override { return "TestsData"; }

private:
    void testarDatasValidas();

    void testarDatasComFormatoInvalido();

    void testarDatasComDiaInvalido();

    void testarDatasComMesInvalido();

    void testarDatasComAnoInvalido();

    void testarDatasBissextas();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSDATA_H