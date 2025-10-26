//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSDATA_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSDATA_H

#include "../interface_tests/TestsBase.h"
#include "../../utilitarios/Data.h"
#include <vector>
#include <string>

class TestsData : public TestsBase
{
public:
    void executar() override;
    std::string nome() const override { return "TestsData"; }

private:
    void testarDatasValidas();
    void testarDatasComFormatoInvalido();
    void testarDatasComDiaInvalido();
    void testarDatasComMesInvalido();
    void testarDatasComAnoInvalido();
    void testarDatasBissextas();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSDATA_H