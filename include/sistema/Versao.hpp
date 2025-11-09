

#ifndef GERENCIADOR_DE_HOTEIS_UNB_VERSAO_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_VERSAO_HPP

#include <cstdint>
#include <iostream>
#include <string>

class Versao {
private:
    static constexpr uint64_t valor = 113;
    static inline const std::string data = "2025-11-09 19:00";

public:
    static uint8_t patch() { return valor % 10; }
    static uint8_t minor() { return (valor / 10) % 10; }
    static uint64_t major() { return valor / 100; }
    static uint64_t getValor() { return valor; }
    static std::string getData() { return data; }
    static std::string getVersaoCompleta() {
        return std::to_string(major()) + "." +
               std::to_string(minor()) + "." +
               std::to_string(patch());
    }
};

#endif // VERSAO_HPP
