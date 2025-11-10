//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOTEL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOTEL_H

#include <iostream>
#include <string>
#include <optional>

#include "ValidadorNumerico.hpp"
#include "InterfaceApresentacaoCRUD.hpp"
#include "InterfaceApresentacaoExibirMenu.hpp"
#include "PersistenciaHotel.hpp"
#include "IO.hpp"
#include "Formato.hpp"
#include "Tabela.hpp"
#include "Linha.hpp"

#include "Menu.hpp"
#include "MenuItem.hpp"

#include "Hotel.hpp"
#include "Nome.hpp"
#include "Endereco.hpp"
#include "Telefone.hpp"
#include "Codigo.hpp"

using namespace std;
using namespace VisualizadorDeTabela;

class ControladorInterfaceHotel : public InterfaceApresentacaoExibirMenu,
                                  public InterfaceApresentacaoCRUD {
private:
    PersistenciaHotel persistencia;
    bool executando = true;

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