//
// Created by caleb on 28/09/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H
#define GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H

#include <iostream>

class SistemaHotel
{
private:
    bool executando = true;

public:
    void rodandoSistema();

    bool getExecutando();
};

inline bool SistemaHotel::getExecutando()
{
    return executando;
};
#endif //GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H
