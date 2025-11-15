cmake_minimum_required(VERSION 3.10)
project(Gerenciador-De-Hoteis---UNB)

set(CMAKE_CXX_STANDARD 17)

# Caminhos
set(VERSAO_TXT "${CMAKE_CURRENT_SOURCE_DIR}/meta/versao.txt")
set(VERSAO_HPP "${CMAKE_CURRENT_SOURCE_DIR}/include/sistema/Versao.hpp")

# Geração automática do cabeçalho
add_custom_command(
        OUTPUT ${VERSAO_HPP}
        COMMAND ${CMAKE_COMMAND} -DINPUT_FILE=${VERSAO_TXT} -DOUTPUT_FILE=${VERSAO_HPP} -P ${CMAKE_SOURCE_DIR}/meta/atualizar_versao.cmake
        DEPENDS ${VERSAO_TXT}
        COMMENT "Atualizando versão automaticamente..."
)

add_custom_target(gerar_versao DEPENDS ${VERSAO_HPP})

# Fontes principais
add_executable(Gerenciador-De-Hoteis---UNB
        src/main.cpp

        # Sistema
        src/sistema/Sistema.cpp
        src/sistema/BancoDeDados.cpp

        # Sub Sistema
        src/sistema/sub_sistema/ControladoraApresentacaoInicial.cpp

        ## Apresentacao
        src/sistema/sub_sistema/modulo-servico_autenticavel/ControladoraApresentacaoAutenticavel.cpp
        src/sistema/sub_sistema/modulo-servico_pessoal/ControladoraApresentacaoPessoal.cpp
        src/sistema/sub_sistema/modulo-servico_hospede/ControladoraApresentacaoHospede.cpp
        src/sistema/sub_sistema/modulo-servico_hotel/ControladoraApresentacaoHotel.cpp
        src/sistema/sub_sistema/modulo-servico_quarto/ControladoraApresentacaoQuarto.cpp
        src/sistema/sub_sistema/modulo-servico_reserva/ControladoraApresentacaoReserva.cpp

        ## Servico
        src/sistema/sub_sistema/modulo-servico_autenticavel/ControladoraServicoAutenticavel.cpp
        src/sistema/sub_sistema/modulo-servico_pessoal/ControladoraServicoPessoal.cpp
        src/sistema/sub_sistema/modulo-servico_hospede/ControladoraServicoHospede.cpp
        src/sistema/sub_sistema/modulo-servico_hotel/ControladoraServicoHotel.cpp
        src/sistema/sub_sistema/modulo-servico_quarto/ControladoraServicoQuarto.cpp
        src/sistema/sub_sistema/modulo-servico_reserva/ControladoraServicoReserva.cpp

        # Controladores de Entidades
        src/sistema/controladores_entidades/ControladorInterfaceGerente.cpp
        src/sistema/controladores_entidades/ControladorInterfaceHospede.cpp
        src/sistema/controladores_entidades/ControladorInterfaceHotel.cpp
        src/sistema/controladores_entidades/ControladorInterfaceQuarto.cpp
        src/sistema/controladores_entidades/ControladorInterfaceReserva.cpp


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

        # DTO
        src/sistema/dto/HotelDTO.cpp
        src/sistema/dto/GerenteDTO.cpp

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
        src/sistema/interfaces/apresentacoes/InterfaceApresentacaoExibirMenu.cpp
        src/sistema/interfaces/apresentacoes/InterfaceApresentacaoCRUD.cpp


        # Interfaces - Gerais
        src/sistema/interfaces/InterfaceFabricaGerenciavel.cpp

        # Persistências
        src/sistema/persistencias/PersistenciaGerente.cpp
        src/sistema/persistencias/PersistenciaHospede.cpp
        src/sistema/persistencias/PersistenciaHotel.cpp
        src/sistema/persistencias/PersistenciaSolicitacaoHospedagem.cpp

        # Utilitários
        src/sistema/utilitarios/Menu.cpp
        src/sistema/utilitarios/MenuItem.cpp
        src/sistema/utilitarios/ValidadorNumerico.cpp

        # Validadores principais
        src/sistema/validadores_principais/ValidarInt.cpp
        src/sistema/validadores_principais/ValidarString.cpp

        # Versao
        src/sistema/Versao.cpp

        # Testes
        testes/TestandoSmoke.cpp

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

        # Libs - IO
        libs/io/IO.cpp

        # Libs - Formato
        libs/formato/Formato.cpp

        # Libs - Sqlite
        libs/sqlite/sqlite3.c

        # Libs - Tabela
        libs/tabela/Tabela.cpp
        libs/tabela/Linha.cpp
        libs/tabela/Atributo.cpp
        libs/tabela/TamanhoAtributo.cpp

        # Libs - teste
        libs/teste/InterfaceDeTestes.cpp
        libs/teste/SmokeTeste.cpp

        # HACKER
        src/HACKER/SistemaHacker.cpp
)

add_dependencies(Gerenciador-De-Hoteis---UNB gerar_versao)

# Diretórios de headers
target_include_directories(Gerenciador-De-Hoteis---UNB PRIVATE
        ${CMAKE_SOURCE_DIR}/docs
        ${CMAKE_SOURCE_DIR}/docs/diagramas
        ${CMAKE_SOURCE_DIR}/docs/imagens
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/HACKER
        ${CMAKE_SOURCE_DIR}/include/sistema
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/modulo-servico_autenticavel
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/modulo-servico_hospede
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/modulo-servico_hotel
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/modulo-servico_pessoal
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/modulo-servico_quarto
        ${CMAKE_SOURCE_DIR}/include/sistema/sub_sistema/modulo-servico_reserva
        ${CMAKE_SOURCE_DIR}/include/sistema/dominios
        ${CMAKE_SOURCE_DIR}/include/sistema/dto
        ${CMAKE_SOURCE_DIR}/include/sistema/entidades
        ${CMAKE_SOURCE_DIR}/include/sistema/enum
        ${CMAKE_SOURCE_DIR}/include/sistema/fabricas
        ${CMAKE_SOURCE_DIR}/include/sistema/interfaces
        ${CMAKE_SOURCE_DIR}/include/sistema/interfaces/apresentacoes
        ${CMAKE_SOURCE_DIR}/include/sistema/interfaces/servicos
        ${CMAKE_SOURCE_DIR}/include/sistema/persistencias
        ${CMAKE_SOURCE_DIR}/include/sistema/controladores_entidades
        ${CMAKE_SOURCE_DIR}/include/sistema/utilitarios
        ${CMAKE_SOURCE_DIR}/include/sistema/validadorPrincipais
        ${CMAKE_SOURCE_DIR}/libs/formato
        ${CMAKE_SOURCE_DIR}/libs/io
        ${CMAKE_SOURCE_DIR}/libs/sqlite
        ${CMAKE_SOURCE_DIR}/libs/tabela
        ${CMAKE_SOURCE_DIR}/libs/teste
        ${CMAKE_SOURCE_DIR}/meta
        ${CMAKE_SOURCE_DIR}/testes
        ${CMAKE_SOURCE_DIR}/testes/testes_dominios
        ${CMAKE_SOURCE_DIR}/testes/testes_entidades
)