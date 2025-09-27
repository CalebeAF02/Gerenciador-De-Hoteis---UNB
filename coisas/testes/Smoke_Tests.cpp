#include "Smoke_Tests.h"

void SmokeTest::testarEntradas() {

    Pessoa pessoa1;
    //------------------------------------------------------------------------------------------------------------------

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Pessoa      |" << endl;
    cout << "                |   Testes Nome   |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &pessoa1, "");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &pessoa1, "Cb");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &pessoa1, "Calebe Alves Freitas Madeira Alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &pessoa1, "Calebe  Alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &pessoa1, "calebe alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &pessoa1, "Calebe alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &pessoa1, "Calebe@alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &pessoa1, "Calebe Alves ");

    testarValidadorNome(Teste::DEVE_DAR_CERTO, &pessoa1, "Luan Freitas");
    testarValidadorNome(Teste::DEVE_DAR_CERTO, &pessoa1, "Kaio Rodrigues");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Pessoa      |" << endl;
    cout << "                |  Testes Emails  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1, "");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1, "Cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1,
                         "1234567890123456789012345678901234567890123456789012345678901234567890@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1, "calebe clves@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1, "calebe  clves@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1,
                         "calebeclves@1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.eb.mil.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1, ".cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1, ".-cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1, "c--b@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1, "c..b@gmail.com");

    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &pessoa1, "calebeclves@citex.eb.mil.com");
    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &pessoa1, "cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &pessoa1, "luanfreitas@gmai.com");
    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &pessoa1, "kaiorodrigues@gmail.com");


    //------------------------------------------------------------------------------------------------------------------
    Gerente gerente1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Gerente     |" << endl;
    cout << "                |   Testes Nome   |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &gerente1, "");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &gerente1, "Cb");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &gerente1, "Calebe Alves Freitas Madeira Alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &gerente1, "Calebe  Alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &gerente1, "calebe alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &gerente1, "Calebe alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &gerente1, "Calebe@alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &gerente1, "Calebe Alves ");

    testarValidadorNome(Teste::DEVE_DAR_CERTO, &gerente1, "Luan Freitas");
    testarValidadorNome(Teste::DEVE_DAR_CERTO, &gerente1, "Kaio Rodrigues");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Gerente     |" << endl;
    cout << "                |  Testes Emails  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &gerente1, "");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &gerente1, "Cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &gerente1,
                         "1234567890123456789012345678901234567890123456789012345678901234567890@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &gerente1, "calebe clves@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &gerente1, "calebe  clves@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &gerente1,
                         "calebeclves@1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.eb.mil.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &gerente1, ".cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &gerente1, ".-cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &gerente1, "c--b@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &gerente1, "c..b@gmail.com");

    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &gerente1, "calebeclves@citex.eb.mil.com");
    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &gerente1, "cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &gerente1, "luanfreitas@gmai.com");
    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &gerente1, "kaiorodrigues@gmail.com");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Gerente     |" << endl;
    cout << "                |   Testes Ramal  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorRamal(Teste::DEVE_DAR_ERRADO, &gerente1, "-1");

    testarValidadorRamal(Teste::DEVE_DAR_CERTO, &gerente1, "00");
    testarValidadorRamal(Teste::DEVE_DAR_CERTO, &gerente1, "50");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Gerente     |" << endl;
    cout << "                |   Testes Senha  |" << endl;
    cout << "                -------------------" << endl << endl;
    testarValidadorSenha(Teste::DEVE_DAR_ERRADO, &gerente1, "AA1#2");
    testarValidadorSenha(Teste::DEVE_DAR_ERRADO, &gerente1, "Aa1#2");
    testarValidadorSenha(Teste::DEVE_DAR_ERRADO, &gerente1, "A12#3");
    testarValidadorSenha(Teste::DEVE_DAR_ERRADO, &gerente1, "1#2#3");
    testarValidadorSenha(Teste::DEVE_DAR_ERRADO, &gerente1, "A#B#C");
    testarValidadorSenha(Teste::DEVE_DAR_ERRADO, &gerente1, "a#b#c");

    testarValidadorSenha(Teste::DEVE_DAR_CERTO, &gerente1, "A#b#3");
    testarValidadorSenha(Teste::DEVE_DAR_CERTO, &gerente1, "A1#a2");

    //------------------------------------------------------------------------------------------------------------------

    Hospede hospede1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                |   Testes Nome   |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &hospede1, "");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &hospede1, "Cb");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &hospede1, "Calebe Alves Freitas Madeira Alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &hospede1, "Calebe  Alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &hospede1, "calebe alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &hospede1, "Calebe alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &hospede1, "Calebe@alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &hospede1, "Calebe Alves ");

    testarValidadorNome(Teste::DEVE_DAR_CERTO, &hospede1, "Luan Freitas");
    testarValidadorNome(Teste::DEVE_DAR_CERTO, &hospede1, "Kaio Rodrigues");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                |  Testes Emails  |" << endl;
    cout << "                -------------------" << endl << endl;


    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &hospede1, "");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &hospede1, "Cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &hospede1,
                         "1234567890123456789012345678901234567890123456789012345678901234567890@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &hospede1, "calebe clves@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &hospede1, "calebe  clves@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &hospede1,
                         "calebeclves@1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.eb.mil.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &hospede1, ".cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &hospede1, ".-cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &hospede1, "c--b@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &hospede1, "c..b@gmail.com");

    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &hospede1, "calebeclves@citex.eb.mil.com");
    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &hospede1, "cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &hospede1, "luanfreitas@gmai.com");
    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &hospede1, "kaiorodrigues@gmail.com");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                | Testes Endereco |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorEndereco(Teste::DEVE_DAR_ERRADO, &hospede1, "");

    testarValidadorEndereco(Teste::DEVE_DAR_CERTO, &hospede1, "Qd.52 Cs.02 Comercial DelLago");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                |  Testes Cartao  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorCartao(Teste::DEVE_DAR_ERRADO, &hospede1, "");

    testarValidadorCartao(Teste::DEVE_DAR_CERTO, &hospede1, "1234567890123456");

    //------------------------------------------------------------------------------------------------------------------

    Hotel hotel1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |      Hotel      |" << endl;
    cout << "                |   Testes Nome   |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &hotel1, "");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &hotel1, "Cb");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &hotel1, "Calebe Alves Freitas Madeira Alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &hotel1, "Calebe  Alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &hotel1, "calebe alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &hotel1, "Calebe alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &hotel1, "Calebe@alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &hotel1, "Calebe Alves ");

    testarValidadorNome(Teste::DEVE_DAR_CERTO, &hotel1, "Luan Freitas");
    testarValidadorNome(Teste::DEVE_DAR_CERTO, &hotel1, "Kaio Rodrigues");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |      Hotel      |" << endl;
    cout << "                | Testes Endereco |" << endl;
    cout << "                -------------------" << endl << endl;


    testarValidadorEndereco(Teste::DEVE_DAR_ERRADO, &hotel1, "");
    testarValidadorEndereco(Teste::DEVE_DAR_CERTO, &hotel1, "Qd.52 Cs.02 Comercial DelLago");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |      Hotel      |" << endl;
    cout << "                | Testes Telefone |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorTelefone(Teste::DEVE_DAR_ERRADO, &hotel1, "");
    testarValidadorTelefone(Teste::DEVE_DAR_ERRADO, &hotel1, "5161993009537");
    testarValidadorTelefone(Teste::DEVE_DAR_ERRADO, &hotel1, "+123456789987654321");

    testarValidadorTelefone(Teste::DEVE_DAR_CERTO, &hotel1, "+5161993009537");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |      Hotel      |" << endl;
    cout << "                |  Testes Codigo  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorCodigo(Teste::DEVE_DAR_ERRADO, &hotel1, "");
    testarValidadorCodigo(Teste::DEVE_DAR_ERRADO, &hotel1, "5161993009537");
    testarValidadorCodigo(Teste::DEVE_DAR_ERRADO, &hotel1, "abcdedghij9987654321");

    testarValidadorCodigo(Teste::DEVE_DAR_CERTO, &hotel1, "1234567890");
    testarValidadorCodigo(Teste::DEVE_DAR_CERTO, &hotel1, "abcde12345");


    //------------------------------------------------------------------------------------------------------------------

    Quarto quarto1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Quarto      |" << endl;
    cout << "                |  Testes Numero  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorNumero(Teste::DEVE_DAR_ERRADO, &quarto1, "-300");
    testarValidadorNumero(Teste::DEVE_DAR_ERRADO, &quarto1, "000");
    testarValidadorNumero(Teste::DEVE_DAR_ERRADO, &quarto1, "Ab$");

    testarValidadorNumero(Teste::DEVE_DAR_CERTO, &quarto1, "001");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Quarto      |" << endl;
    cout << "                |Testes Capacidade|" << endl;
    cout << "                -------------------" << endl << endl;


    testarValidadorCapacidade(Teste::DEVE_DAR_ERRADO, &quarto1, 5);

    testarValidadorCapacidade(Teste::DEVE_DAR_CERTO, &quarto1, 1);

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Quarto      |" << endl;
    cout << "                |  Testes Diaria  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorDinheiro(Teste::DEVE_DAR_ERRADO, &quarto1, -50);
    testarValidadorDinheiro(Teste::DEVE_DAR_ERRADO, &quarto1, 1000);

    testarValidadorDinheiro(Teste::DEVE_DAR_CERTO, &quarto1, 80000);
    testarValidadorDinheiro(Teste::DEVE_DAR_CERTO, &quarto1, 120000);


    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Quarto      |" << endl;
    cout << "                |   Testes Ramal  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorRamal(Teste::DEVE_DAR_ERRADO, &quarto1, "0");
    testarValidadorRamal(Teste::DEVE_DAR_ERRADO, &quarto1, "100");

    testarValidadorRamal(Teste::DEVE_DAR_CERTO, &quarto1, "10");


    //------------------------------------------------------------------------------------------------------------------

    Reserva reserva1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Reserva     |" << endl;
    cout << "                |  Testes Chegada |" << endl;
    cout << "                -------------------" << endl << endl;
    testarValidadorChegada(Teste::DEVE_DAR_ERRADO, &reserva1, 33, 55, 5000);
    testarValidadorChegada(Teste::DEVE_DAR_ERRADO, &reserva1, -20, -30, -1000);


    testarValidadorChegada(Teste::DEVE_DAR_CERTO, &reserva1, 23, 03, 2002);


    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Reserva     |" << endl;
    cout << "                |  Testes Partida |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorPartida(Teste::DEVE_DAR_ERRADO, &reserva1, 33, 55, 5000);
    testarValidadorPartida(Teste::DEVE_DAR_ERRADO, &reserva1, -20, -30, -1000);

    testarValidadorChegada(Teste::DEVE_DAR_CERTO, &reserva1, 01, 03, 2022);

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Reserva     |" << endl;
    cout << "                | Testes Dinheiro |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorDinheiro(Teste::DEVE_DAR_ERRADO, &reserva1, -70);

    testarValidadorDinheiro(Teste::DEVE_DAR_CERTO, &reserva1, 2000);

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Reserva     |" << endl;
    cout << "                |  Testes Codigo  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorCodigo(Teste::DEVE_DAR_ERRADO, &reserva1, "");
    testarValidadorCodigo(Teste::DEVE_DAR_ERRADO, &reserva1, "12345678901215168468");

    testarValidadorCodigo(Teste::DEVE_DAR_CERTO, &reserva1, "1234567890");

    //------------------------------------------------------------------------------------------------------------------

    Data data1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |      Data       |" << endl;
    cout << "                |   Testes Data   |" << endl;
    cout << "                -------------------" << endl << endl;


    testarValidadorDia(Teste::DEVE_DAR_ERRADO, &data1, 40);
    testarValidadorMes(Teste::DEVE_DAR_ERRADO, &data1, 22);
    testarValidadorAno(Teste::DEVE_DAR_ERRADO, &data1, 5000);

    testarValidadorDia(Teste::DEVE_DAR_CERTO, &data1, 23);
    testarValidadorMes(Teste::DEVE_DAR_CERTO, &data1, 3);
    testarValidadorAno(Teste::DEVE_DAR_CERTO, &data1, 2002);

    cout << "Total de Testes: " << Teste::getTestes() << endl;
    cout << "Total de Testes Ok: " << Teste::getTestesOk() << endl;
    cout << "Total de Testes Problema: " << Teste::getTestesProblema() << endl;
}

//-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorNome(int esperando_resultado, Pessoa *ptr, string nome) {
    Teste::apresentacaoTeste(nome);
    int resultado_teste = 0;
    try {
        ptr->setNome(nome);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorEmail(int esperando_resultado, Pessoa *ptr, string email) {
    Teste::apresentacaoTeste(email);
    int resultado_teste = 0;
    try {
        ptr->setEmail(email);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

//-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorNome(int esperando_resultado, Gerente *ptr, string nome) {
    Teste::apresentacaoTeste(nome);
    int resultado_teste = 0;
    try {
        ptr->setNome(nome);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorEmail(int esperando_resultado, Gerente *ptr, string email) {
    Teste::apresentacaoTeste(email);
    int resultado_teste = 0;
    try {
        ptr->setEmail(email);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorRamal(int esperando_resultado, Gerente *ptr, string ramal) {
    Teste::apresentacaoTeste(ramal);
    int resultado_teste = 0;
    try {
        ptr->setRamal(ramal);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorSenha(int esperando_resultado, Gerente *ptr, string senha) {
    Teste::apresentacaoTeste(senha);
    int resultado_teste = 0;
    try {
        ptr->setSenha(senha);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

//-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorNome(int esperando_resultado, Hospede *ptr, string nome) {
    Teste::apresentacaoTeste(nome);
    int resultado_teste = 0;
    try {
        ptr->setNome(nome);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorEmail(int esperando_resultado, Hospede *ptr, string email) {
    Teste::apresentacaoTeste(email);
    int resultado_teste = 0;
    try {
        ptr->setEmail(email);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorCartao(int esperando_resultado, Hospede *ptr, string cartao) {
    Teste::apresentacaoTeste(cartao);
    int resultado_teste = 0;
    try {
        ptr->setCartao(cartao);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorEndereco(int esperando_resultado, Hospede *ptr, string endereco) {
    Teste::apresentacaoTeste(endereco);
    int resultado_teste = 0;
    try {
        ptr->setEndereco(endereco);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

//-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorNome(int esperando_resultado, Hotel *ptr, string nome) {
    Teste::apresentacaoTeste(nome);
    int resultado_teste = 0;
    try {
        ptr->setNome(nome);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorEndereco(int esperando_resultado, Hotel *ptr, string endereco) {
    Teste::apresentacaoTeste(endereco);
    int resultado_teste = 0;
    try {
        ptr->setEndereco(endereco);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorTelefone(int esperando_resultado, Hotel *ptr, string telefone) {
    Teste::apresentacaoTeste(telefone);
    int resultado_teste = 0;
    try {
        ptr->setTelefone(telefone);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorCodigo(int esperando_resultado, Hotel *ptr, string codigo) {
    Teste::apresentacaoTeste(codigo);
    int resultado_teste = 0;
    try {
        ptr->setCodigo(codigo);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

//-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorNumero(int esperando_resultado, Quarto *ptr, string numero) {
    Teste::apresentacaoTeste(numero);
    int resultado_teste = 0;
    try {
        ptr->setNumero(numero);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorCapacidade(int esperando_resultado, Quarto *ptr, int capacidade) {
    Teste::apresentacaoTeste(capacidade);
    int resultado_teste = 0;
    try {
        ptr->setCapacidade(capacidade);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorDinheiro(int esperando_resultado, Quarto *ptr, int diaria) {
    Teste::apresentacaoTeste(diaria);
    int resultado_teste = 0;
    try {
        ptr->setDiaria(diaria);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorRamal(int esperando_resultado, Quarto *ptr, string ramal) {
    Teste::apresentacaoTeste(ramal);
    int resultado_teste = 0;
    try {
        ptr->setRamal(ramal);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
} //-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorChegada(int esperando_resultado, Reserva *ptr, int dia, int mes, int ano) {
    Teste::apresentacaoTesteData(dia, mes, ano);
    int resultado_teste = 0;
    try {
        ptr->setChegada(dia, mes, ano);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorPartida(int esperando_resultado, Reserva *ptr, int dia, int mes, int ano) {
    Teste::apresentacaoTesteData(dia, mes, ano);
    int resultado_teste = 0;
    try {
        ptr->setPartida(dia, mes, ano);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorDinheiro(int esperando_resultado, Reserva *ptr, int dinheiro) {
    Teste::apresentacaoTeste(dinheiro);
    int resultado_teste = 0;
    try {
        ptr->setDinheiro(dinheiro);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorCodigo(int esperando_resultado, Reserva *ptr, string codigo) {
    Teste::apresentacaoTeste(codigo);
    int resultado_teste = 0;
    try {
        ptr->setCodigo(codigo);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

//-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorDia(int esperando_resultado, Data *ptr, int dia) {
    Teste::apresentacaoTeste(dia);
    int resultado_teste = 0;
    try {
        ptr->setData(dia, Data::JAN, 2000); //(valor, padrao , padrao)
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorMes(int esperando_resultado, Data *ptr, int mes) {
    Teste::apresentacaoTeste(mes);
    int resultado_teste = 0;
    try {
        ptr->setData(1, mes, 2000); //(padrao,valor, padrao)
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorAno(int esperando_resultado, Data *ptr, int ano) {
    Teste::apresentacaoTeste(ano);
    int resultado_teste = 0;
    try {
        ptr->setData(1, Data::JAN, ano); //(padrao, padrao , valor)
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}

//-----------------------------------------------------------------------------------------------------------
