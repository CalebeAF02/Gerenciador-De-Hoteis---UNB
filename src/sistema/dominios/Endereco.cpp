#include <sstream>
#include <cctype>
#include <stdexcept>

#include "Endereco.hpp"

void Endereco::validar(const std::string endereco) {
    if (endereco.length() < 5 || endereco.length() > 30) {
        throw std::invalid_argument("Erro: Endereco com tamanho invalido");
    }

    // Separar os componentes: rua, número, complemento
    std::istringstream iss(endereco);
    std::string rua, numero, complemento;

    if (!(iss >> rua >> numero)) {
        throw std::invalid_argument("Erro: Endereco deve conter pelo menos rua e numero");
    }

    std::getline(iss, complemento); // complemento pode ter espaços

    // Validar rua: cada termo começa com maiúscula
    std::istringstream ruaStream(rua);
    std::string termo;
    while (std::getline(ruaStream, termo, ' ')) {
        if (!isupper(termo[0])) {
            throw std::invalid_argument("Erro: Rua deve comecar com letra maiuscula em cada termo");
        }
    }

    // Validar número: inteiro positivo
    for (char c: numero) {
        if (!isdigit(c)) {
            throw std::invalid_argument("Erro: Numero do endereco deve conter apenas digitos");
        }
    }
    if (std::stoi(numero) <= 0) {
        throw std::invalid_argument("Erro: Numero do endereco deve ser positivo");
    }

    // Validar complemento (se existir): cada termo começa com maiúscula
    if (!complemento.empty()) {
        std::istringstream compStream(complemento);
        std::string compTermo;
        while (compStream >> compTermo) {
            if (!isupper(compTermo[0])) {
                throw std::invalid_argument("Erro: Complemento deve comecar com letra maiuscula em cada termo");
            }
        }
    }
}