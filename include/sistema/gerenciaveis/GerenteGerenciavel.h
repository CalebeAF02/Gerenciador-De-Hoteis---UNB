//
// Created by caleb on 16/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_GERENTEGERENCIAVEL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_GERENTEGERENCIAVEL_H

#include "InterfaceGerenciavel.h"
#include "PersistenciaGerente.h"
#include "../utilitarios/TextoApresentacao.h"

class GerenteGerenciavel : public InterfaceGerenciavel
{
    Gerente* gerenteLogado;
    PersistenciaGerente dao;

public:
    void criar() override;
    void ler() override;
    void atualizar() override;
    bool remover() override;

    void setGerenteLogado(Gerente* gerente)
    {
        this->gerenteLogado = gerente;
    }
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_GERENTEGERENCIAVEL_H