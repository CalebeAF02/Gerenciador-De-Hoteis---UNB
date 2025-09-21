cmake_minimum_required(VERSION 4.0)
project(projetos_cpp_unb_7)

set(CMAKE_CXX_STANDARD 20)

add_executable(projetos_cpp_unb_7 main.cpp
        dominios/Quarto.cpp
        dominios/Pessoa.cpp
        dominios/Hotel.cpp
        dominios/Hospede.cpp
        dominios/Gerente.cpp
        validadores/ValidarDouble.cpp
        validadores/ValidarEndereco.cpp
        validadores/ValidarInt.cpp
        validadores/ValidarNome.cpp
        validadores/ValidarRamal.cpp
        validadores/ValidarString.cpp
        testes/testes_validadores.cpp
        testes/testes_validadores.h
        testes/Teste.cpp
        testes/Teste.h
        Data.cpp
        dominios/Reserva.cpp
        dominios/Reserva.h
        validadores/ValidarDinheiro.cpp
        validadores/ValidarDinheiro.h)
