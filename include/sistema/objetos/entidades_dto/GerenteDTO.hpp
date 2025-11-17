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
        int id;
        string nome;
        string email;
        string ramal;

    public:
        GerenteDTO() = default;

        GerenteDTO(int id, string nome, string email, string ramal) : id(id), nome(nome), email(email), ramal(ramal) {
        };

        int getId() const {
            return id;
        }

        void setId(int id) {
            this->id = id;
        }

        string getNome() const {
            return nome;
        }

        void setNome(const string &nome) {
            this->nome = nome;
        }

        string getEmail() const {
            return email;
        }

        void setEmail(const string &email) {
            this->email = email;
        }

        string getRamal() const {
            return ramal;
        }

        void setRamal(const string &ramal) {
            this->ramal = ramal;
        }
    };
}

#endif //Hotelaria_UnB_TP1_GERENTEDTO_HPP