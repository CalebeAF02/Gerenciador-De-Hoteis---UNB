#include <iostream>
#include <string>

#include "validadores/ValidarString.h"
#include "Data.h"
#include "dominios/Pessoa.h"
#include "dominios/Hospede.h"
#include "dominios/Gerente.h"
#include "dominios/Hotel.h"
#include "dominios/Quarto.h"
#include "testes/testes_validadores.h"
#include "validadores/ValidarString.h"
#include "validadores/ValidarInt.h"
#include "validadores/ValidarEmail.h"
#include "validadores/ValidarNome.h"
#include "validadores/ValidarRamal.h"
#include "validadores/ValidarEndereco.h"

using namespace std;

int Teste::contTodalTestes = 0;
int Teste::contTodalTestesOk = 0;
int Teste::contTodalTestesProblema = 0;

int main() {
    TesteValidadores::testarEntradas();


    //-----------------------------------------------------------------------------------------------------------------
    /*
    cout << "Cadastrando Class Pessoa :" << endl;
    Pessoa pessoa;

    //cout << "Configurando o Nome da  pessoa 1" << endl;
    //cout << "Digite o Nome:";
    string nome_1 = "Calebe Alves";
    //getline(cin, nome_1);
    pessoa.setNome(nome_1);

    //cout << "Configurando o email 1" << endl;
    //cout << "Digite o Email:";
    string email_1 = "calebe.2324@gmail.com";
    //getline(cin, email_1);
    pessoa.setEmail(email_1);

    /*
    cout << "Vamos Validar os dados da Pessoa 1!" << endl;
    if (pessoa.validar(pessoa.getNome())) {
        cout << "Nome valido!\n";
    } else {
        cout << "Erro: Nome invalido!\n";
    }
    if (pessoa.validar(pessoa.getEmail())) {
        cout << "Email valido!\n";
    } else {
        cout << "Erro: Email invalido!\n";
    }
    #1#

    //cout << "Imprimindo a pessoa 1" << endl;
    cout << "Segue o resultado da Class Pessoa abaixo:" << endl;
    cout << "O nome da Pessoa e: " << pessoa.getNome() << endl;
    cout << "O email e: " << pessoa.getEmail() << endl;

    cout << "---------------------------------------------" << endl;

    cout << "Cadastrando Class Hospede:" << endl;
    Hospede hhospede;

    //cout << "Configurando a Endereco 1 << endl;
    //cout << "Digite o Endereco:";
    string endereco_1 = "Qd:56,Conj:D,Cs:01,Cid:Itapoa2";
    //getline(cin, endereco_1);
    hhospede.setEndereco(endereco_1);

    //Configurando o cartao 1
    //cout << "Digite o cartao:";
    string cartao_1 = "1234567898765432";
    //getline(cin, cartao_1);
    hhospede.setCartao(cartao_1);

    /*
    cout << "Vamos Validar os dados do hospede 1!" << endl;
    if (h.validar(h.getEndereco())) {
        cout << "Endereco valido!\n";
    } else {
        cout << "Erro: Endereco Inavalido!\n";
    }
    if (h.validar(h.getCartao())) {
        cout << "cartao valido!\n";
    } else {
        cout << "Erro: cartao Invalido!\n";
    }
    #1#

    //cout << "Imprimindo o hospede 1" << endl;
    cout << "Segue o resultado da Class Hospede abaixo:" << endl;
    cout << "O Endereco e: " << hhospede.getEndereco() << endl;
    cout << "O Cartao e: " << hhospede.getCartao() << endl;

    cout << "---------------------------------------------" << endl;

    cout << "Configurando o gerente 1" << endl;
    Gerente gerente;

    //cout << "Configurando a ramal 1" << endl;
    //cout << "Digite o Ramal:";
    int ramal_1 = 5555;
    //getline(cin, Ramal_1);
    gerente.setRamal(ramal_1);

    //cout << "Configurando a senha 1" << endl;
    //cout << "Digite a senha:";
    int senha_1 = 54321;
    //getline(cin, senha_1);
    gerente.setSenha(senha_1);

    /*
    cout << "Vamos Validar os dados do gerente 1!" << endl;
    if (gerente.validar(g1.getRamal())) {
        cout << "Ramal valido!\n";
    } else {
        cout << "Erro: Ramal invalido!\n";
    }
    if (gerente.validar(g1.getSenha())) {
        cout << "Senha valida!\n";
    } else {
        cout << "Erro: Senha invalida!\n";
    }
    #1#
    //cout << "Imprimindo o gerente 1" << endl;
    cout << "Segue o resultado de Class Gerente abaixo:" << endl;
    cout << "O Ramal e: " << gerente.getRamal() << endl;
    cout << "A Senha e: " << gerente.getSenha() << endl;

    cout << "---------------------------------------------" << endl;

    cout << "Configurando o hotel 1" << endl;
    Hotel hotel;

    //cout << "Configurando a Nome do hotel 1" << endl;
    //cout << "Digite o Nome do Hotel:";
    string nomeHotel_1 = "Jariguagua";
    //getline(cin, nomeHotel_1);
    hotel.setNome(nomeHotel_1);

    //cout << "Configurando o endereco 1" << endl;
    string enderecco_1 = "Qd:56,Conj:D,Cs:01,Cid:Itapoa2";
    //getline(cin, enderecco_1);
    hotel.setEndereco(endereco_1);

    //cout << "Configurando o telefone 1" << endl;
    //cout << "Digite o Telefone:";
    string telefone_1 = "1234567898765432";
    //getline(cin, telefone_1);
    hotel.setTelefone(telefone_1);

    /*
    cout << "Vamos Validar os dados do hotel 1!" << endl;
    if (hotel.validar(hotel.getNome())) {
        cout << "Nome valido!\n";
    } else {
        cout << "Erro: Nome invalido!\n";
    }
    if (hotel.validar(hotel.getEndereco())) {
        cout << "Endereco valido!\n";
    } else {
        cout << "Erro: Endereco invalido!\n";
    }
    if (hotel.validar(hotel.getTelefone())) {
        cout << "Telefone valida!\n";
    } else {
        cout << "Erro: Telefone invalido!\n";
    }
    #1#
    //cout << "Imprimindo o hotel 1" << endl;
    cout << "Segue o resultado da Class Hotel abaixo:" << endl;
    cout << "O Nome do Hotel  e: " << hotel.getNome() << endl;
    cout << "O Endereco  e: " << hotel.getEndereco() << endl;
    cout << "O Telefone e: " << hotel.getTelefone() << endl;

    cout << "---------------------------------------------" << endl;

    cout << "Configurando a quarto 1" << endl;
    Quarto quarto;

    //cout << "Configurando o numero 1" << endl;
    //cout << "Digite o Numero:";
    int numero_1 = 1;
    //getline(cin, numero_1);
    quarto.setNumero(numero_1);


    //cout << "Configurando a capacidade 1" << endl;
    //cout << "Digite a Capacidade:";
    int capacidade_1 = 4;
    //getline(cin, capacidade_1);
    quarto.setCapacidade(capacidade_1);

    //Configurando a Diaria 1
    //cout << "Digite a Diaria1:";
    double diaria_1 = 75.00;
    //getline(cin, diaria_1);
    quarto.setDiaria(diaria_1);

    //Configurando a Ramal 1
    //cout << "Digite a ramal:";
    int rramal_1 = 100000;
    //getline(cin, rramal_1);
    quarto.setRamal(rramal_1);

    /*
    cout << "Vamos Validar os dados do quarto 1!" << endl << endl;
    if (quarto.validar(quarto.getNumero())) {
        cout << "Numero valido!\n";
    } else {
        cout << "Erro: Numero invalido!\n";
    }
    if (q.validar(quarto.getCapacidade())) {
        cout << "Capacidade valida!\n";
    } else {
        cout << "Erro: Capacidade invalida!\n";
    }
    if (q.validar(quarto.getDiaria())) {
        cout << "Diaria valida!\n";
    } else {
        cout << "Erro: Diaria invalida!\n";
    }
    if (q.validar(quarto.getRamal())) {
        cout << "Ramal valido!\n";
    } else {
        cout << "Erro: Ramal invalido!\n";
    }
    #1#

    //cout << "Imprimindo o quarto 1" << endl;
    cout << "Segue o resultado da Class Quarto abaixo:" << endl;
    cout << "O Numero  e: " << quarto.getNumero() << endl;
    cout << "O Ramal e: " << quarto.getRamal() << endl;
    cout << "A Capacidade e: " << quarto.getCapacidade() << endl;
    cout << "A Diaria e: " << quarto.getDiaria() << endl;

    cout << "---------------------------------------------" << endl;

    /*
    cout << "Hospede valido? " << hhospede.validar(hospede.getNome()) << endl;
    cout << "Gerente valido? " << gerente.validar(gerente.getEmail()) << endl;
    cout << "Hotel valido? " << hotel.validar("Hotel Bom Sono") << endl;
    cout << "Quarto valido? " << quarto.validar("101") << endl;
    #1#
    #1#*/

    //-----------------------------------------------------------------------------------------------------------------

    system("pause");
    return 0;
}