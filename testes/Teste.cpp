//
// Created by caleb on 20/09/2025.
//
#include "Teste.h"
#include "testes_validadores.h"

//-----------------------------------------------------------------------------------------------------------
void Teste::checaResultado(int esperando_resultado, int resultado_teste ) {
    if (esperando_resultado == DEVE_DAR_CERTO) {
        cout << "Esperando: Validacao CORRETA" << endl;
    }else if (esperando_resultado == DEVE_DAR_ERRADO){
        cout << "Esperando: Validacao ERRADA" << endl;
    }

    if (esperando_resultado == resultado_teste) {
        cout << "Resultado: OK" << endl<<endl;
        contTodalTestesOk += 1;
    }else{
        cout << "Resultado: PROBLEMA NA VALIDACAO DO PROGRAMADOR" << endl<<endl;
        contTodalTestesProblema +=1;
    }
};
//-----------------------------------------------------------------------------------------------------------
void Teste::apresentacaoTeste(string valor) {
    cout << "Teste Para Validar " << endl << "Entrada: " << valor << endl;
    contTodalTestes += 1;
}
void Teste::apresentacaoTeste(int valor) {
    cout << "Teste Para Validar " << endl << "Entrada: " << valor << endl;
    contTodalTestes += 1;
}
//-----------------------------------------------------------------------------------------------------------
int Teste::apresentacaoSucesso() {
    cout << "----------------------OK----------------------" << endl;
    cout << "Entrada Valida! "<< endl;
    cout << "----------------------------------------------" << endl;
    return DEVE_DAR_CERTO;
}
//-----------------------------------------------------------------------------------------------------------
int Teste::apresentacaoErro(invalid_argument erro) {
    cout << "---------------------ERRO---------------------" << endl;
    cout << erro.what() << endl;
    cout << "----------------------------------------------" << endl;
    return DEVE_DAR_ERRADO;
}
//-------------------------------------------------------------------
int Teste::getTestes() {
    return contTodalTestes;
}
int Teste::getTestesOk() {
    return contTodalTestesOk;
}
int Teste::getTestesProblema() {
    return contTodalTestesProblema;
}
//-----------------------------------------------------------------------------------------------------------