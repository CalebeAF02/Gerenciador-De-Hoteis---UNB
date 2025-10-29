//
// Created by caleb on 26/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_GERADORCODIGO_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_GERADORCODIGO_H

#include <string>

class GeradorCodigo
{
public:
    // Gera um codigo unico com prefixo (ex: "SOL1698330000")
    static std::string gerar(const std::string& prefixo);

private:
    // Gera parte numerica baseada no tempo atual
    static std::string gerarSufixo();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_GERADORCODIGO_H