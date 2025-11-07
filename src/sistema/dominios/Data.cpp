#include "../../../include/sistema/dominios/Data.hpp"

using namespace std;

//void Data{10,9,2025};

void Data::validar(int tipo, int valor) {
    switch (tipo) {
        case TIPO_DIA: {
            if (valor < 1 || valor > 31) {
                throw invalid_argument("Erro: Dia invalido");
            }

            break;
        }
        case TIPO_MES: {
            if (valor < 1 || valor > 12) {
                throw invalid_argument("Erro: Mes invalido");
            }
            break;
        }
        case TIPO_ANO: {
            if (valor < 2000 || valor > 2999) {
                throw invalid_argument("Erro: Ano invalido");
            }
            break;
        }
    }
}
void Data::setData(int d, int m, int a) {
    validar(TIPO_DIA, d);
    validar(TIPO_MES, m);
    validar(TIPO_ANO, a);

    this->dia = d;
    this->mes = m;
    this->ano = a;

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