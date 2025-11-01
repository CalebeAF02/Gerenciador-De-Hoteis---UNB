//
// Created by caleb on 10/10/2025.
//

#include "ServicosGerente.h"

#include "FabricaGerenciavel.h"
#include "GerenteGerenciavel.h"
#include "HospedeGerenciavel.h"
#include "Menu.h"
#include "ServicosHospede.h"
#include "ServicosHotel.h"
#include "ServicosQuarto.h"
#include "ServicosReserva.h"
#include "sqlite3.h"

void ServicosGerente::exibirCentralDeServicosGerentes() {
    bool status = true;
    while (this->getEstaLogado()) {
        FabricaGerenciavel<GerenteGerenciavel> fabrica;
        fabrica.executarMenu(status);
        if (status == false) {
            break;
        }
    };
}

/*
void ServicosGerente::excluirMeuCadastro()
{
    if (!gerenteEstaLogado)
    {
        cout << "Voce precisa estar logado para excluir seu cadastro.\n";
        return;
    }
    PersistenciaGerente persistencia;
    bool sucesso = persistencia.excluirPorEmailDoBD(logGerente);

    if (sucesso)
    {
        gerenteEstaLogado = false;
        logGerente = nullptr;
        executando = false; // ou redireciona para menu principal
    }
    else
    {
        cout << "Nao foi possivel excluir seu cadastro.\n";
    }
}
*/