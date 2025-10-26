cmake_minimum_required(VERSION 3.10)
project(gerenciador_hotel_unb)

set(CMAKE_CXX_STANDARD 17)

# Diretorios de headers
include_directories(
        #includes
        include

        include/dominios

        include/entidades

        include/sistema
        include/sistema/fabricas
        include/sistema/gerenciaveis
        include/sistema/interfaces
        include/sistema/persistencias
        include/sistema/servicos
        include/sistema/Modelagem_E_LogicaDeServico/apresentacao
        include/sistema/Modelagem_E_LogicaDeServico/interfaces
        include/sistema/Modelagem_E_LogicaDeServico/servicos_-_

        include/utilitarios

        include/validadorPrincipais

        #outros
        libs
        libs/sqlite

        tests
        tests/interface_tests
        tests/smoke_testes
        tests/tests_dominios
        tests/tests_entidades
)

# Fontes principais
add_executable(gerenciador_hotel_unb
        src/main.cpp

        # Entidades
        src/entidades/Gerente.cpp
        src/entidades/Hospede.cpp
        src/entidades/Hotel.cpp
        src/entidades/Pessoa.cpp
        src/entidades/Quarto.cpp
        src/entidades/Reserva.cpp

        # Dominios
        src/dominios/Nome.cpp
        src/dominios/Email.cpp
        src/dominios/Ramal.cpp
        src/dominios/Senha.cpp
        src/dominios/Endereco.cpp
        src/dominios/Cartao.cpp
        src/dominios/Telefone.cpp
        src/dominios/Codigo.cpp
        src/dominios/Numero.cpp
        src/dominios/Capacidade.cpp
        src/dominios/Dinheiro.cpp


        # ValidadoresPrincipais
        src/validadores_principais/ValidarInt.cpp
        src/validadores_principais/ValidarString.cpp

        #Sistamas
        src/sistema/Sistema.cpp

        src/sistema/fabricas/FabricaGerenciavel.cpp


        src/sistema/gerenciaveis/GerenteGerenciavel.cpp
        src/sistema/gerenciaveis/HospedeGerenciavel.cpp

        src/sistema/interfaces/InterfaceGerenciavel.cpp
        src/sistema/interfaces/InterfaceAutenticavel.cpp
        src/sistema/interfaces/InterfaceFabricaGerenciavel.cpp

        src/sistema/persistencias/PersistenciaGerente.cpp
        src/sistema/persistencias/PersistenciaHospede.cpp

        src/sistema/servicos/ServicosGerente.cpp
        src/sistema/servicos/ServicosHospede.cpp
        src/sistema/servicos/ServicosHotel.cpp
        src/sistema/servicos/ServicosQuarto.cpp
        src/sistema/servicos/ServicosReserva.cpp

        # libs
        libs/sqlite/sqlite3.c

        # Modelagem_E_LogicaServico
        src/sistema/Modelagem_E_LogicaDeServico/apresentacao/ApresentacaoAutenticavel.cpp
        src/sistema/Modelagem_E_LogicaDeServico/interfaces/InterfaceServicoAutenticacao.cpp
        src/sistema/Modelagem_E_LogicaDeServico/servicos_-_/ServicoAutenticacao.cpp

        #utilitarios
        src/utilitarios/Data.cpp
        src/utilitarios/TextoApresentacao.cpp
        src/utilitarios/LinhaTSV.cpp
        src/utilitarios/Menu.cpp
        src/utilitarios/MenuItem.cpp
        src/utilitarios/SolicitacaoHospedagem.cpp
        src/utilitarios/PersistenciaSolicitacaoHospedagem.cpp
        src/utilitarios/GeradorCodigo.cpp

        # Tests
        tests/smoke_testes/Smoke_Tests.cpp
        tests/interface_tests/InterfaceDeTeste.cpp
        tests/interface_tests/TestsModulares.cpp

        # Tests_Entidades
        tests/tests_entidades/TestsGerente.cpp
        tests/tests_entidades/TestsHospede.cpp
        tests/tests_entidades/TestsHotel.cpp
        tests/tests_entidades/TestsQuarto.cpp
        tests/tests_entidades/TestsReserva.cpp
        tests/tests_entidades/TestsSolicitacaoHospedagem.cpp

        # Tests_Dominios
        tests/tests_dominios/TestsCapacidade.cpp
        tests/tests_dominios/TestsCartao.cpp
        tests/tests_dominios/TestsCodigo.cpp
        tests/tests_dominios/TestsDinheiro.cpp
        tests/tests_dominios/TestsEmail.cpp
        tests/tests_dominios/TestsEndereco.cpp
        tests/tests_dominios/TestsNome.cpp
        tests/tests_dominios/TestsNumero.cpp
        tests/tests_dominios/TestsRamal.cpp
        tests/tests_dominios/TestsSenha.cpp
        tests/tests_dominios/TestsTelefone.cpp
        tests/tests_dominios/TestsData.cpp

)