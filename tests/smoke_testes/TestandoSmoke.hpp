//
// Created by caleb on 02/11/2025.
//

#ifndef GERENCIADOR_DE_HOTEIS_UNB_TESTANDOSMOKE_HPP
#define GERENCIADOR_DE_HOTEIS_UNB_TESTANDOSMOKE_HPP

#include "iostream"

using namespace std;

#include "Gerente.hpp"
#include "Hospede.hpp"
#include "Hotel.hpp"
#include "Quarto.hpp"
#include "Reserva.hpp"

class TestandoSmoke {
public:
    void ChamandoOsTests();
    static void TestesGerente(string titulo, string contador);
    static void TestesHospede(string titulo, string contador);
    static void TestesHotel(string titulo, string contador);
    static void TestesQuarto(string titulo, string contador);
    static void TestesReserva(string titulo, string contador);
    static void TestesData(string titulo, string contador);
    static void GerenteTSV(string titulo, string contador);
    static void ResultadoTSV(string titulo, string contador);

};


#endif //GERENCIADOR_DE_HOTEIS_UNB_TESTANDOSMOKE_HPP