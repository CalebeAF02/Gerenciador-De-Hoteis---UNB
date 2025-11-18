//
// Created by caleb on 10/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOTEL_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOTEL_H

#include <iostream>
#include <string>
#include <optional>

#include "Utils.hpp"
#include "../../../../../libs/menu/MenuCRUD.hpp"
#include "../../../../../libs/menu/ExibirMenu.hpp"
#include "../modulo_persistencia_hotel/PersistenciaHotel.hpp"
#include "../../../../../libs/io/IO.hpp"
#include "../../../../../libs/formato/Formato.hpp"
#include "Tabela.hpp"
#include "Linha.hpp"

#include "../../../../../libs/menu/Menu.hpp"
#include "MenuItem.hpp"

#include "Hotel.hpp"
#include "Nome.hpp"
#include "Endereco.hpp"
#include "Telefone.hpp"
#include "Codigo.hpp"

using namespace std;
using namespace VisualizadorDeTabela;
using namespace VisualizadorDeMenu;
namespace Hotelaria {
    class ControladorInterfaceHotel : public ExibirMenu,
                                      public MenuCRUD {
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

        void remover() override;
    };
}
#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_SERVICOSHOTEL_H