#include "Smoke_Tests.hpp"
/*
void SmokeTest::testarEntradas() {

};
*/
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