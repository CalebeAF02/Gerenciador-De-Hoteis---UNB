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
        include/sistema/servicos
        include/validadorAbstratos
        include/validadorPrincipais

        #outros
        coisas
        coisas/utilitarios
        coisas/testes

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

        # ValidadoresAbstratos
        src/validadores_abstratos/ValidarCodigo.cpp
        src/validadores_abstratos/ValidarDinheiro.cpp
        src/validadores_abstratos/ValidarEmail.cpp
        src/validadores_abstratos/ValidarEndereco.cpp
        src/validadores_abstratos/ValidarNome.cpp
        src/validadores_abstratos/ValidarRamal.cpp

        # ValidadoresPrincipais
        src/validadores_principais/ValidarInt.cpp
        src/validadores_principais/ValidarString.cpp

        #Sistamas
        src/sistema/Sistema.cpp
        src/sistema/servicos/ServicosGerente.cpp
        src/sistema/servicos/ServicosHospede.cpp
        src/sistema/servicos/ServicosHotel.cpp
        src/sistema/servicos/ServicosQuarto.cpp
        src/sistema/servicos/ServicosReserva.cpp

        # Testes
        coisas/testes/Teste.cpp
        coisas/testes/Smoke_Tests.cpp

        #utilitarios
        coisas/utilitarios/Data.cpp
        coisas/utilitarios/TextoApresentacao.cpp
        coisas/utilitarios/LinhaTSV.cpp

)