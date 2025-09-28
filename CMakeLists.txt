cmake_minimum_required(VERSION 3.10)
project(gerenciador_hotel_unb)

set(CMAKE_CXX_STANDARD 17)

# Diretórios de headers
include_directories(
        include
        include/dominios
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
        src/dominios/Data.cpp
        src/dominios/Gerente.cpp
        src/dominios/Hospede.cpp
        src/dominios/Hotel.cpp
        src/dominios/Pessoa.cpp
        src/dominios/Quarto.cpp
        src/dominios/Reserva.cpp

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
        coisas/utilitarios/Servicos.cpp
        coisas/utilitarios/TextoApresentacao.cpp
        coisas/utilitarios/LinhaTSV.cpp
        coisas/utilitarios/LinhaTSV.h
)