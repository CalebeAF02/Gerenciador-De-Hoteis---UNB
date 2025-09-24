cmake_minimum_required(VERSION 4.0)
project(projetos_cpp_unb_7)

set(CMAKE_CXX_STANDARD 20)

add_executable(projetos_cpp_unb_7 main.cpp
        dominios/d_corpo/Quarto.cpp
        dominios/d_corpo/Pessoa.cpp
        dominios/d_corpo/Hotel.cpp
        dominios/d_corpo/Hospede.cpp
        dominios/d_corpo/Gerente.cpp
        validadores/val_abstratos/ValidarEmail.cpp
        validadores/val_abstratos/ValidarEndereco.cpp
        validadores/val_principais/ValidarInt.cpp
        validadores/val_abstratos/ValidarNome.cpp
        validadores/val_abstratos/ValidarRamal.cpp
        validadores/val_principais/ValidarString.cpp
        validadores/testes_validadores/testes_validadores.cpp
        validadores/testes_validadores/testes_validadores.h
        validadores/testes/Teste.cpp
        validadores/testes/Teste.h
        Data.cpp
        dominios/d_corpo/Reserva.cpp
        dominios/d_cabecalho/Reserva.h
        validadores/val_abstratos/ValidarDinheiro.cpp
        validadores/val_abstratos/ValidarDinheiro.h
        validadores/val_abstratos/ValidarCodigo.cpp
        validadores/val_abstratos/ValidarCodigo.h)
