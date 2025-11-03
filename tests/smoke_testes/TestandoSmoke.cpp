//
// Created by caleb on 02/11/2025.
//

#include "TestandoSmoke.hpp"

using namespace std;

//------------------------------------------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------------------------------------------
void TestandoSmoke::TestesGerente(string titulo, string contador) {
    SmokeTest smoke_test;
    Gerente gerente1;

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE DOMINIO: GERENTE");

    // =========================================================================
    // 1. VALIDACAO DE NOME
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria(
        "1. Validacao de Nome (4 a 30 caracteres, 1o maiusculo, Apenas 1 espaco)");

    // A. Casos Invalidos
    vector<string> nomesInvalidos = {
        "", "Cb", "Calebe Alves Freitas Madeira Alves", "Calebe  Alves", "Calebe   ",
        "calebe alves", "Calebe alves", "Calebe@alves", "Calebe Alves "
    };

    for (const string &nome: nomesInvalidos) {
        smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, nome);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "Luan Freitas");

    // =========================================================================
    // 2. VALIDACAO DE EMAIL
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("2. Validacao de Email (Padrao: AAAA@BBBB.CCC, min 3, max 64 no local)");

    // A. Casos Invalidos
    vector<string> emailsInvalidos = {
        "", "Cb@gmail.com",
        "1234567890123456789012345678901234567890123456789012345678901234567890@gmail.com", // Usuario muito longo
        "calebe clves@gmail.com", "calebe  clves@gmail.com", ".cb@gmail.com", ".-cb@gmail.com",
        "c--b@gmail.com", "c..b@gmail.com",
        "calebeclves@1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.eb.mil.com"
        // Dominio muito longo
    };

    for (const string &email: emailsInvalidos) {
        smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, email);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "calebeclves@citex.eb.mil.com");


    // =========================================================================
    // 3. VALIDACAO DE RAMAL
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("3. Validacao de Ramal (2 digitos numericos, 00 a 50)");

    // A. Casos Invalidos
    vector<string> ramaisInvalidos = {
        "-1", "51", "abc", ""
    };

    for (const string &ramal: ramaisInvalidos) {
        smoke_test.testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, ramal);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "49");


    // =========================================================================
    // 4. VALIDACAO DE SENHA
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("4. Validacao de Senha (5 caracteres: M, m, d, #)");

    // A. Casos Invalidos
    vector<string> senhasInvalidas = {
        "AA1#2", "Aa1#2", "A12#3", "1#2#3", "A#B#C", "a#b#c", ""
    };

    for (const string &senha: senhasInvalidas) {
        smoke_test.testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente1, senha);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorSenha(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente1, "A1!b2");
}

//------------------------------------------------------------------------------------------------------------------
void TestandoSmoke::TestesHospede(string titulo, string contador) {
    SmokeTest smoke_test;
    Hospede hospede1;

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE DOMINIO: HOSPEDE");

    // =========================================================================
    // 1. VALIDACAO DE NOME (Compartilhado com Gerente)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria(
        "1. Validacao de Nome (4 a 30 caracteres, 1o maiusculo, Apenas 1 espaco)");

    // A. Casos Invalidos
    vector<string> nomesInvalidos = {
        "", "Cb", "Calebe Alves Freitas Madeira Alves", "Calebe  Alves",
        "calebe alves", "Calebe alves", "Calebe@alves", "Calebe Alves "
    };

    for (const string &nome: nomesInvalidos) {
        smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, nome);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "Kaio Rodrigues");


    // =========================================================================
    // 2. VALIDACAO DE EMAIL (Compartilhado com Gerente)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("2. Validacao de Email (Padrao: AAAA@BBBB.CCC)");

    // A. Casos Invalidos
    vector<string> emailsInvalidos = {
        "", "Cb@gmail.com",
        "1234567890123456789012345678901234567890123456789012345678901234567890@gmail.com",
        "calebe clves@gmail.com", "calebe  clves@gmail.com", ".cb@gmail.com", ".-cb@gmail.com",
        "c--b@gmail.com", "c..b@gmail.com",
        "calebeclves@123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.eb.mil.com"
    };

    for (const string &email: emailsInvalidos) {
        smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, email);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "luanfreitas@gmai.com");

    // =========================================================================
    // 3. VALIDACAO DE ENDERECO
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria(
        "3. Validacao de Endereco (1 a 20 caracteres alfanumericos, inclui . e espacos)");

    // A. Casos Invalidos
    vector<string> enderecosInvalidos = {
        "", "Endereco com Caractere Invalido!"
    };

    for (const string &endereco: enderecosInvalidos) {
        smoke_test.testarValidadorEndereco(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, endereco);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorEndereco(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "Qd.52 Cs.02 Comercial DelLago");

    // =========================================================================
    // 4. VALIDACAO DE CARTAO
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("4. Validacao de Cartao (16 digitos numericos)");

    // A. Casos Invalidos
    vector<string> cartoesInvalidos = {
        "", "123456789012345", "12345678901234567", "123456789012A456"
    };

    for (const string &cartao: cartoesInvalidos) {
        smoke_test.testarValidadorCartao(InterfaceDeTeste::DEVE_DAR_ERRADO, &hospede1, cartao);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorCartao(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede1, "1234567890123456");
}

//------------------------------------------------------------------------------------------------------------------
void TestandoSmoke::TestesHotel(string titulo, string contador) {
    SmokeTest smoke_test;
    Hotel hotel1;

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE DOMINIO: HOTEL");

    // =========================================================================
    // 1. VALIDACAO DE NOME
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria(
        "1. Validacao de Nome (4 a 30 caracteres, 1o maiusculo, Apenas 1 espaco)");

    // A. Casos Invalidos
    vector<string> nomesInvalidos = {
        "", "Cb", "Calebe Alves Freitas Madeira Alves", "Calebe  Alves",
        "calebe alves", "Calebe alves", "Calebe@alves", "Calebe Alves "
    };

    for (const string &nome: nomesInvalidos) {
        smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, nome);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "Luan Freitas");

    // =========================================================================
    // 2. VALIDACAO DE ENDERECO
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("2. Validacao de Endereco");

    // A. Casos Invalidos
    vector<string> enderecosInvalidos = {
        ""
    };

    for (const string &endereco: enderecosInvalidos) {
        smoke_test.testarValidadorEndereco(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, endereco);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorEndereco(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "Qd.52 Cs.02 Comercial DelLago");

    // =========================================================================
    // 3. VALIDACAO DE TELEFONE
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("3. Validacao de Telefone (12 a 16 digitos, iniciando com '+')");

    // A. Casos Invalidos
    vector<string> telefonesInvalidos = {
        "", "5161993009537", "+123456789987654321", "+5161A993009537", "+123"
    };

    for (const string &telefone: telefonesInvalidos) {
        smoke_test.testarValidadorTelefone(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, telefone);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorTelefone(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "+5161993009537");

    // =========================================================================
    // 4. VALIDACAO DE CODIGO
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("4. Validacao de Codigo (10 caracteres, alfanumerico)");

    // A. Casos Invalidos
    vector<string> codigosInvalidos = {
        "", "5161993009537", "abcdedghij9987654321", "abcde12!34"
    };

    for (const string &codigo: codigosInvalidos) {
        smoke_test.testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_ERRADO, &hotel1, codigo);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel1, "1234567890");
}

//------------------------------------------------------------------------------------------------------------------
void TestandoSmoke::TestesQuarto(string titulo, string contador) {
    SmokeTest smoke_test;
    Quarto quarto1;

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE DOMINIO: QUARTO");

    // =========================================================================
    // 1. VALIDACAO DE NUMERO
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("1. Validacao de Numero (3 digitos, > 000)");

    // A. Casos Invalidos
    vector<string> numerosInvalidos = {
        "-300", "000", "Ab$", ""
    };

    for (const string &numero: numerosInvalidos) {
        smoke_test.testarValidadorNumero(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, numero);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorNumero(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, "001");

    // =========================================================================
    // 2. VALIDACAO DE CAPACIDADE
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("2. Validacao de Capacidade (1 a 4 pessoas)");

    // A. Casos Invalidos
    vector<int> capacidadesInvalidas = {
        0, 5, -1
    };

    for (const int &capacidade: capacidadesInvalidas) {
        smoke_test.testarValidadorCapacidade(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, capacidade);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorCapacidade(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, 4);

    // =========================================================================
    // 3. VALIDACAO DE DIARIA (DINHEIRO)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("3. Validacao de Diaria (Valor inteiro positivo)");

    // A. Casos Invalidos
    vector<int> diariasInvalidas = {
        -50, 0
    };

    for (const int &diaria: diariasInvalidas) {
        smoke_test.testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, diaria);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, 120000);

    // =========================================================================
    // 4. VALIDACAO DE RAMAL
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("4. Validacao de Ramal (2 digitos, 10 a 99)");

    // A. Casos Invalidos
    vector<string> ramaisInvalidos = {
        "0", "100", ""
    };

    for (const string &ramal: ramaisInvalidos) {
        smoke_test.testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_ERRADO, &quarto1, ramal);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto1, "10");
}

//------------------------------------------------------------------------------------------------------------------
void TestandoSmoke::TestesReserva(string titulo, string contador){
    SmokeTest smoke_test;
    Reserva reserva1;

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE DOMINIO: RESERVA");

    // =========================================================================
    // 1. VALIDACAO DE DATA DE CHEGADA (STRING)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("1. Validacao de Data de Chegada (DD/MM/AAAA)");

    // A. Casos Invalidos
    vector<string> datasInvalidas = {
        "33/55/5000", "-20/-30/-1000", "01/01/1999", "30/02/2023", ""
    };

    for (const string &data: datasInvalidas) {
        smoke_test.testarValidadorChegada(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, data);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorChegada(InterfaceDeTeste::DEVE_DAR_CERTO, &reserva1, "23/03/2002");


    // =========================================================================
    // 2. VALIDACAO DE DATA DE PARTIDA (STRING)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("2. Validacao de Data de Partida (DD/MM/AAAA)");

    // A. Casos Invalidos
    vector<string> partidasInvalidas = {
        "33/55/5000", "-20/-30/-1000", "01/01/1999"
    };

    for (const string &data: partidasInvalidas) {
        smoke_test.testarValidadorPartida(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, data);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorChegada(InterfaceDeTeste::DEVE_DAR_CERTO, &reserva1, "01/03/2022");


    // =========================================================================
    // 3. VALIDACAO DE DINHEIRO
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("3. Validacao de Dinheiro (Valor inteiro positivo)");

    // A. Casos Invalidos
    vector<int> dinheirosInvalidos = {
        -70, 0
    };

    for (const int &dinheiro: dinheirosInvalidos) {
        smoke_test.testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, dinheiro);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_CERTO, &reserva1, 2000);

    // =========================================================================
    // 4. VALIDACAO DE CODIGO
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("4. Validacao de Codigo (10 caracteres, alfanumerico)");

    // A. Casos Invalidos
    vector<string> codigosInvalidos = {
        "", "12345678901215168468", "abcde!fghi"
    };

    for (const string &codigo: codigosInvalidos) {
        smoke_test.testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_ERRADO, &reserva1, codigo);
    }

    // B. Caso Valido (Apenas 1)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido Unico (Referencia Correta):");
    smoke_test.testarValidadorCodigo(InterfaceDeTeste::DEVE_DAR_CERTO, &reserva1, "1234567890");
}

//------------------------------------------------------------------------------------------------------------------
void TestandoSmoke::TestesData(string titulo, string contador){
    SmokeTest smoke_test;
    Data data1;

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE DOMINIO: DATA (Membros internos)");

    // =========================================================================
    // 1. VALIDACAO DE DIA, MES, ANO (Membros internos)
    // =========================================================================
    ConsoleFormatter::MostrarSeparadorCategoria("1. Validacao de Dia, Mes, Ano");

    // A. Casos Invalidos
    vector<int> diasInvalidos = {40, 0, -5};
    vector<int> mesesInvalidos = {22, 0, -1};
    vector<int> anosInvalidos = {5000, 1999, 10000};

    ConsoleIO::PrintMensagem("-> Testando Dias Invalidos:");
    for (const int &dia: diasInvalidos) {
        smoke_test.testarValidadorDia(InterfaceDeTeste::DEVE_DAR_ERRADO, &data1, dia);
    }

    ConsoleIO::PrintMensagem("-> Testando Meses Invalidos:");
    for (const int &mes: mesesInvalidos) {
        smoke_test.testarValidadorMes(InterfaceDeTeste::DEVE_DAR_ERRADO, &data1, mes);
    }

    ConsoleIO::PrintMensagem("-> Testando Anos Invalidos:");
    for (const int &ano: anosInvalidos) {
        smoke_test.testarValidadorAno(InterfaceDeTeste::DEVE_DAR_ERRADO, &data1, ano);
    }

    // B. Caso Valido (Apenas 1 de cada)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Casos Validos Unicos (Referencia Correta):");
    smoke_test.testarValidadorDia(InterfaceDeTeste::DEVE_DAR_CERTO, &data1, 23);
    smoke_test.testarValidadorMes(InterfaceDeTeste::DEVE_DAR_CERTO, &data1, 3);
    smoke_test.testarValidadorAno(InterfaceDeTeste::DEVE_DAR_CERTO, &data1, 2002);
}

//------------------------------------------------------------------------------------------------------------------
void TestandoSmoke::GerenteTSV(string titulo, string contador){
    SmokeTest smoke_test;
    Gerente g_teste;

    ConsoleFormatter::MostrarTituloEmCaixa("TESTES DE PERSISTENCIA: TSV");

    ConsoleFormatter::MostrarSeparadorCategoria("Validacao de Gerente TSV (SERIALIZACAO/DESSERIALIZACAO)");

    // Teste 1: Serializacao (Criar TSV)
    g_teste.setNome(Nome("Calebe"));
    g_teste.setEmail(Email("calebe.2324@gmail.com"));
    g_teste.setRamal(Ramal("22"));
    g_teste.setSenha(Senha("A1!b2"));

    // Caso 1 Valido (Serializacao)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido 1 (Criacao de TSV):");
    smoke_test.testarValidadorString(InterfaceDeTeste::DEVE_DAR_CERTO, g_teste.getTSV(),
                          "GERENTE\tCalebe\tcalebe.2324@gmail.com\t22\tA1!b2");

    // Teste 2: Desserializacao (Ler TSV)
    Gerente g2;
    string dadosGerente = g_teste.getTSV();
    g2.setTSV(dadosGerente);

    // Caso 2 Valido (Leitura de TSV - Verifica se o objeto lido é igual ao original)
    ConsoleFormatter::MostrarSeparadorDeTeste();
    ConsoleIO::PrintMensagem("Caso Valido 2 (Leitura de TSV):");
    smoke_test.testarValidadorString(InterfaceDeTeste::DEVE_DAR_CERTO, g_teste.getTSV(), g2.getTSV());

}

//------------------------------------------------------------------------------------------------------------------
void TestandoSmoke::ResultadoTSV(string titulo, string contador) {
    // Este metodo agora simplesmente delega a responsabilidade para a InterfaceDeTeste
    InterfaceDeTeste::mostrarSumarioGeral();
}

//------------------------------------------------------------------------------------------------------------------