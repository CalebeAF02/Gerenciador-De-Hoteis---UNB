#include "TestsData.hpp"
#include <iostream>
#include <vector>

void TestsData::executar() {
    testarDatasValidas();
    testarDatasComFormatoInvalido();
    testarDatasComDiaInvalido();
    testarDatasComMesInvalido();
    testarDatasComAnoInvalido();
    testarDatasBissextas();
}

void TestsData::testarDatasValidas() {
    std::vector<std::string> datas;
    datas.push_back("01/01/2000");
    datas.push_back("15/06/2025");
    datas.push_back("31/12/2099");
    datas.push_back("30/04/2023");
    datas.push_back("28/02/2024");

    for (std::size_t i = 0; i < datas.size(); ++i) {
        std::string dataStr = datas[i];
        apresentacaoTesteData(dataStr);
        try {
            Data d(dataStr);
            checaResultado(DEVE_DAR_CERTO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_CERTO, apresentacaoErro(e));
        }
    }
}

void TestsData::testarDatasComFormatoInvalido() {
    std::vector<std::string> datas;
    datas.push_back("01-01-2000");
    datas.push_back("01012000");
    datas.push_back("01/01/00");
    datas.push_back("1/1/2000");
    datas.push_back("01/01/2000 ");

    for (std::size_t i = 0; i < datas.size(); ++i) {
        std::string dataStr = datas[i];
        apresentacaoTesteData(dataStr);
        try {
            Data d(dataStr);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsData::testarDatasComDiaInvalido() {
    std::vector<std::string> datas;
    datas.push_back("32/01/2025");
    datas.push_back("00/05/2025");
    datas.push_back("31/04/2025");
    datas.push_back("29/02/2023");

    for (std::size_t i = 0; i < datas.size(); ++i) {
        std::string dataStr = datas[i];
        apresentacaoTesteData(dataStr);
        try {
            Data d(dataStr);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsData::testarDatasComMesInvalido() {
    std::vector<std::string> datas;
    datas.push_back("15/00/2025");
    datas.push_back("10/13/2025");
    datas.push_back("01/-1/2025");

    for (std::size_t i = 0; i < datas.size(); ++i) {
        std::string dataStr = datas[i];
        apresentacaoTesteData(dataStr);
        try {
            Data d(dataStr);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsData::testarDatasComAnoInvalido() {
    std::vector<std::string> datas;
    datas.push_back("01/01/1999");
    datas.push_back("31/12/2100");
    datas.push_back("15/06/0000");

    for (std::size_t i = 0; i < datas.size(); ++i) {
        std::string dataStr = datas[i];
        apresentacaoTesteData(dataStr);
        try {
            Data d(dataStr);
            checaResultado(DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            checaResultado(DEVE_DAR_ERRADO, apresentacaoErro(e));
        }
    }
}

void TestsData::testarDatasBissextas() {
    std::vector<std::string> datas;
    datas.push_back("29/02/2024");
    datas.push_back("29/02/2020");
    datas.push_back("29/02/2023");
    datas.push_back("29/02/2100");

    for (std::size_t i = 0; i < datas.size(); ++i) {
        std::string dataStr = datas[i];
        apresentacaoTesteData(dataStr);
        try {
            Data d(dataStr);
            bool isBissexto = (dataStr == "29/02/2024" || dataStr == "29/02/2020");
            checaResultado(isBissexto ? DEVE_DAR_CERTO : DEVE_DAR_ERRADO, apresentacaoSucesso());
        } catch (std::invalid_argument &e) {
            bool esperadoErro = (dataStr == "29/02/2023" || dataStr == "29/02/2100");
            checaResultado(esperadoErro ? DEVE_DAR_ERRADO : DEVE_DAR_CERTO, apresentacaoErro(e));
        }
    }
}