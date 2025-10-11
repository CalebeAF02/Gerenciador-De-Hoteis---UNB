#include "Hospede.h"


#include <istream>
#include <sstream>

using namespace std;

void Hospede::setTSV(string dados) // Transforma uma linha de texto em um Gerente
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
    setEndereco(Endereco(ramalStr));
    setCartao(Cartao(senhaStr));
};