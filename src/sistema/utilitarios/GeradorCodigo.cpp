//
// Created by caleb on 26/10/2025.
//

#include "GeradorCodigo.h"
#include <ctime>
#include <sstream>

std::string GeradorCodigo::gerar(const std::string& prefixo)
{
    return prefixo + gerarSufixo();
}

std::string GeradorCodigo::gerarSufixo()
{
    std::stringstream ss;
    ss << std::time(nullptr); // timestamp atual
    return ss.str();
}