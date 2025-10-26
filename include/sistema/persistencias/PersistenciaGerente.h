//
// Created by caleb on 16/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H

#include <vector>

#include "Gerente.h"
#include "ServicosGerente.h"

using namespace std;

class PersistenciaGerente
{
public:
    bool adicionarAoBD(Gerente& gerente);

    vector<Gerente*> listarBD();

    Gerente* autenticarGerentePeloBD(const std::string& email, const std::string& senha);

    bool atualizarGerenteNoBD(const Gerente& gerente);

    static bool excluirPorEmailDoBD(Gerente* gerenteLogado);
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIAGERENTE_H