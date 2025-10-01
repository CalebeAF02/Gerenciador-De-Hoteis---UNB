cmake_minimum_required(VERSION 3.10)
project(gerenciador_hotel_unb)

set(CMAKE_CXX_STANDARD 17)

# Diretórios de headers
include_directories(
        #includes
        include
        include/Entidades
        include/validadorAbstratos
        include/validadorPrincipais

        #outros
        coisas
        coisas/utilitarios
)

# Fontes principais
add_executable(gerenciador_hotel_unb
        src/main.cpp

        # Entidades
        src/Entidades/Gerente.cpp
        src/Entidades/Hospede.cpp
        src/Entidades/Hotel.cpp
        src/Entidades/Pessoa.cpp
        src/Entidades/Quarto.cpp
        src/Entidades/Reserva.cpp

        # Dominios
        src/Dominios/Nome.cpp
        src/Dominios/Email.cpp
        src/Dominios/Ramal.cpp
        src/Dominios/Senha.cpp
        src/Dominios/Endereco.cpp
        src/Dominios/Cartao.cpp
        src/Dominios/Telefone.cpp
        src/Dominios/Codigo.cpp
        src/Dominios/Numero.cpp
        src/Dominios/Capacidade.cpp
        src/Dominios/Dinheiro.cpp

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
        coisas/utilitarios/Data.cpp
        coisas/utilitarios/TextoApresentacao.cpp
        coisas/utilitarios/LinhaTSV.cpp
        src/sistema/SistemaHotel.cpp
        src/sistema/Servicos.cpp
)