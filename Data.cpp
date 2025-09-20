//
// Created by caleb on 10/09/2025.
//

#include "Data.h"

using namespace std;

//void Data{10,9,2025};

void Data::validar(int tipo, int valor) {
    switch (tipo) {
        case TIPO_DIA:{
            if (valor <1 || valor >31) {
                throw invalid_argument("Dia invalido");
            }

            break;
        }
        case TIPO_MES:{
            break;
        }
        case TIPO_ANO:{
            break;
        }

    }

}
