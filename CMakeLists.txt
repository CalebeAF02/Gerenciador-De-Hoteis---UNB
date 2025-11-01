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
        include/sistema/servicos
        include/sistema/dominios
        include/sistema/entidades
        include/sistema/enum
        include/sistema/fabricas
        include/sistema/interfaces
        include/sistema/interfaces/apresentacoes
        include/sistema/interfaces/servicos
        include/sistema/persistencias
        include/sistema/controladores_entidades
        include/sistema/controladores_metodos
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
        src/sistema/BancoDeDados.cpp

        # Controladore_Entidades
        src/sistema/controladores_entidades/ControladorInterfaceGerente.cpp
        src/sistema/controladores_entidades/ControladorInterfaceHospede.cpp
        src/sistema/controladores_entidades/ControladorInterfaceHotel.cpp
        src/sistema/controladores_entidades/ControladorInterfaceQuarto.cpp
        src/sistema/controladores_entidades/ControladorInterfaceReserva.cpp

        # Controladores_Metodos
        src/sistema/controladores_metodos/ControladorInterfaceGerenteAutenticavel.cpp

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
        src/sistema/enum/EnumConversor.cpp

        # Fabricas
        src/sistema/fabricas/FabricaGerenciavel.cpp


        ## Interface apresentacoes
        src/sistema/interfaces/apresentacoes/InterfaceApresentacaoAutenticavel.cpp
        src/sistema/interfaces/apresentacoes/InterfaceApresentacaoExibirMenu.cpp
        src/sistema/interfaces/apresentacoes/InterfaceApresentacaoCRUD.cpp

        ## Interface Servicos
        src/sistema/interfaces/servicos/InterfaceServicoAutenticavel.cpp

        # Interface
        src/sistema/interfaces/InterfaceFabricaGerenciavel.cpp

        # Persistencias
        src/sistema/persistencias/PersistenciaGerente.cpp
        src/sistema/persistencias/PersistenciaHospede.cpp
        src/sistema/persistencias/PersistenciaHotel.cpp
        src/sistema/persistencias/PersistenciaSolicitacaoHospedagem.cpp

        # Servicos
        src/sistema/servicos/ServicoAutenticavel.cpp

        #utilitarios
        src/sistema/utilitarios/Data.cpp
        src/sistema/utilitarios/TextoApresentacao.cpp
        src/sistema/utilitarios/LinhaTSV.cpp
        src/sistema/utilitarios/Menu.cpp
        src/sistema/utilitarios/MenuItem.cpp

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
)

# Linka com o executável principal
target_link_libraries(Gerenciador-De-Hoteis---UNB sqlite3)
