//
// Created by caleb on 26/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIASOLICITACAOHOSPEDAGEM_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIASOLICITACAOHOSPEDAGEM_H

#include "SolicitacaoHospedagem.hpp"
#include "EnumConversor.hpp"
#include "SolicitacaoHospedagem.hpp"

#include "BancoDeDados.hpp"
#include <vector>
#include <string>
#include <sqlite3.h>
#include <iostream>

class PersistenciaSolicitacaoHospedagem {
public:
    static void inicializar();

    static void salvar(const SolicitacaoHospedagem &s);

    static vector<SolicitacaoHospedagem> buscarPorEmail(const string &email);

    static vector<SolicitacaoHospedagem> buscarPorStatus(int status);

    static void atualizar(const SolicitacaoHospedagem &s);
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIASOLICITACAOHOSPEDAGEM_H