#include "../Entidades/Gerente.h"


void Gerente::validar(int tipo, const string valor)
{
    switch (tipo)
    {
    case TIPO_RAMAL:
        {
            ValidarRamal::validar(valor);
            break;
        };
    case TIPO_SENHA:
        {
            validarSenha(valor);
            break;
        };
    };
};

void Gerente::validarSenha(const string senha)
{
    // Deve ser editado ainda
    // ! " # $ % & ?
    int caixa_alta = 0;
    int caixa_baixa = 0;
    int caracter_especial = 0;
    int num = 0;

    int cont_letra = 0;
    int cont_num = 0;

    int Totlaletras = 0;

    int senhaTamanho = senha.length();
    if (senhaTamanho != 5)
    {
        throw invalid_argument("Erro: Senha com tamanho invalido");
    }
    for (int i = 0; i < senhaTamanho; i++)
    {
        if (isalpha(senha[i]))
        {
            if (islower(senha[i]))
            {
                Totlaletras += 1;
                caixa_baixa += 1;
                cont_letra += 1;
                if (cont_letra > 1)
                {
                    throw invalid_argument("Erro: + de 1 caracter caixa baixa");
                }
            }
            else if (isupper(senha[i]))
            {
                Totlaletras += 1;
                caixa_alta += 1;
                cont_letra += 1;
                if (cont_letra > 1)
                {
                    throw invalid_argument("Erro: + de 1 caracter caixa alta");
                }
            }
        }
        else if (isdigit(senha[i]))
        {
            cont_letra = 0;
            num += 1;
            cont_num += 1;
            if (cont_num > 1)
            {
                throw invalid_argument("Erro: Senha com numeros 2 seguidos");
            }
        }
        else if (senha[i] == '!' || senha[i] == '"' || senha[i] == '#' || senha[i] == '$' || senha[i] == '%' || senha[
            i] == '&' || senha[i] == '?')
        {
            cont_letra = 0;
            cont_num = 0;
            caracter_especial += 1;
        }
        else
        {
            throw invalid_argument("Erro: Caracter invalido");
        }
    }
    if (caixa_baixa < 1 || caixa_alta < 1 || num < 1 || caracter_especial < 1)
    {
        throw invalid_argument("Erro: Senha invalida");
    }
};

string Gerente::getTSV() // Transforma Gerente em uma linha de texto
{
    return string("GERENTE") + "\t" + nome + "\t" + email + "\t" + ramal + "\t" + senha;
}

void Gerente::setTSV(string dados) // Transforma uma linha de texto em um Gerente
{
    string parteGerente = "";
    string parteNome = "";
    string parteEmail = "";
    string parteRamal = "";
    string parteResto = "";


    // Extrai cada atribulto
    extrairAtributo(dados, parteGerente, parteResto);
    extrairAtributo(parteResto, parteNome, parteResto);
    extrairAtributo(parteResto, parteEmail, parteResto);
    extrairAtributo(parteResto, parteRamal, parteResto);

    /* Debuguer
    cout << "|"<< parteGerente << "|"<< endl;
    cout << "|"<< parteNome << "|"<< endl;
    cout << "|"<< parteEmail << "|"<< endl;
    cout << "|"<< parteRamal << "|"<< endl;
    cout << "|"<< parteResto << "|"<< endl;
    */

    //Repassa os atribultos
    setNome(parteNome);
    setEmail(parteEmail);
    setRamal(parteRamal);
    setSenha(parteResto);
};