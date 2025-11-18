//
// Created by caleb on 09/11/2025.
//

#ifndef Hotelaria_UnB_TP1_GERENTEDTO_HPP
#define Hotelaria_UnB_TP1_GERENTEDTO_HPP

#include <string>

using namespace std;
namespace Hotelaria {
    class GerenteDTO {
    private:
        int gerenteId;
        string nome;
        string email;
        string ramal;

    public:
        GerenteDTO() = default;

        GerenteDTO(int gerenteId, string nome, string email, string ramal) : gerenteId(gerenteId), nome(nome), email(email), ramal(ramal) {
        };

        int getGerenteId() const {
            return gerenteId;
        }

        void setGerenteId(int valor) {
            this->gerenteId = valor;
        }

        string getNome() const {
            return nome;
        }

        void setNome(const string &valor) {
            this->nome = valor;
        }

        string getEmail() const {
            return email;
        }

        void setEmail(const string &valor) {
            this->email = valor;
        }

        string getRamal() const {
            return ramal;
        }

        void setRamal(const string &valor) {
            this->ramal = valor;
        }
    };
}

#endif //Hotelaria_UnB_TP1_GERENTEDTO_HPP