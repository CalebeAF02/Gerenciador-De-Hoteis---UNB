cmake_minimum_required(VERSION 3.10)
project(Gerenciador-De-Hoteis---UNB)

set(CMAKE_CXX_STANDARD 17)

# Declara a biblioteca SQLite como externa
add_library(sqlite3 STATIC IMPORTED)
set_target_properties(sqlite3 PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/libsqlite3.a)

# Inclui o diretório dos headers
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/libs/sqlite)

# Diretorios de headers
include_directories(
        #includes
        include

        include/sistema
        include/sistema/apresentacao
        include/sistema/dominios
        include/sistema/entidades
        include/sistema/enum
        include/sistema/fabricas
        include/sistema/gerenciaveis
        include/sistema/interfaces
        include/sistema/persistencias
        include/sistema/servicos
        include/sistema/utilitarios
        include/sistema/validadorPrincipais
        include/libs/sqlite

        libs

        tests
        tests/interface_tests
        tests/smoke_testes
        tests/tests_dominios
        tests/tests_entidades

        confiruracoes
        docs
        imagens

)

# Fontes principais
add_executable(Gerenciador-De-Hoteis---UNB
        src/main.cpp

        #Sistamas
        src/sistema/Sistema.cpp

        # Apresentacao
        src/sistema/apresentacao/ApresentacaoAutenticavel.cpp

        # Dominios
        src/sistema/dominios/Nome.cpp
        src/sistema/dominios/Email.cpp
        src/sistema/dominios/Ramal.cpp
        src/sistema/dominios/Senha.cpp
        src/sistema/dominios/Endereco.cpp
        src/sistema/dominios/Cartao.cpp
        src/sistema/dominios/Telefone.cpp
        src/sistema/dominios/Codigo.cpp
        src/sistema/dominios/Numero.cpp
        src/sistema/dominios/Capacidade.cpp
        src/sistema/dominios/Dinheiro.cpp

        # Entidades
        src/sistema/entidades/Gerente.cpp
        src/sistema/entidades/Hospede.cpp
        src/sistema/entidades/Hotel.cpp
        src/sistema/entidades/Pessoa.cpp
        src/sistema/entidades/Quarto.cpp
        src/sistema/entidades/Reserva.cpp
        src/sistema/entidades/SolicitacaoHospedagem.cpp

        # Enum
        src/sistema/enum/StatusSolicitacaoHospedagem.cpp

        # Fabricas
        src/sistema/fabricas/FabricaGerenciavel.cpp

        # Gerenciaveis
        src/sistema/gerenciaveis/GerenteGerenciavel.cpp
        src/sistema/gerenciaveis/HospedeGerenciavel.cpp

        # interfaces
        src/sistema/interfaces/InterfaceGerenciavel.cpp
        src/sistema/interfaces/InterfaceAutenticavel.cpp
        src/sistema/interfaces/InterfaceFabricaGerenciavel.cpp
        src/sistema/interfaces/InterfaceServicoAutenticacao.cpp

        # Persistencias
        src/sistema/persistencias/PersistenciaGerente.cpp
        src/sistema/persistencias/PersistenciaHospede.cpp
        src/sistema/persistencias/PersistenciaSolicitacaoHospedagem.cpp

        # Servicos
        src/sistema/servicos/ServicosGerente.cpp
        src/sistema/servicos/ServicosHospede.cpp
        src/sistema/servicos/ServicosHotel.cpp
        src/sistema/servicos/ServicosQuarto.cpp
        src/sistema/servicos/ServicosReserva.cpp
        src/sistema/servicos/ServicosAutenticacao.cpp

        #utilitarios
        src/sistema/utilitarios/Data.cpp
        src/sistema/utilitarios/TextoApresentacao.cpp
        src/sistema/utilitarios/LinhaTSV.cpp
        src/sistema/utilitarios/Menu.cpp
        src/sistema/utilitarios/MenuItem.cpp
        src/sistema/utilitarios/GeradorCodigo.cpp

        # ValidadoresPrincipais
        src/sistema/validadores_principais/ValidarInt.cpp
        src/sistema/validadores_principais/ValidarString.cpp

        # Tests
        tests/interface_tests/InterfaceDeTeste.cpp
        tests/interface_tests/TestsModulares.cpp

        tests/smoke_testes/Smoke_Tests.cpp

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

        # Tests_Entidades
        tests/tests_entidades/TestsGerente.cpp
        tests/tests_entidades/TestsHospede.cpp
        tests/tests_entidades/TestsHotel.cpp
        tests/tests_entidades/TestsQuarto.cpp
        tests/tests_entidades/TestsReserva.cpp
        tests/tests_entidades/TestsSolicitacaoHospedagem.cpp
        src/sistema/enum/EnumConversor.cpp
        include/sistema/enum/EnumConversor.h
)

# Linka com o executável principal
target_link_libraries(Gerenciador-De-Hoteis---UNB sqlite3)
