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
)