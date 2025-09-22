//
// Created by caleb on 20/09/2025.
//

#include "testes_validadores.h"

void TesteValidadores::testarEntradas() {

    Pessoa pessoa1, pessoa2;

    //------------------------------------------------------------------------------------------------------------------

    Gerente gerente1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Gerente     |" << endl;
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
    cout << "                |     Gerente     |" << endl;
    cout << "                |  Testes Emails  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1, "");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1, "Cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1,"1234567890123456789012345678901234567890123456789012345678901234567890@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1, "calebe clves@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1, "calebe  clves@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1,"calebeclves@1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.eb.mil.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1, ".cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1, ".-cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1, "c--b@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa1, "c..b@gmail.com");

    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &pessoa1, "calebeclves@citex.eb.mil.com");
    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &pessoa1, "cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &pessoa1, "luanfreitas@gmai.com");
    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &pessoa1, "kaiorodrigues@gmail.com");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Gerente     |" << endl;
    cout << "                |   Testes Ramal  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorRamal(Teste::DEVE_DAR_CERTO, &gerente1, 00);

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Gerente     |" << endl;
    cout << "                |   Testes Senha  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorSenha(Teste::DEVE_DAR_CERTO, &gerente1, "A1#a2$");

    //------------------------------------------------------------------------------------------------------------------

    Hospede hospede1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                |   Testes Nome   |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &pessoa2, "");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &pessoa2, "Cb");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &pessoa2, "Calebe Alves Freitas Madeira Alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &pessoa2, "Calebe  Alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &pessoa2, "calebe alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &pessoa2, "Calebe alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &pessoa2, "Calebe@alves");
    testarValidadorNome(Teste::DEVE_DAR_ERRADO, &pessoa2, "Calebe Alves ");

    testarValidadorNome(Teste::DEVE_DAR_CERTO, &pessoa2, "Luan Freitas");
    testarValidadorNome(Teste::DEVE_DAR_CERTO, &pessoa2, "Kaio Rodrigues");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                |  Testes Emails  |" << endl;
    cout << "                -------------------" << endl << endl;


    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa2, "");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa2, "Cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa2,"1234567890123456789012345678901234567890123456789012345678901234567890@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa2, "calebe clves@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa2, "calebe  clves@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa2,"calebeclves@1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.eb.mil.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa2, ".cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa2, ".-cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa2, "c--b@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_ERRADO, &pessoa2, "c..b@gmail.com");

    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &pessoa2, "calebeclves@citex.eb.mil.com");
    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &pessoa2, "cb@gmail.com");
    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &pessoa2, "luanfreitas@gmai.com");
    testarValidadorEmail(Teste::DEVE_DAR_CERTO, &pessoa2, "kaiorodrigues@gmail.com");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                | Testes Endereço |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorEndereco(Teste::DEVE_DAR_ERRADO, &hospede1, "calebe alves");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                |  Testes Cartao  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorCartao(Teste::DEVE_DAR_ERRADO, &hospede1, "calebe alves");

    //------------------------------------------------------------------------------------------------------------------

    Hotel hotel1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                |   Testes Nome   |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorNome(Teste::DEVE_DAR_CERTO, &hotel1, "Quadra 52, Casa 02, Comercial Del Lago");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                | Testes Endereço |" << endl;
    cout << "                -------------------" << endl << endl;


    testarValidadorEndereco(Teste::DEVE_DAR_CERTO, &hotel1, "");// Vai dar errado
    testarValidadorEndereco(Teste::DEVE_DAR_CERTO, &hotel1, "Quadra 52, Casa 02, Comercial Del Lago");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                | Testes Telefone |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorTelefone(Teste::DEVE_DAR_CERTO, &hotel1, "Quadra 52, Casa 02, Comercial Del Lago");

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                |  Testes Codigo  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorCodigo(Teste::DEVE_DAR_CERTO, &hotel1, "Quadra 52, Casa 02, Comercial Del Lago");


    //------------------------------------------------------------------------------------------------------------------

    Quarto quarto1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                |  Testes Numero  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorNumero(Teste::DEVE_DAR_CERTO, &quarto1, 000);// Vai dar errado

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                | Testes Capacidade |" << endl;
    cout << "                -------------------" << endl << endl;


    testarValidadorCapacidade(Teste::DEVE_DAR_ERRADO, &quarto1, 5);

    testarValidadorCapacidade(Teste::DEVE_DAR_CERTO, &quarto1, 1);

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                | Testes Dinheiro |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorDinheiro(Teste::DEVE_DAR_ERRADO, &quarto1, -50);// Vai dar errado

    testarValidadorDinheiro(Teste::DEVE_DAR_CERTO, &quarto1, 1000);// Vai dar errado

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Hospede     |" << endl;
    cout << "                |   Testes Ramal  |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorRamal(Teste::DEVE_DAR_ERRADO, &quarto1, 100);// Vai dar errado

    testarValidadorRamal(Teste::DEVE_DAR_CERTO, &quarto1, 10);// Vai dar errado


    //------------------------------------------------------------------------------------------------------------------

    Reserva reserva1;

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Chegada     |" << endl;
    cout << "                |  Testes Resreva |" << endl;
    cout << "                -------------------" << endl << endl;

    //testarValidadorChegada(Teste::DEVE_DAR_ERRADO, &reserva1, 40);


    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Partida     |" << endl;
    cout << "                |  Testes Resreva |" << endl;
    cout << "                -------------------" << endl << endl;

    //testarValidadorPartida(Teste::DEVE_DAR_ERRADO, &reserva1, 40);

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Dinheiro    |" << endl;
    cout << "                |  Testes Resreva |" << endl;
    cout << "                -------------------" << endl << endl;

    testarValidadorDinheiro(Teste::DEVE_DAR_ERRADO, &reserva1, -70);// Vai dar errado

    testarValidadorDinheiro(Teste::DEVE_DAR_CERTO, &reserva1, 2000);// Vai dar errado

    cout << "                -------------------" << endl;
    cout << "                |     Testes      |" << endl;
    cout << "                |     Codigo      |" << endl;
    cout << "                |  Testes Resreva |" << endl;
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
void TesteValidadores::testarValidadorNome(int esperando_resultado, Pessoa *ptr, string nome) {
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
//-----------------------------------------------------------------------------------------------------------
void TesteValidadores::testarValidadorEmail(int esperando_resultado, Pessoa *ptr, string email) {
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
void TesteValidadores::testarValidadorNome(int esperando_resultado, Gerente *ptr, string nome) {
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
//-----------------------------------------------------------------------------------------------------------
void TesteValidadores::testarValidadorEmail(int esperando_resultado, Gerente *ptr, string email) {
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
void TesteValidadores::testarValidadorRamal(int esperando_resultado, Gerente *ptr, int ramal) {
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
//-----------------------------------------------------------------------------------------------------------
void TesteValidadores::testarValidadorSenha(int esperando_resultado, Gerente *ptr, string senha) {
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
void TesteValidadores::testarValidadorNome(int esperando_resultado, Hospede *ptr, string nome) {
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
//-----------------------------------------------------------------------------------------------------------
void TesteValidadores::testarValidadorEmail(int esperando_resultado, Hospede *ptr, string email) {
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
void TesteValidadores::testarValidadorCartao(int esperando_resultado, Hospede *ptr, string cartao) {
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
//-----------------------------------------------------------------------------------------------------------
void TesteValidadores::testarValidadorEndereco(int esperando_resultado, Hospede *ptr, string endereco) {
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
void TesteValidadores::testarValidadorNome(int esperando_resultado, Hotel *ptr, string nome) {
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
//-----------------------------------------------------------------------------------------------------------
void TesteValidadores::testarValidadorEndereco(int esperando_resultado, Hotel *ptr, string endereco) {
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
void TesteValidadores::testarValidadorTelefone(int esperando_resultado, Hotel *ptr, string telefone) {
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
//-----------------------------------------------------------------------------------------------------------
void TesteValidadores::testarValidadorCodigo(int esperando_resultado, Hotel *ptr, string codigo) {
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
void TesteValidadores::testarValidadorNumero(int esperando_resultado, Quarto *ptr, int numero) {
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
//-----------------------------------------------------------------------------------------------------------
void TesteValidadores::testarValidadorCapacidade(int esperando_resultado, Quarto *ptr, int capacidade) {
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
//-----------------------------------------------------------------------------------------------------------
void TesteValidadores::testarValidadorDinheiro(int esperando_resultado, Quarto *ptr, int diaria) {
    Teste::apresentacaoTeste(diaria);
    int resultado_teste = 0;
    try {
        ptr->setDinheiro(diaria);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}
//-----------------------------------------------------------------------------------------------------------
void TesteValidadores::testarValidadorRamal(int esperando_resultado, Quarto *ptr, int ramal) {
    Teste::apresentacaoTeste(ramal);
    int resultado_teste = 0;
    try {
        ptr->setRamal(ramal);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);

}//-----------------------------------------------------------------------------------------------------------
void TesteValidadores::testarValidadorChegada(int esperando_resultado, Reserva *ptr, string chegada) {
    Teste::apresentacaoTeste(chegada);
    int resultado_teste = 0;
    try {
        ptr->setChegada(chegada);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}
//-----------------------------------------------------------------------------------------------------------
void TesteValidadores::testarValidadorPartida(int esperando_resultado, Reserva *ptr, string partida) {
    Teste::apresentacaoTeste(partida);
    int resultado_teste = 0;
    try {
        ptr->setPartida(partida);
        resultado_teste = Teste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        resultado_teste = Teste::apresentacaoErro(erro);
    }
    Teste::checaResultado(esperando_resultado, resultado_teste);
}
//-----------------------------------------------------------------------------------------------------------
void TesteValidadores::testarValidadorDinheiro(int esperando_resultado, Reserva *ptr, int dinheiro) {
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
//-----------------------------------------------------------------------------------------------------------
void TesteValidadores::testarValidadorCodigo(int esperando_resultado, Reserva *ptr, string codigo) {
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
void TesteValidadores::testarValidadorDia(int esperando_resultado, Data *ptr, int dia) {
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
void TesteValidadores::testarValidadorMes(int esperando_resultado, Data *ptr, int mes) {
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
void TesteValidadores::testarValidadorAno(int esperando_resultado, Data *ptr, int ano) {
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
