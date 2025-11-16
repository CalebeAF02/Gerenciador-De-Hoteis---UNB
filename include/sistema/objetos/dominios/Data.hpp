#ifndef DATA_INCLUDE
#define DATA_INCLUDE

#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;
namespace Hotelaria {
    class Data : public exception {
    private:
        void validar();

    public:
        int dia;
        int mes;
        int ano;

        static int const JAN = 1;
        static int const FEV = 2;
        static int const MAR = 3;
        static int const ABR = 4;
        static int const MAI = 5;
        static int const JUN = 6;
        static int const JUL = 7;
        static int const AGO = 8;
        static int const SET = 9;
        static int const OUT = 10;
        static int const NOV = 11;
        static int const DEZ = 12;

        //Construtores
        Data() = default;

        explicit Data(const string &dataStr);

        // Metodo de Impressao
        string toString() {
            return to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
        }

        //metodo Setar - Entrada
        void setData(int d, int m, int a);

        //metodos get - Saida
        int getDia();

        int getMes();

        int getAno();
    };

    inline int Data::getDia() {
        return dia;
    }

    inline int Data::getMes() {
        return mes;
    }

    inline int Data::getAno() {
        return ano;
    }
}

#endif