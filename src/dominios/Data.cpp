
#include "dominios/Data.h"

using namespace std;

//void Data{10,9,2025};

void Data::validar(int tipo, int valor) {
    switch (tipo) {
        case TIPO_DIA:{
            if (valor <1 || valor >31) {
                throw invalid_argument("Erro: Dia invalido");
            }

            break;
        }
        case TIPO_MES:{
            if (valor <1 || valor > 12) {
                throw invalid_argument("Erro: Mes invalido");
            }
            break;
        }
        case TIPO_ANO:{
            if (valor <2000 || valor > 2999) {
                throw invalid_argument("Erro: Ano invalido");
            }
            break;
        }

    }

}
