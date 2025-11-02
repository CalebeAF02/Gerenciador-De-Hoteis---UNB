#include "Smoke_Tests.hpp"

void SmokeTest::testarEntradas() {
    //------------------------------------------------------------------------------------------------------------------

    cout << "----------------------------------------------" << endl;
    cout << "##############################################" << endl;
    cout << "----------------------------------------------" << endl;

    Gerente gerente1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Gerente     |" << endl;
    cout << "                |   Testes Nome   |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "Cb");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "Calebe Alves Freitas Madeira Alves");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "Calebe  Alves");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "Calebe   ");

    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "calebe alves");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "Calebe alves");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "Calebe@alves");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "Calebe Alves ");

    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "Luan Freitas");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "Kaio Rodrigues");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Gerente     |" << endl;
    cout << "                |  Testes Emails  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "Cb@gmail.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1,
                         "1234567890123456789012345678901234567890123456789012345678901234567890@gmail.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "calebe clves@gmail.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "calebe  clves@gmail.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1,
                         "calebeclves@1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.eb.mil.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, ".cb@gmail.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, ".-cb@gmail.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "c--b@gmail.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "c..b@gmail.com");

    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "calebeclves@citex.eb.mil.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "cb@gmail.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "luanfreitas@gmai.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "kaiorodrigues@gmail.com");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Gerente     |" << endl;
    cout << "                |   Testes Ramal  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "-1");

    testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "00");
    testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "50");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Gerente     |" << endl;
    cout << "                |   Testes Senha  |" << endl;
    cout << "                -------------------" << endl << endl;
    testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "AA1#2");
    testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "Aa1#2");
    testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "A12#3");
    testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "1#2#3");
    testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "A#B#C");
    testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "a#b#c");

    testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "A#b#3");
    testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "A1#a2");

    //------------------------------------------------------------------------------------------------------------------

    Hospede hospede1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                |   Testes Nome   |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "Cb");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "Calebe Alves Freitas Madeira Alves");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "Calebe  Alves");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "calebe alves");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "Calebe alves");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "Calebe@alves");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "Calebe Alves ");

    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "Luan Freitas");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "Kaio Rodrigues");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                |  Testes Emails  |" << endl;
    cout << "                -------------------" << endl << endl;


    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "Cb@gmail.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1,
                         "1234567890123456789012345678901234567890123456789012345678901234567890@gmail.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "calebe clves@gmail.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "calebe  clves@gmail.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1,
                         "calebeclves@1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.eb.mil.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, ".cb@gmail.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, ".-cb@gmail.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "c--b@gmail.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "c..b@gmail.com");

    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "calebeclves@citex.eb.mil.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "cb@gmail.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "luanfreitas@gmai.com");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "kaiorodrigues@gmail.com");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                | Testes Endereco |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorEndereco(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "");

    testarValidadorEndereco(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "Qd.52 Cs.02 Comercial DelLago");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                |  Testes Cartao  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorCartao(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "");

    testarValidadorCartao(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "1234567890123456");

    //------------------------------------------------------------------------------------------------------------------

    Hotel hotel1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |      Hotel      |" << endl;
    cout << "                |   Testes Nome   |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "Cb");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "Calebe Alves Freitas Madeira Alves");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "Calebe  Alves");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "calebe alves");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "Calebe alves");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "Calebe@alves");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "Calebe Alves ");

    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "Luan Freitas");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "Kaio Rodrigues");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |      Hotel      |" << endl;
    cout << "                | Testes Endereco |" << endl;
    cout << "                -------------------" << endl << endl;


    testarValidadorEndereco(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "");
    testarValidadorEndereco(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "Qd.52 Cs.02 Comercial DelLago");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |      Hotel      |" << endl;
    cout << "                | Testes Telefone |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorTelefone(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "");
    testarValidadorTelefone(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "5161993009537");
    testarValidadorTelefone(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "+123456789987654321");

    testarValidadorTelefone(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "+5161993009537");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |      Hotel      |" << endl;
    cout << "                |  Testes Codigo  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "");
    testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "5161993009537");
    testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "abcdedghij9987654321");

    testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "1234567890");
    testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "abcde12345");


    //------------------------------------------------------------------------------------------------------------------

    Quarto quarto1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Quarto      |" << endl;
    cout << "                |  Testes Numero  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorNumero(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, "-300");
    testarValidadorNumero(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, "000");
    testarValidadorNumero(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, "Ab$");

    testarValidadorNumero(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, "001");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Quarto      |" << endl;
    cout << "                |Testes Capacidade|" << endl;
    cout << "                -------------------" << endl << endl;


    testarValidadorCapacidade(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, 5);

    testarValidadorCapacidade(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, 1);

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Quarto      |" << endl;
    cout << "                |  Testes Diaria  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, -50);

    testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, 1000);
    testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, 80000);
    testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, 120000);


    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Quarto      |" << endl;
    cout << "                |   Testes Ramal  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, "0");
    testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, "100");

    testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, "10");


    //------------------------------------------------------------------------------------------------------------------

    Reserva reserva1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Reserva     |" << endl;
    cout << "                |  Testes Chegada |" << endl;
    cout << "                -------------------" << endl << endl;
    testarValidadorChegada(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, "33/55/5000");
    testarValidadorChegada(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, "-20/-30/-1000");


    testarValidadorChegada(InterfaceDeTeste::DEVE_DAR_CERTO, &reserva1, "23/03/2002");


    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Reserva     |" << endl;
    cout << "                |  Testes Partida |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorPartida(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, "33/55/5000");
    testarValidadorPartida(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, "-20/-30/-1000");

    testarValidadorChegada(InterfaceDeTeste::DEVE_DAR_CERTO, &reserva1, "01/03/2022");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Reserva     |" << endl;
    cout << "                | Testes Dinheiro |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, -70);

    testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_CERTO, &reserva1, 2000);

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Reserva     |" << endl;
    cout << "                |  Testes Codigo  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, "");
    testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, "12345678901215168468");

    testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_CERTO, &reserva1, "1234567890");

    //------------------------------------------------------------------------------------------------------------------

    Data data1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |      Data       |" << endl;
    cout << "                |   Testes Data   |" << endl;
    cout << "                -------------------" << endl << endl;


    testarValidadorDia(InterfaceDeTeste::DEVE_DAR_ERRADO, &data1, 40);
    testarValidadorMes(InterfaceDeTeste::DEVE_DAR_ERRADO, &data1, 22);
    testarValidadorAno(InterfaceDeTeste::DEVE_DAR_ERRADO, &data1, 5000);

    testarValidadorDia(InterfaceDeTeste::DEVE_DAR_CERTO, &data1, 23);
    testarValidadorMes(InterfaceDeTeste::DEVE_DAR_CERTO, &data1, 3);
    testarValidadorAno(InterfaceDeTeste::DEVE_DAR_CERTO, &data1, 2002);

    //------------------------------------------------------------------------------------------------------------------

    Gerente g_teste;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |       TSV       |" << endl;
    cout << "                | Testes Gerente  |" << endl;
    cout << "                -------------------" << endl << endl;

    g_teste.setNome(Nome("Calebe Alves"));
    g_teste.setEmail(Email("calebe.2324@gmail.com"));
    g_teste.setRamal(Ramal("22"));
    g_teste.setSenha(Senha("A1#a2"));

    //cout << "g1 =" << dadosGerente << endl;
    testarValidadorString(InterfaceDeTeste::DEVE_DAR_CERTO, g_teste.getTSV(),
                          "GERENTE\tCalebe Alves\tcalebe.2324@gmail.com\t22\tA1#a2");
    Gerente g2;
    string dadosGerente = g_teste.getTSV();
    g2.setTSV(dadosGerente);
    //cout << "g2 =" << g2.getTSV() << endl;
    testarValidadorString(InterfaceDeTeste::DEVE_DAR_CERTO, g_teste.getTSV(), g2.getTSV());

    Gerente g3;

    g3.setNome(Nome("Luan Freitas"));
    g3.setEmail(Email("luan.dkg@gmail.com"));
    g3.setRamal(Ramal("49"));
    g3.setSenha(Senha("C4$c5"));


    cout << "                -------------------" << endl;
    cout << "                |    Resultado    |" << endl;
    cout << "                |       TSV       |" << endl;
    cout << "                -------------------" << endl << endl;

    cout << "Total de Testes: " << InterfaceDeTeste::getTestes() << endl;
    cout << "Total de Testes Ok: " << InterfaceDeTeste::getTestesOk() << endl;
    cout << "Total de Testes Problema: " << InterfaceDeTeste::getTestesProblema() << endl << endl;

    cout << "----------------------------------------------" << endl;
    cout << "##############################################" << endl;
    cout << "----------------------------------------------" << endl;
}

//-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorString(int esperando_resultado, string s1, string s2) {
    InterfaceDeTeste::apresentacaoTeste(s1);
    int resultado_teste = 0;
    if (s1 == s2) {
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } else {
        resultado_teste = InterfaceDeTeste::apresentacaoErro("Erro: Strings sao diferentes");
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

//-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorNome(int esperando_resultado, Gerente *ptr, string nome) {
    InterfaceDeTeste::apresentacaoTeste(nome);
    int resultado_teste = 0;
    try {
        Nome nomeObj(nome);
        ptr->setNome(Nome(nomeObj));
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorEmail(int esperando_resultado, Gerente *ptr, string email) {
    InterfaceDeTeste::apresentacaoTeste(email);
    int resultado_teste = 0;
    try {
        Email emailObj(email);
        ptr->setEmail(Email(emailObj));
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorRamal(int esperando_resultado, Gerente *ptr, string ramal) {
    InterfaceDeTeste::apresentacaoTeste(ramal);
    int resultado_teste = 0;
    try {
        Ramal ramalObj(ramal);
        ptr->setRamal(ramalObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorSenha(int esperando_resultado, Gerente *ptr, string senha) {
    InterfaceDeTeste::apresentacaoTeste(senha);
    int resultado_teste = 0;
    try {
        Senha senhaObj(senha);
        ptr->setSenha(senhaObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

//-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorNome(int esperando_resultado, Hospede *ptr, string nome) {
    InterfaceDeTeste::apresentacaoTeste(nome);
    int resultado_teste = 0;
    try {
        Nome nomeObj(nome);
        ptr->setNome(Nome(nomeObj));
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorEmail(int esperando_resultado, Hospede *ptr, string email) {
    InterfaceDeTeste::apresentacaoTeste(email);
    int resultado_teste = 0;
    try {
        Email emailObj(email);
        ptr->setEmail(Email(emailObj));
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorCartao(int esperando_resultado, Hospede *ptr, string cartao) {
    InterfaceDeTeste::apresentacaoTeste(cartao);
    int resultado_teste = 0;
    try {
        Cartao cartaoObj(cartao);
        ptr->setCartao(cartaoObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorEndereco(int esperando_resultado, Hospede *ptr, string endereco) {
    InterfaceDeTeste::apresentacaoTeste(endereco);
    int resultado_teste = 0;
    try {
        Endereco enderecoObj(endereco);
        ptr->setEndereco(enderecoObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

//-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorNome(int esperando_resultado, Hotel *ptr, string nome) {
    InterfaceDeTeste::apresentacaoTeste(nome);
    int resultado_teste = 0;
    try {
        Nome nomeObj(nome);
        ptr->setNome(nomeObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorEndereco(int esperando_resultado, Hotel *ptr, string endereco) {
    InterfaceDeTeste::apresentacaoTeste(endereco);
    int resultado_teste = 0;
    try {
        Endereco enderecoObj(endereco);
        ptr->setEndereco(enderecoObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorTelefone(int esperando_resultado, Hotel *ptr, string telefone) {
    InterfaceDeTeste::apresentacaoTeste(telefone);
    int resultado_teste = 0;
    try {
        Telefone telefoneObj(telefone);
        ptr->setTelefone(telefoneObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorCodigo(int esperando_resultado, Hotel *ptr, string codigo) {
    InterfaceDeTeste::apresentacaoTeste(codigo);
    int resultado_teste = 0;
    try {
        Codigo codigoObj(codigo);
        ptr->setCodigo(codigoObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

//-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorNumero(int esperando_resultado, Quarto *ptr, string numero) {
    InterfaceDeTeste::apresentacaoTeste(numero);
    int resultado_teste = 0;
    try {
        Numero numeroObj(numero);
        ptr->setNumero(numeroObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorCapacidade(int esperando_resultado, Quarto *ptr, int capacidade) {
    InterfaceDeTeste::apresentacaoTeste(capacidade);
    int resultado_teste = 0;
    try {
        Capacidade capacidadeObj(capacidade);
        ptr->setCapacidade(capacidadeObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorDinheiro(int esperando_resultado, Quarto *ptr, int diaria) {
    InterfaceDeTeste::apresentacaoTeste(diaria);
    int resultado_teste = 0;
    try {
        Dinheiro diariaObj(diaria);
        ptr->setDiaria(diariaObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorRamal(int esperando_resultado, Quarto *ptr, string ramal) {
    InterfaceDeTeste::apresentacaoTeste(ramal);
    int resultado_teste = 0;
    try {
        Ramal ramalObj(ramal);
        ptr->setRamal(ramalObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
} //-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorChegada(int esperando_resultado, Reserva *ptr, string chegada) {
    InterfaceDeTeste::apresentacaoTesteData(chegada);
    int resultado_teste = 0;
    try {
        Data chegadaObj(chegada);
        ptr->setChegada(chegadaObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorPartida(int esperando_resultado, Reserva *ptr, string partida) {
    InterfaceDeTeste::apresentacaoTesteData(partida);
    int resultado_teste = 0;
    try {
        Data partidaObj(partida);
        ptr->setPartida(partidaObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorDinheiro(int esperando_resultado, Reserva *ptr, int dinheiro) {
    InterfaceDeTeste::apresentacaoTeste(dinheiro);
    int resultado_teste = 0;
    try {
        Dinheiro dinheiroObj(dinheiro);
        ptr->setDinheiro(dinheiroObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorCodigo(int esperando_resultado, Reserva *ptr, string codigo) {
    InterfaceDeTeste::apresentacaoTeste(codigo);
    int resultado_teste = 0;
    try {
        Codigo codigoObj(codigo);
        ptr->setCodigo(codigoObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

//-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorDia(int esperando_resultado, Data *ptr, int dia) {
    InterfaceDeTeste::apresentacaoTeste(dia);
    int resultado_teste = 0;
    try {
        ptr->setData(dia, Data::JAN, 2000); //(valor, padrao , padrao)
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorMes(int esperando_resultado, Data *ptr, int mes) {
    InterfaceDeTeste::apresentacaoTeste(mes);
    int resultado_teste = 0;
    try {
        ptr->setData(1, mes, 2000); //(padrao,valor, padrao)
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

void SmokeTest::testarValidadorAno(int esperando_resultado, Data *ptr, int ano) {
    InterfaceDeTeste::apresentacaoTeste(ano);
    int resultado_teste = 0;
    try {
        ptr->setData(1, Data::JAN, ano); //(padrao, padrao , valor)
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);
}

//-----------------------------------------------------------------------------------------------------------