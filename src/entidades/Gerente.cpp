#include "Gerente.h"

#include <istream>
#include <sstream>

using namespace std;

void Gerente::setTSV(string dados) // Transforma uma linha de texto em um Gerente
{
    istringstream stream(dados);
    string tipo, nome, email, ramal, senha;
    getline(stream, tipo, '\t');
    getline(stream, nome, '\t');
    getline(stream, email, '\t');
    getline(stream, ramal, '\t');
    getline(stream, senha, '\t');

    string parteGerente = "";
    string parteNome = "";
    string parteEmail = "";
    string parteRamal = "";
    string parteResto = "";

    //Repassa os atribultos
    setNome(Nome(nome));
    setEmail(Email(email));
    setRamal(ramal);
    setSenha(senha);

    /*

    //  Extrai cada atribulto
    extrairAtributo(dados, parteGerente, parteResto);
    extrairAtributo(parteResto, parteNome, parteResto);
    extrairAtributo(parteResto, parteEmail, parteResto);
    extrairAtributo(parteResto, parteRamal, parteResto);

    /*
    //   Debuguer
    cout << "|"<< parteGerente << "|"<< endl;
    cout << "|"<< parteNome << "|"<< endl;
    cout << "|"<< parteEmail << "|"<< endl;
    cout << "|"<< parteRamal << "|"<< endl;
    cout << "|"<< parteResto << "|"<< endl;


    //Repassa os atribultos
    setNome(Nome(parteNome));
    setEmail(Email(parteEmail));
    setRamal(parteRamal);
    setSenha(parteResto);
    */
};