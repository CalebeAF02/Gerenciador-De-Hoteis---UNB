//
// Created by caleb on 02/11/2025.
//

#include "TestandoSmoke.hpp"

#include "Smoke_Tests.hpp"

void TestandoSmoke::ChamandoOsTests() {
    TestesGerente("Testes Gerente","C1");
    TestesHospede( "Testes Hospede","C2");
    TestesHotel( "Testes Hotel","C3");
    TestesQuarto( "Testes Qaurto","C4");
    TestesReserva( "Testes Reserva","C5");
    TestesData( "Testes Data","C6");
    GerenteTSV( "Testes Gerente TSV","C7");
    ResultadoTSV( "Testes Resultado TSV","C8");
}

void TestandoSmoke::TestesGerente(string titulo, string contador){

    SmokeTest smoke_test;

    Gerente gerente1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Gerente     |" << endl;
    cout << "                |   Testes Nome   |" << endl;
    cout << "                -------------------" << endl << endl;

    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "Cb");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "Calebe Alves Freitas Madeira Alves");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "Calebe  Alves");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "Calebe   ");

    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "calebe alves");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "Calebe alves");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "Calebe@alves");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "Calebe Alves ");

    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "Luan Freitas");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "Kaio Rodrigues");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Gerente     |" << endl;
    cout << "                |  Testes Emails  |" << endl;
    cout << "                -------------------" << endl << endl;

    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "Cb@gmail.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1,
                         "1234567890123456789012345678901234567890123456789012345678901234567890@gmail.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "calebe clves@gmail.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "calebe  clves@gmail.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1,
                         "calebeclves@1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.eb.mil.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, ".cb@gmail.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, ".-cb@gmail.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "c--b@gmail.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "c..b@gmail.com");

    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "calebeclves@citex.eb.mil.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "cb@gmail.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "luanfreitas@gmai.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "kaiorodrigues@gmail.com");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Gerente     |" << endl;
    cout << "                |   Testes Ramal  |" << endl;
    cout << "                -------------------" << endl << endl;

    smoke_test.testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "-1");

    smoke_test.testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "00");
    smoke_test.testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "50");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Gerente     |" << endl;
    cout << "                |   Testes Senha  |" << endl;
    cout << "                -------------------" << endl << endl;
    smoke_test.testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "AA1#2");
    smoke_test.testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "Aa1#2");
    smoke_test.testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "A12#3");
    smoke_test.testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "1#2#3");
    smoke_test.testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "A#B#C");
    smoke_test.testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, "a#b#c");

    smoke_test.testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "A1b!3");
    smoke_test.testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "A1!b2");
}

//------------------------------------------------------------------------------------------------------------------
void TestandoSmoke::TestesHospede(string titulo, string contador) {
    SmokeTest smoke_test;

    Hospede hospede1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                |   Testes Nome   |" << endl;
    cout << "                -------------------" << endl << endl;

    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "Cb");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "Calebe Alves Freitas Madeira Alves");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "Calebe  Alves");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "calebe alves");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "Calebe alves");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "Calebe@alves");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "Calebe Alves ");

    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "Luan Freitas");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "Kaio Rodrigues");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                |  Testes Emails  |" << endl;
    cout << "                -------------------" << endl << endl;


    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "Cb@gmail.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1,
                         "1234567890123456789012345678901234567890123456789012345678901234567890@gmail.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "calebe clves@gmail.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "calebe  clves@gmail.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1,
                         "calebeclves@1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.eb.mil.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, ".cb@gmail.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, ".-cb@gmail.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "c--b@gmail.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "c..b@gmail.com");

    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "calebeclves@citex.eb.mil.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "cb@gmail.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "luanfreitas@gmai.com");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "kaiorodrigues@gmail.com");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                | Testes Endereco |" << endl;
    cout << "                -------------------" << endl << endl;

    smoke_test.testarValidadorEndereco(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "");

    smoke_test.testarValidadorEndereco(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "Qd.52 Cs.02 Comercial DelLago");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                |  Testes Cartao  |" << endl;
    cout << "                -------------------" << endl << endl;

    smoke_test.testarValidadorCartao(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, "");

    smoke_test.testarValidadorCartao(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "1234567890123456");
}

//------------------------------------------------------------------------------------------------------------------
void TestandoSmoke::TestesHotel(string titulo, string contador) {

    SmokeTest smoke_test;

    Hotel hotel1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |      Hotel      |" << endl;
    cout << "                |   Testes Nome   |" << endl;
    cout << "                -------------------" << endl << endl;

    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "Cb");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "Calebe Alves Freitas Madeira Alves");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "Calebe  Alves");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "calebe alves");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "Calebe alves");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "Calebe@alves");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "Calebe Alves ");

    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "Luan Freitas");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "Kaio Rodrigues");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |      Hotel      |" << endl;
    cout << "                | Testes Endereco |" << endl;
    cout << "                -------------------" << endl << endl;


    smoke_test.testarValidadorEndereco(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "");
    smoke_test.testarValidadorEndereco(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "Qd.52 Cs.02 Comercial DelLago");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |      Hotel      |" << endl;
    cout << "                | Testes Telefone |" << endl;
    cout << "                -------------------" << endl << endl;

    smoke_test.testarValidadorTelefone(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "");
    smoke_test.testarValidadorTelefone(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "5161993009537");
    smoke_test.testarValidadorTelefone(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "+123456789987654321");

    smoke_test.testarValidadorTelefone(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "+5161993009537");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |      Hotel      |" << endl;
    cout << "                |  Testes Codigo  |" << endl;
    cout << "                -------------------" << endl << endl;

    smoke_test.testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "");
    smoke_test.testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "5161993009537");
    smoke_test.testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, "abcdedghij9987654321");

    smoke_test.testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "1234567890");
    smoke_test.testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "abcde12345");
}

//------------------------------------------------------------------------------------------------------------------
void TestandoSmoke::TestesQuarto(string titulo, string contador) {

    SmokeTest smoke_test;

    Quarto quarto1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Quarto      |" << endl;
    cout << "                |  Testes Numero  |" << endl;
    cout << "                -------------------" << endl << endl;

    smoke_test.testarValidadorNumero(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, "-300");
    smoke_test.testarValidadorNumero(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, "000");
    smoke_test.testarValidadorNumero(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, "Ab$");

    smoke_test.testarValidadorNumero(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, "001");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Quarto      |" << endl;
    cout << "                |Testes Capacidade|" << endl;
    cout << "                -------------------" << endl << endl;


    smoke_test.testarValidadorCapacidade(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, 5);

    smoke_test.testarValidadorCapacidade(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, 1);

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Quarto      |" << endl;
    cout << "                |  Testes Diaria  |" << endl;
    cout << "                -------------------" << endl << endl;

    smoke_test.testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, -50);

    smoke_test.testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, 1000);
    smoke_test.testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, 80000);
    smoke_test.testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, 120000);


    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Quarto      |" << endl;
    cout << "                |   Testes Ramal  |" << endl;
    cout << "                -------------------" << endl << endl;

    smoke_test.testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, "0");
    smoke_test.testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, "100");

    smoke_test.testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, "10");
}

//------------------------------------------------------------------------------------------------------------------
void TestandoSmoke::TestesReserva(string titulo, string contador){

    SmokeTest smoke_test;

    Reserva reserva1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Reserva     |" << endl;
    cout << "                |  Testes Chegada |" << endl;
    cout << "                -------------------" << endl << endl;
    smoke_test.testarValidadorChegada(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, "33/55/5000");
    smoke_test.testarValidadorChegada(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, "-20/-30/-1000");


    smoke_test.testarValidadorChegada(InterfaceDeTeste::DEVE_DAR_CERTO, &reserva1, "23/03/2002");


    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Reserva     |" << endl;
    cout << "                |  Testes Partida |" << endl;
    cout << "                -------------------" << endl << endl;

    smoke_test.testarValidadorPartida(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, "33/55/5000");
    smoke_test.testarValidadorPartida(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, "-20/-30/-1000");

    smoke_test.testarValidadorChegada(InterfaceDeTeste::DEVE_DAR_CERTO, &reserva1, "01/03/2022");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Reserva     |" << endl;
    cout << "                | Testes Dinheiro |" << endl;
    cout << "                -------------------" << endl << endl;

    smoke_test.testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, -70);

    smoke_test.testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_CERTO, &reserva1, 2000);

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Reserva     |" << endl;
    cout << "                |  Testes Codigo  |" << endl;
    cout << "                -------------------" << endl << endl;

    smoke_test.testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, "");
    smoke_test.testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, "12345678901215168468");

    smoke_test.testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_CERTO, &reserva1, "1234567890");
}

//------------------------------------------------------------------------------------------------------------------
void TestandoSmoke::TestesData(string titulo, string contador){

    SmokeTest smoke_test;

    Data data1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |      Data       |" << endl;
    cout << "                |   Testes Data   |" << endl;
    cout << "                -------------------" << endl << endl;


    smoke_test.testarValidadorDia(InterfaceDeTeste::DEVE_DAR_ERRADO, &data1, 40);
    smoke_test.testarValidadorMes(InterfaceDeTeste::DEVE_DAR_ERRADO, &data1, 22);
    smoke_test.testarValidadorAno(InterfaceDeTeste::DEVE_DAR_ERRADO, &data1, 5000);

    smoke_test.testarValidadorDia(InterfaceDeTeste::DEVE_DAR_CERTO, &data1, 23);
    smoke_test.testarValidadorMes(InterfaceDeTeste::DEVE_DAR_CERTO, &data1, 3);
    smoke_test.testarValidadorAno(InterfaceDeTeste::DEVE_DAR_CERTO, &data1, 2002);
}

//------------------------------------------------------------------------------------------------------------------
void TestandoSmoke::GerenteTSV(string titulo, string contador){

    SmokeTest smoke_test;

    Gerente g_teste;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |       TSV       |" << endl;
    cout << "                | Testes Gerente  |" << endl;
    cout << "                -------------------" << endl << endl;

    g_teste.setNome(Nome("Calebe"));
    g_teste.setEmail(Email("calebe.2324@gmail.com"));
    g_teste.setRamal(Ramal("22"));
    g_teste.setSenha(Senha("A1!b2"));

    //cout << "g1 =" << dadosGerente << endl;
    smoke_test.testarValidadorString(InterfaceDeTeste::DEVE_DAR_CERTO, g_teste.getTSV(),
                          "GERENTE\tCalebe\tcalebe.2324@gmail.com\t22\tA1!b2");
    Gerente g2;
    string dadosGerente = g_teste.getTSV();
    g2.setTSV(dadosGerente);
    //cout << "g2 =" << g2.getTSV() << endl;
    smoke_test.testarValidadorString(InterfaceDeTeste::DEVE_DAR_CERTO, g_teste.getTSV(), g2.getTSV());

    Gerente g3;

    g3.setNome(Nome("Luan Freitas"));
    g3.setEmail(Email("luan.dkg@gmail.com"));
    g3.setRamal(Ramal("49"));
    g3.setSenha(Senha("C4$c5"));
}
//------------------------------------------------------------------------------------------------------------------

void TestandoSmoke::ResultadoTSV(string titulo, string contador){
    cout << "                -------------------" << endl;
    cout << "                |    Resultado    |" << endl;
    cout << "                |       TSV       |" << endl;
    cout << "                -------------------" << endl << endl;

    int tests = InterfaceDeTeste::getTestes();
    cout << "\nTotal de Testes: " << tests;

    int testsOK = InterfaceDeTeste::getTestesOk();
    cout << "\nTotal de Testes Ok: " << testsOK;

    int TestesProblema = InterfaceDeTeste::getTestesProblema();
    cout << "\nTotal de Testes Problema: " << TestesProblema;


    cout << "\n\n";
}
//------------------------------------------------------------------------------------------------------------------
