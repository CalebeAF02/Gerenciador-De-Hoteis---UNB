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
    void menuSistema();

    void rodandoSistema();

    bool getExecutando();

    // Metodo Para Fazer um login pre-programado)
    bool fazerLogin(string emailLoginProgramado, string senhaLoginProgramada);
};

inline bool SistemaHotel::getExecutando()
{
    return executando;
};
#endif //GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H
