<<<<<<< HEAD
cmake_minimum_required(VERSION 3.10)
project(gerenciador_hotel_unb)

set(CMAKE_CXX_STANDARD 17)

# Diretórios de headers
include_directories(
        include
        include/Entidades
        include/validadorAbstratos
        include/validadorPrincipais
)

include_directories(
        coisas
)
#
include_directories(
        coisas/utilitarios
)

# Fontes principais
add_executable(gerenciador_hotel_unb
        src/main.cpp

        # Domínios
        coisas/utilitarios/Data.cpp
        src/Entidades/Gerente.cpp
        src/Entidades/Hospede.cpp
        src/Entidades/Hotel.cpp
        src/Entidades/Pessoa.cpp
        src/Entidades/Quarto.cpp
        src/Entidades/Reserva.cpp

        # ValidadoresAbstratos
        src/validadoresAbstratos/ValidarCodigo.cpp
        src/validadoresAbstratos/ValidarDinheiro.cpp
        src/validadoresAbstratos/ValidarEmail.cpp
        src/validadoresAbstratos/ValidarEndereco.cpp
        src/validadoresAbstratos/ValidarNome.cpp
        src/validadoresAbstratos/ValidarRamal.cpp

        # ValidadoresPrincipais
        src/validadoresPrincipais/ValidarInt.cpp
        src/validadoresPrincipais/ValidarString.cpp

        # Testes
        coisas/testes/Teste.cpp
        coisas/testes/Smoke_Tests.cpp

        #utilitarios
        src/sistema/Servicos.cpp
        coisas/utilitarios/TextoApresentacao.cpp
        coisas/utilitarios/LinhaTSV.cpp
        coisas/utilitarios/LinhaTSV.h
        src/sistema/SistemaHotel.cpp
        include/sistema/SistemaHotel.h
        src/Dominios/Nome.cpp
        include/Dominios/Nome.h
        src/Dominios/Email.cpp
        include/Dominios/Email.h
        src/Dominios/Ramal.cpp
        include/Dominios/Ramal.h
        src/Dominios/Senha.cpp
        include/Dominios/Senha.h
        src/Dominios/Endereco.cpp
        include/Dominios/Endereco.h
        src/Dominios/Cartao.cpp
        include/Dominios/Cartao.h
        src/Dominios/Telefone.cpp
        include/Dominios/Telefone.h
        src/Dominios/Codigo.cpp
        include/Dominios/Codigo.h
        src/Dominios/Numero.cpp
        include/Dominios/Numero.h
        src/Dominios/Capacidade.cpp
        include/Dominios/Capacidade.h
        src/Dominios/Dinheiro.cpp
        include/Dominios/Dinheiro.h
=======
cmake_minimum_required(VERSION 3.10)
project(gerenciador_hotel_unb)

set(CMAKE_CXX_STANDARD 17)

# Diretorios de headers
include_directories(
        #includes
        include

        include/sistema
        include/sistema/apresentacao
        include/sistema/dominios
        include/sistema/entidades
        include/sistema/fabricas
        include/sistema/gerenciaveis
        include/sistema/interfaces
        include/sistema/persistencias
        include/sistema/servicos
        include/sistema/utilitarios
        include/sistema/validadorPrincipais

        libs
        libs/sqlite

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
add_executable(gerenciador_hotel_unb
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
        src/sistema/utilitarios/SolicitacaoHospedagem.cpp
        src/sistema/utilitarios/PersistenciaSolicitacaoHospedagem.cpp
        src/sistema/utilitarios/GeradorCodigo.cpp

        # ValidadoresPrincipais
        src/sistema/validadores_principais/ValidarInt.cpp
        src/sistema/validadores_principais/ValidarString.cpp

        # libs
        libs/sqlite/sqlite3.c

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
>>>>>>> antigo/main
)