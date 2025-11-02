cmake_minimum_required(VERSION 3.10)
project(Gerenciador-De-Hoteis---UNB)

set(CMAKE_CXX_STANDARD 17)

# Declara a biblioteca SQLite como externa
add_library(sqlite3 STATIC IMPORTED)
set_target_properties(sqlite3 PROPERTIES
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/libsqlite3.a
        INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/include/libs/sqlite
)

# Fontes principais
add_executable(Gerenciador-De-Hoteis---UNB
        src/main.cpp

        # Sistema
        src/sistema/Sistema.cpp
        src/sistema/BancoDeDados.cpp

        # Controladores de Entidades
        src/sistema/controladores_entidades/ControladorInterfaceGerente.cpp
        src/sistema/controladores_entidades/ControladorInterfaceHospede.cpp
        src/sistema/controladores_entidades/ControladorInterfaceHotel.cpp
        src/sistema/controladores_entidades/ControladorInterfaceQuarto.cpp
        src/sistema/controladores_entidades/ControladorInterfaceReserva.cpp

        # Controladores de Métodos
        src/sistema/controladores_metodos/ControladorInterfaceGerenteAutenticavel.cpp

        # Domínios
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

        # Fábricas
        src/sistema/fabricas/FabricaGerenciavel.cpp

        # Interfaces - Apresentações
        src/sistema/interfaces/apresentacoes/InterfaceApresentacaoAutenticavel.cpp
        src/sistema/interfaces/apresentacoes/InterfaceApresentacaoExibirMenu.cpp
        src/sistema/interfaces/apresentacoes/InterfaceApresentacaoCRUD.cpp

        # Interfaces - Serviços
        src/sistema/interfaces/servicos/InterfaceServicoAutenticavel.cpp

        # Interfaces - Gerais
        src/sistema/interfaces/InterfaceFabricaGerenciavel.cpp

        # Persistências
        src/sistema/persistencias/PersistenciaGerente.cpp
        src/sistema/persistencias/PersistenciaHospede.cpp
        src/sistema/persistencias/PersistenciaHotel.cpp
        src/sistema/persistencias/PersistenciaSolicitacaoHospedagem.cpp

        # Serviços
        src/sistema/servicos/ServicoAutenticavel.cpp

        # Utilitários
        src/sistema/utilitarios/Data.cpp
        src/sistema/utilitarios/TextoApresentacao.cpp
        src/sistema/utilitarios/LinhaTSV.cpp
        src/sistema/utilitarios/Menu.cpp
        src/sistema/utilitarios/MenuItem.cpp

        # Validadores principais
        src/sistema/validadores_principais/ValidarInt.cpp
        src/sistema/validadores_principais/ValidarString.cpp

        # Testes - Interface
        tests/interface_tests/InterfaceDeTeste.cpp
        tests/interface_tests/TestsModulares.cpp

        # Testes - Smoke
        tests/smoke_testes/Smoke_Tests.cpp

        # Testes - Domínios
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

        # Testes - Entidades
        tests/tests_entidades/TestsGerente.cpp
        tests/tests_entidades/TestsHospede.cpp
        tests/tests_entidades/TestsHotel.cpp
        tests/tests_entidades/TestsQuarto.cpp
        tests/tests_entidades/TestsReserva.cpp
)

# Diretórios de headers
target_include_directories(Gerenciador-De-Hoteis---UNB PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/sistema
        ${CMAKE_SOURCE_DIR}/include/sistema/servicos
        ${CMAKE_SOURCE_DIR}/include/sistema/dominios
        ${CMAKE_SOURCE_DIR}/include/sistema/entidades
        ${CMAKE_SOURCE_DIR}/include/sistema/enum
        ${CMAKE_SOURCE_DIR}/include/sistema/fabricas
        ${CMAKE_SOURCE_DIR}/include/sistema/interfaces
        ${CMAKE_SOURCE_DIR}/include/sistema/interfaces/apresentacoes
        ${CMAKE_SOURCE_DIR}/include/sistema/interfaces/servicos
        ${CMAKE_SOURCE_DIR}/include/sistema/persistencias
        ${CMAKE_SOURCE_DIR}/include/sistema/controladores_entidades
        ${CMAKE_SOURCE_DIR}/include/sistema/controladores_metodos
        ${CMAKE_SOURCE_DIR}/include/sistema/utilitarios
        ${CMAKE_SOURCE_DIR}/include/sistema/validadorPrincipais
        ${CMAKE_SOURCE_DIR}/include/libs/sqlite
        ${CMAKE_SOURCE_DIR}/tests
        ${CMAKE_SOURCE_DIR}/tests/interface_tests
        ${CMAKE_SOURCE_DIR}/tests/smoke_testes
        ${CMAKE_SOURCE_DIR}/tests/tests_dominios
        ${CMAKE_SOURCE_DIR}/tests/tests_entidades
)

# Linka com o executável principal
target_link_libraries(Gerenciador-De-Hoteis---UNB sqlite3)
