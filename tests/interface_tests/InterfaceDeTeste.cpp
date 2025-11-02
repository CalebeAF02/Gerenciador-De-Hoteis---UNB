#include "InterfaceDeTeste.hpp"

int InterfaceDeTeste::contTodalTestes = 0;
int InterfaceDeTeste::contTodalTestesOk = 0;
int InterfaceDeTeste::contTodalTestesProblema = 0;

//-----------------------------------------------------------------------------------------------------------
void InterfaceDeTeste::checaResultado(int esperando_resultado, int resultado_teste) {
    if (esperando_resultado == DEVE_DAR_CERTO) {
        cout << "Esperando: Validacao CORRETA" << endl;
    } else if (esperando_resultado == DEVE_DAR_ERRADO) {
        cout << "Esperando: Validacao ERRADA" << endl;
    }

    if (esperando_resultado == resultado_teste) {
        cout << "Resultado: OK" << endl << endl;
        contTodalTestesOk += 1;
    } else {
        cout << "Resultado: PROBLEMA NA VALIDACAO DO PROGRAMADOR" << endl << endl;
        contTodalTestesProblema += 1;
    }
};
//-----------------------------------------------------------------------------------------------------------
void InterfaceDeTeste::apresentacaoTeste(string valor) {
    cout << "Teste Para Validar " << endl << "Entrada: " << valor << endl;
    contTodalTestes += 1;
}

void InterfaceDeTeste::apresentacaoTeste(int valor) {
    cout << "Teste Para Validar " << endl << "Entrada: " << valor << endl;
    contTodalTestes += 1;
}

void InterfaceDeTeste::apresentacaoTesteData(string valor) {
    cout << "Teste Para Validar " << endl << "Entrada: " << valor << endl;
    contTodalTestes += 1;
}

//-----------------------------------------------------------------------------------------------------------
int InterfaceDeTeste::apresentacaoSucesso() {
    cout << "----------------------OK----------------------" << endl;
    cout << "Entrada Valida! " << endl;
    cout << "----------------------------------------------" << endl;
    return DEVE_DAR_CERTO;
}

//-----------------------------------------------------------------------------------------------------------
int InterfaceDeTeste::apresentacaoErro(invalid_argument erro) {
    cout << "---------------------ERRO---------------------" << endl;
    cout << erro.what() << endl;
    cout << "----------------------------------------------" << endl;
    return DEVE_DAR_ERRADO;
}

//-----------------------------------------------------------------------------------------------------------
int InterfaceDeTeste::apresentacaoErro(string erro) {
    cout << "---------------------ERRO---------------------" << endl;
    cout << erro << endl;
    cout << "----------------------------------------------" << endl;
    return DEVE_DAR_ERRADO;
}

//-------------------------------------------------------------------
int InterfaceDeTeste::getTestes() {
    return contTodalTestes;
}

int InterfaceDeTeste::getTestesOk() {
    return contTodalTestesOk;
}

int InterfaceDeTeste::getTestesProblema() {
    return contTodalTestesProblema;
}

//-----------------------------------------------------------------------------------------------------------