cmake_minimum_required(VERSION 3.10)
project(gerenciador_hotel_unb)

set(CMAKE_CXX_STANDARD 17)

# 1) Onde estão os headers
include_directories(include)

# 2) Adicionar todos os .cpp
file(GLOB SOURCES
        src/*.cpp
        src/dominios/*.cpp
        src/validadoresAbstratos/*.cpp
        src/validadoresPrincipais/*.cpp
        testes/*.cpp
)
# 3) Gerar o executável
add_executable(gerenciador_hotel_unb ${SOURCES})
