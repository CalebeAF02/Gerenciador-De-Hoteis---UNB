//
// Created by caleb on 28/09/2025.
//

#ifndef GERENCIADOR_HOTEL_UNB_LINHATSV_H
#define GERENCIADOR_HOTEL_UNB_LINHATSV_H

#include <iostream>
#include <string>

using namespace std;

class LinhaTSV
{
public:
    virtual string getTSV() = 0;
    virtual void setTSV(string dados) = 0;

    void extrairAtributo(string valor, string& parte, string& parteResto);
};


#endif //GERENCIADOR_HOTEL_UNB_LINHATSV_H