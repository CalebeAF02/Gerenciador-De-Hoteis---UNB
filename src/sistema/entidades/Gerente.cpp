#include "Gerente.hpp"

#include <istream>
#include <sstream>

using namespace std;

void Gerente::setTSV(string dados) // Transforma uma linha de texto em um Gerente
{
    istringstream stream(dados);
    string tipo, nomeStr, emailStr, ramalStr, senhaStr;
    getline(stream, tipo, '\t');
    getline(stream, nomeStr, '\t');
    getline(stream, emailStr, '\t');
    getline(stream, ramalStr, '\t');
    getline(stream, senhaStr, '\t');

    //Repassa os atribultos
    setNome(Nome(nomeStr));
    setEmail(Email(emailStr));
    setRamal(Ramal(ramalStr));
    setSenha(Senha(senhaStr));
};