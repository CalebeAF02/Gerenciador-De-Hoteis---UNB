#include "../validadoresAbstratos/ValidarDinheiro.h"

using namespace std;

void ValidarDinheiro::validar(const int valor) {
    if (valor >= 1 && valor <= 100000000) {
    }else {
        throw invalid_argument("Erro: Valor invalido! Digite o valor entre R$ 1 e R$ 100000000 !");
    }
};
