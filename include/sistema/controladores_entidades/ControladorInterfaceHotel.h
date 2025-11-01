//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOTEL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOTEL_H

#include <iostream>

#include "InterfaceApresentacaoCRUD.h"
#include "TextoApresentacao.h"
#include "InterfaceApresentacaoExibirMenu.h"
#include "PersistenciaHotel.h"

#include "Menu.h"
#include "MenuItem.h"

#include "Hotel.h"
#include "Nome.h"
#include "Endereco.h"
#include "Telefone.h"
#include "Codigo.h"

using namespace std;

class ControladorInterfaceHotel : public InterfaceApresentacaoExibirMenu,
                                  public InterfaceApresentacaoCRUD {
public:
    // Construtor dos servicosHotel
    ControladorInterfaceHotel() = default;

    // Acessando servicos
    void exibirMenu() override;

    // Menu CRUD
    void exibirMenuCRUD();

    // Metods CRUD
    void criar() override;

    void ler() override;

    void atualizar() override;

    bool remover() override;
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOTEL_H