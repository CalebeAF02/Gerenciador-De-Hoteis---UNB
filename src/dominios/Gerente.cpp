#include "../dominios/Gerente.h"


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

string Gerente::getTSV()
{
    return string("GERENTE") + "\t" + nome + "\t" + email + "\t" + ramal + "\t" + senha;
}

void Gerente::setTSV(string dados)
{
    int posicaoGerente = dados.find("\t");

    if (posicaoGerente == string::npos)
    {
        throw invalid_argument("Erro: Dados invalida");
    }
    string parteGerente = dados.substr(0, posicaoGerente);
    string parteResto = dados.substr(posicaoGerente + 1);


    int posicaoNome = parteResto.find("\t");

    if (posicaoNome == string::npos)
    {
        throw invalid_argument("Erro: Dados invalida");
    }
    string parteNome = parteResto.substr(0, posicaoNome);
    parteResto = parteResto.substr(posicaoNome + 1);

    int posicaoEmail = parteResto.find("\t");

    if (posicaoEmail == string::npos)
    {
        throw invalid_argument("Erro: Dados invalida");
    }
    string parteEmail = parteResto.substr(0, posicaoEmail);
    parteResto = parteResto.substr(posicaoEmail + 1);

    int posicaoRamal = parteResto.find("\t");

    if (posicaoRamal == string::npos)
    {
        throw invalid_argument("Erro: Dados invalida");
    }
    string parteRamal = parteResto.substr(0, posicaoRamal);
    parteResto = parteResto.substr(posicaoRamal + 1);

    setNome(parteNome);
    setEmail(parteEmail);
    setRamal(parteRamal);
    setSenha(parteResto);
    cout << "tipo :" << parteGerente << endl;
    cout << "nome :" << parteNome << endl;
    cout << "email :" << parteEmail << endl;
    cout << "ramal :" << parteRamal << endl;
    cout << "senha :" << parteResto << endl;
}
