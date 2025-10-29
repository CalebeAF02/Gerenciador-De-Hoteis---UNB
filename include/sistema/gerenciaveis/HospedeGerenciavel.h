//
// Created by caleb on 16/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_HOSPEDEGERENCIAVEL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_HOSPEDEGERENCIAVEL_H

#include "InterfaceGerenciavel.h"
#include "PersistenciaHospede.h"
#include "PersistenciaSolicitacaoHospedagem.h"
#include "TextoApresentacao.h"

class HospedeGerenciavel : public InterfaceGerenciavel
{
    PersistenciaHospede dao;

public:
    void criar() override;
    void ler() override;
    void atualizar() override;
    bool remover() override;
    void avaliarSolicitacoes();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_HOSPEDEGERENCIAVEL_H