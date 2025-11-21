//
// Created by caleb on 16/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAHOSPEDE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAHOSPEDE_H

#include "InterfacePersistenciaHospede.hpp"
#include "Hospede.hpp"
#include "HospedeDTO.hpp"

#include "BancoDeDados.hpp"

#include <iostream>
#include <vector>
#include <optional>
#include "sqlite3.h"

using namespace std;

namespace Hotelaria {
    class ControladoraPersistenciaHospede : public InterfacePersistenciaHospede {
        string caminho = "Dados_Hospedes.txt";

    public:
        bool inserir(const Hospede &hospede) override;

        bool autenticar(const string &email, const string &senha) override;

        vector<HospedeDTO> listar() override;

        optional<HospedeDTO> pesquisar(const int &id) override;

        bool atualizar(const Email &email, const Hospede &hospede) override;

        bool excluir(const int &id) override;
    };
}

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAHOSPEDE_H