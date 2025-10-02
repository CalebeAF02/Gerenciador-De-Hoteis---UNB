//
// Created by caleb on 28/09/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H
#define GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H

#include "Servicos.h"

#include <iostream>

class SistemaHotel
{
private:
    bool executando = true;
    Servicos servicos;

public:
    void rodandoSistema();

    bool getExecutando();

    bool fazerLogin(string copiaLogin, string senhaLogin);

    void menuSistema();
};

inline bool SistemaHotel::getExecutando()
{
    return executando;
};
#endif //GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H
