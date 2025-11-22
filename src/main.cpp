#include "Sistema.hpp"
#include "SistemaHacker.hpp"

#include <iostream>
#include <string>
#include "sqlite3.h"

#include "Formato.hpp"

#include "SmokeTeste.hpp"
#include "TestandoSmoke.hpp"
#include "InterfaceDeTestes.hpp"
#include "BancoDeDados.hpp"

// Testes de domínios
#include "TesteCapacidade.hpp"
#include "TesteCartao.hpp"
#include "TesteCodigo.hpp"
#include "TesteDinheiro.hpp"
#include "TesteEmail.hpp"
#include "TesteEndereco.hpp"
#include "TesteNome.hpp"
#include "TesteNumero.hpp"
#include "TesteRamal.hpp"
#include "TesteSenha.hpp"
#include "TesteTelefone.hpp"

// Testes de entidades
#include "TesteGerente.hpp"
#include "TesteHospede.hpp"
#include "TesteHotel.hpp"
#include "TesteQuarto.hpp"
#include "TesteReserva.hpp"

#include "sistema/utilitarios/Modos.hpp"

using namespace std;
using namespace Hotelaria;


MODOS MODO_ATUAL = MODOS::MODO_HACKER;


int main() {
    BancoDeDados banco;
    banco.iniciar();

    // Escolhendo modo de execução
    switch (MODO_ATUAL) {
        case MODOS::MODO_SMOKE: {
            TestandoSmoke teste;
            teste.executarSmokeTest();
            InterfaceDeTeste::mostrarRelatorioDeTestes();
            break;
        }
        case MODOS::MODO_PRODUCAO: {
            Sistema sistema;
            sistema.iniciar();
            break;
        }
        case MODOS::MODO_HACKER: {
            SistemaHacker sistema_hacker;
            sistema_hacker.iniciar();
            break;
        }
    }
    return 0;
}