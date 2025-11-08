cmake_minimum_required(VERSION 3.10)
project(Gerenciador-De-Hoteis---UNB)

set(CMAKE_CXX_STANDARD 17)

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
        src/sistema/dominios/Data.cpp

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
        src/sistema/utilitarios/Menu.cpp
        src/sistema/utilitarios/MenuItem.cpp

        # Utilitarios - Console
        src/sistema/utilitarios/console/ConsoleFormatter.cpp
        src/sistema/utilitarios/console/ConsoleIO.cpp

        # Validadores principais
        src/sistema/validadores_principais/ValidarInt.cpp
        src/sistema/validadores_principais/ValidarString.cpp

        # Testes - Interface
        testes/interface_testes/InterfaceDeTestes.cpp

        # Testes - Smoke
        testes/smoke_teste/SmokeTeste.cpp
        testes/smoke_teste/TestandoSmoke.cpp

        # Testes - Domínios
        testes/testes_dominios/TesteCapacidade.cpp
        testes/testes_dominios/TesteCartao.cpp
        testes/testes_dominios/TesteCodigo.cpp
        testes/testes_dominios/TesteDinheiro.cpp
        testes/testes_dominios/TesteEmail.cpp
        testes/testes_dominios/TesteEndereco.cpp
        testes/testes_dominios/TesteNome.cpp
        testes/testes_dominios/TesteNumero.cpp
        testes/testes_dominios/TesteRamal.cpp
        testes/testes_dominios/TesteSenha.cpp
        testes/testes_dominios/TesteTelefone.cpp
        testes/testes_dominios/TestesData.cpp

        # Testes - Entidades
        testes/testes_entidades/TesteGerente.cpp
        testes/testes_entidades/TesteHospede.cpp
        testes/testes_entidades/TesteHotel.cpp
        testes/testes_entidades/TesteQuarto.cpp
        testes/testes_entidades/TesteReserva.cpp

        # Include - Sqlite
        libs/sqlite/sqlite3.c
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
        ${CMAKE_SOURCE_DIR}/include/sistema/utilitarios/console
        ${CMAKE_SOURCE_DIR}/include/sistema/validadorPrincipais
        ${CMAKE_SOURCE_DIR}/libs/sqlite
        ${CMAKE_SOURCE_DIR}/testes
        ${CMAKE_SOURCE_DIR}/testes/interface_testes
        ${CMAKE_SOURCE_DIR}/testes/smoke_teste
        ${CMAKE_SOURCE_DIR}/testes/testes_dominios
        ${CMAKE_SOURCE_DIR}/testes/testes_entidades
)
