//
// Created by caleb on 26/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIASOLICITACAOHOSPEDAGEM_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIASOLICITACAOHOSPEDAGEM_H

#include "../entidades/SolicitacaoHospedagem.h"
#include "BancoDeDados.h"
#include <vector>
#include <string>

class PersistenciaSolicitacaoHospedagem {
public:
    static void inicializar();

    static void salvar(const SolicitacaoHospedagem &s);

    static std::vector<SolicitacaoHospedagem> buscarPorEmail(const std::string &email);

    static std::vector<SolicitacaoHospedagem> buscarPorStatus(int status);

    static void atualizar(const SolicitacaoHospedagem &s);
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_PERSISTENCIASOLICITACAOHOSPEDAGEM_H