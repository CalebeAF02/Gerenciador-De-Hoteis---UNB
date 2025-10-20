cmake_minimum_required(VERSION 3.10)
project(gerenciador_hotel_unb)

set(CMAKE_CXX_STANDARD 17)

# Diretórios de headers
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

        include/utilitarios

        include/validadorPrincipais

        #outros
        libs
        libs/testes
        libs/sqlite

        testes
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
        src/sistema/interfaces/InterfaceFabricaGerenciavel.cpp

        src/sistema/persistencias/PersistenciaGerente.cpp
        src/sistema/persistencias/PersistenciaHospede.cpp

        src/sistema/servicos/ServicosGerente.cpp
        src/sistema/servicos/ServicosHospede.cpp
        src/sistema/servicos/ServicosHotel.cpp
        src/sistema/servicos/ServicosQuarto.cpp
        src/sistema/servicos/ServicosReserva.cpp

        # libs
        libs/testes/Teste.cpp
        libs/sqlite/sqlite3.c

        #utilitarios
        src/utilitarios/Data.cpp
        src/utilitarios/TextoApresentacao.cpp
        src/utilitarios/LinhaTSV.cpp
        src/utilitarios/Menu.cpp
        src/utilitarios/MenuItem.cpp

        testes/Smoke_Tests.cpp
)