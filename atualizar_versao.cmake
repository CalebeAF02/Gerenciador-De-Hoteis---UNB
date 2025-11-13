# Lê o valor atual
file(READ "${INPUT_FILE}" VERSAO_STR)
string(STRIP "${VERSAO_STR}" VERSAO_STR)
math(EXPR NOVA_VERSAO "${VERSAO_STR} + 1")

# Atualiza o arquivo de versão
file(WRITE "${INPUT_FILE}" "${NOVA_VERSAO}\n")

# Captura a data atual
string(TIMESTAMP DATA_ATUAL "%Y-%m-%d %H:%M")

# Gera o cabeçalho com valor e data atualizados
file(WRITE "${OUTPUT_FILE}" "

#ifndef GERENCIADOR_DE_HOTEIS_UNB_VERSAO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_VERSAO_HPP

#include <cstdint>
#include <iostream>
#include <string>

class Versao {
private:
    static constexpr uint64_t valor = ${NOVA_VERSAO};
    static inline const string data = \"${DATA_ATUAL}\";

public:
    static uint8_t patch() { return valor % 10; }
    static uint8_t minor() { return (valor / 10) % 10; }
    static uint64_t major() { return valor / 100; }
    static uint64_t getValor() { return valor; }
    static string getData() { return data; }
    static string getVersaoCompleta() {
        return to_string(major()) + \".\" +
               to_string(minor()) + \".\" +
               to_string(patch());
    }
};

#endif // VERSAO_HPP
")