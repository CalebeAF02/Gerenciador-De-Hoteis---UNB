#include "../../../include/sistema/dominios/Data.hpp"

using namespace std;

//void Data{10,9,2025};

void Data::validar() {
    if (dia < 1 || dia > 31) {
        throw invalid_argument("Erro: Dia invalido");
    }
    if (mes < 1 || mes > 12) {
                throw invalid_argument("Erro: Mes invalido");
            }
    if (ano < 2000 || ano > 2999) {
                throw invalid_argument("Erro: Ano invalido");
    }
}

void Data::setData(int d, int m, int a) {
    this->dia = d;
    this->mes = m;
    this->ano = a;

    validar();

    // 2. Validação LÓGICA (Bissexto e Dias por Mês) - DEVE OCORRER DEPOIS DE SETAR TUDO

    // Calcula dias no mês atual
    int diasNoMes;
    if (m == ABR || m == JUN || m == SET || m == NOV) {
        diasNoMes = 30;
    } else if (m == FEV) {
        bool ehBissexto = (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
        diasNoMes = ehBissexto ? 29 : 28;
    } else {
        diasNoMes = 31;
    }

    if (d < 1 || d > diasNoMes) {
        throw invalid_argument("Erro: Dia invalido para o mes e ano fornecidos.");
    }
};