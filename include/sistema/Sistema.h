//
// Created by caleb on 28/09/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H
#define GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H

#include "ServicosGerente.h"
#include "ServicosHospede.h"
#include "../utilitarios/Menu.h"

#include "TextoApresentacao.h"
#include <iostream>
#include <string>

using namespace std;

class Sistema
{
private:
    bool executando = true;
    ServicosGerente servicosGerente;
    ServicosHospede servicosHospede;

public:
    Sistema() = default;

    void menuSistema()
    {
        Sistema::rodandoSistema();
    };

    void rodandoSistema();

    bool getExecutandoSistema();

    // Metodo Para Fazer um login pre-programado)
    bool fazerLoginSistemaGerente(const string& emailLoginProgramado, const string& senhaLoginProgramada)
    {
        return servicosGerente.fazerLoginGerente(emailLoginProgramado, senhaLoginProgramada);
    };

    bool fazerLoginSistemaHospede(const string& emailLoginProgramado, const string& senhaLoginProgramada)
    {
        return servicosHospede.fazerLoginHospede(emailLoginProgramado);
    };
};

inline bool Sistema::getExecutandoSistema()
{
    return executando;
};
#endif //GERENCIADOR_HOTEL_UNB_SISTEMAHOTEL_H