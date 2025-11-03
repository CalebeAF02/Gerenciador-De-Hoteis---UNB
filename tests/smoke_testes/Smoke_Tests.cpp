#include "Smoke_Tests.hpp"

void SmokeTest::testarEntradas() {
    cout << "\n=======================================================" << endl;
    cout << "           INICIANDO TESTE DE FUMAÇA (SMOKE TEST)        " << endl;
    cout << "=======================================================" << endl;

    // Criando instâncias de objetos para os testes
    Gerente gerente;
    Hospede hospede;
    Hotel hotel;
    Quarto quarto;
    Reserva reserva;
    Data data; // para testar os componentes de Data separadamente

    //---------------------------------------------------------
    // 1. EXEMPLOS DE TESTE DE NOME (SUCESSO E FALHA ESPERADA)
    //---------------------------------------------------------
    cout << "\n*** TESTANDO DOMÍNIO NOME (PESSOA) ***" << endl;
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente, "Calebe Alves Ferreira");
    testarValidadorNome(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente, "ca"); // Nome muito curto

    //---------------------------------------------------------
    // 2. EXEMPLOS DE TESTE DE EMAIL (SUCESSO E FALHA)
    //---------------------------------------------------------
    cout << "\n*** TESTANDO DOMÍNIO EMAIL (GERENTE) ***" << endl;
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente, "teste.gerente@unb.br");
    testarValidadorEmail(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente, "email_invalido"); // Falta o @

    //---------------------------------------------------------
    // 3. EXEMPLO DE TESTE DE RAMAL (SE SEU ERRO ERA AQUI)
    //---------------------------------------------------------
    cout << "\n*** TESTANDO DOMÍNIO RAMAL (GERENTE) ***" << endl;
    testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_CERTO, &gerente, "15");
    testarValidadorRamal(InterfaceDeTeste::DEVE_DAR_ERRADO, &gerente, "99"); // Ramal fora do limite (se for 00-50)

    //---------------------------------------------------------
    // 4. EXEMPLO DE TESTE DE DATA (DIA) (SE SEU ERRO ERA AQUI)
    //---------------------------------------------------------
    cout << "\n*** TESTANDO DOMÍNIO DATA (DIA) ***" << endl;
    testarValidadorDia(InterfaceDeTeste::DEVE_DAR_CERTO, &data, 15);
    testarValidadorDia(InterfaceDeTeste::DEVE_DAR_ERRADO, &data, 32); // Dia inválido

    // ... CONTINUE ADICIONANDO MAIS CHAMADAS PARA COBRIR TODOS OS SEUS VALIDADORES ...

    // Exemplo de chamada para Hospede:
    testarValidadorCartao(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede, "1111111111111111");
    testarValidadorEndereco(InterfaceDeTeste::DEVE_DAR_CERTO, &hospede, "SQS 100 Bloco A");

    // Exemplo de chamada para Hotel:
    testarValidadorTelefone(InterfaceDeTeste::DEVE_DAR_CERTO, &hotel, "61987654321");

    // Exemplo de chamada para Quarto:
    testarValidadorDinheiro(InterfaceDeTeste::DEVE_DAR_CERTO, &quarto, 15000); // 150,00

    // Exemplo de chamada para Reserva:
    testarValidadorChegada(InterfaceDeTeste::DEVE_DAR_CERTO, &reserva, "15/01/2026");

    cout << "\n=======================================================" << endl;
    cout << "           FIM DO TESTE DE FUMAÇA                        " << endl;
    cout << "=======================================================" << endl;
}

//-----------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------

void SmokeTest::testarValidadorString(int esperando_resultado, string s1, string s2) {
    InterfaceDeTeste::apresentacaoTeste(s1);
    int resultado_teste = 0;
    string erro_capturado = "Erro: Strings sao diferentes";

    if (s1 == s2) {
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } else {
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro_capturado);
    }

    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("String (Util)", s1, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

//-----------------------------------------------------------------------------------------------------------
// Padrão de Registro de Falha (Nome, Email, Ramal, Senha, Cartao, Endereco, Telefone, Codigo)
// Apliquei a mesma lógica de captura e registro a partir daqui.

void SmokeTest::testarValidadorNome(int esperando_resultado, Pessoa *ptr, string nome) {
    InterfaceDeTeste::apresentacaoTeste(nome);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";

    try {
        Nome nomeObj(nome);
        ptr->setPessoaNome(Nome(nomeObj));
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Nome (Pessoa)", nome, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

void SmokeTest::testarValidadorEmail(int esperando_resultado, Pessoa *ptr, string email) {
    InterfaceDeTeste::apresentacaoTeste(email);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Email emailObj(email);
        ptr->setPessoaEmail(Email(emailObj));
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Email (Pessoa)", email, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

//-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorNome(int esperando_resultado, Gerente *ptr, string nome) {
    InterfaceDeTeste::apresentacaoTeste(nome);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Nome nomeObj(nome);
        ptr->setNome(Nome(nomeObj));
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Nome (Gerente)", nome, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

void SmokeTest::testarValidadorEmail(int esperando_resultado, Gerente *ptr, string email) {
    InterfaceDeTeste::apresentacaoTeste(email);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Email emailObj(email);
        ptr->setEmail(Email(emailObj));
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Email (Gerente)", email, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

void SmokeTest::testarValidadorRamal(int esperando_resultado, Gerente *ptr, string ramal) {
    InterfaceDeTeste::apresentacaoTeste(ramal);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Ramal ramalObj(ramal);
        ptr->setRamal(ramalObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Ramal (Gerente)", ramal, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

void SmokeTest::testarValidadorSenha(int esperando_resultado, Gerente *ptr, string senha) {
    InterfaceDeTeste::apresentacaoTeste(senha);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Senha senhaObj(senha);
        ptr->setSenha(senhaObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Senha (Gerente)", senha, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

//-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorNome(int esperando_resultado, Hospede *ptr, string nome) {
    InterfaceDeTeste::apresentacaoTeste(nome);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Nome nomeObj(nome);
        ptr->setNome(Nome(nomeObj));
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Nome (Hospede)", nome, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

void SmokeTest::testarValidadorEmail(int esperando_resultado, Hospede *ptr, string email) {
    InterfaceDeTeste::apresentacaoTeste(email);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Email emailObj(email);
        ptr->setEmail(Email(emailObj));
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Email (Hospede)", email, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

void SmokeTest::testarValidadorCartao(int esperando_resultado, Hospede *ptr, string cartao) {
    InterfaceDeTeste::apresentacaoTeste(cartao);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Cartao cartaoObj(cartao);
        ptr->setCartao(cartaoObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Cartao (Hospede)", cartao, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

void SmokeTest::testarValidadorEndereco(int esperando_resultado, Hospede *ptr, string endereco) {
    InterfaceDeTeste::apresentacaoTeste(endereco);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Endereco enderecoObj(endereco);
        ptr->setEndereco(enderecoObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Endereco (Hospede)", endereco, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

//-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorNome(int esperando_resultado, Hotel *ptr, string nome) {
    InterfaceDeTeste::apresentacaoTeste(nome);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Nome nomeObj(nome);
        ptr->setNome(nomeObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Nome (Hotel)", nome, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

void SmokeTest::testarValidadorEndereco(int esperando_resultado, Hotel *ptr, string endereco) {
    InterfaceDeTeste::apresentacaoTeste(endereco);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Endereco enderecoObj(endereco);
        ptr->setEndereco(enderecoObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Endereco (Hotel)", endereco, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

void SmokeTest::testarValidadorTelefone(int esperando_resultado, Hotel *ptr, string telefone) {
    InterfaceDeTeste::apresentacaoTeste(telefone);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Telefone telefoneObj(telefone);
        ptr->setTelefone(telefoneObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Telefone (Hotel)", telefone, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

void SmokeTest::testarValidadorCodigo(int esperando_resultado, Hotel *ptr, string codigo) {
    InterfaceDeTeste::apresentacaoTeste(codigo);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Codigo codigoObj(codigo);
        ptr->setCodigo(codigoObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Codigo (Hotel)", codigo, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

//-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorNumero(int esperando_resultado, Quarto *ptr, string numero) {
    InterfaceDeTeste::apresentacaoTeste(numero);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Numero numeroObj(numero);
        ptr->setNumero(numeroObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Numero (Quarto)", numero, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

void SmokeTest::testarValidadorCapacidade(int esperando_resultado, Quarto *ptr, int capacidade) {
    InterfaceDeTeste::apresentacaoTeste(capacidade);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Capacidade capacidadeObj(capacidade);
        ptr->setCapacidade(capacidadeObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Capacidade (Quarto)", to_string(capacidade), erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

void SmokeTest::testarValidadorDinheiro(int esperando_resultado, Quarto *ptr, int diaria) {
    InterfaceDeTeste::apresentacaoTeste(diaria);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Dinheiro diariaObj(diaria);
        ptr->setDiaria(diariaObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Diaria (Quarto)", to_string(diaria), erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

void SmokeTest::testarValidadorRamal(int esperando_resultado, Quarto *ptr, string ramal) {
    InterfaceDeTeste::apresentacaoTeste(ramal);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Ramal ramalObj(ramal);
        ptr->setRamal(ramalObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Ramal (Quarto)", ramal, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}
//-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorChegada(int esperando_resultado, Reserva *ptr, string chegada) {
    InterfaceDeTeste::apresentacaoTeste(chegada);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Data chegadaObj(chegada);
        ptr->setChegada(chegadaObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Data Chegada (Reserva)", chegada, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

void SmokeTest::testarValidadorPartida(int esperando_resultado, Reserva *ptr, string partida) {
    InterfaceDeTeste::apresentacaoTeste(partida);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Data partidaObj(partida);
        ptr->setPartida(partidaObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Data Partida (Reserva)", partida, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

void SmokeTest::testarValidadorDinheiro(int esperando_resultado, Reserva *ptr, int dinheiro) {
    InterfaceDeTeste::apresentacaoTeste(dinheiro);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Dinheiro dinheiroObj(dinheiro);
        ptr->setDinheiro(dinheiroObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Dinheiro (Reserva)", to_string(dinheiro), erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

void SmokeTest::testarValidadorCodigo(int esperando_resultado, Reserva *ptr, string codigo) {
    InterfaceDeTeste::apresentacaoTeste(codigo);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        Codigo codigoObj(codigo);
        ptr->setCodigo(codigoObj);
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Codigo (Reserva)", codigo, erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

//-----------------------------------------------------------------------------------------------------------
void SmokeTest::testarValidadorDia(int esperando_resultado, Data *ptr, int dia) {
    InterfaceDeTeste::apresentacaoTeste(dia);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        ptr->setData(dia, Data::JAN, 2000); //(valor, padrao , padrao)
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Dia (Data)", to_string(dia), erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

void SmokeTest::testarValidadorMes(int esperando_resultado, Data *ptr, int mes) {
    InterfaceDeTeste::apresentacaoTeste(mes);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        ptr->setData(1, mes, 2000); //(padrao,valor, padrao)
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Mes (Data)", to_string(mes), erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

void SmokeTest::testarValidadorAno(int esperando_resultado, Data *ptr, int ano) {
    InterfaceDeTeste::apresentacaoTeste(ano);
    int resultado_teste = 0;
    string erro_capturado = "Sucesso esperado, mas falhou";
    try {
        ptr->setData(1, Data::JAN, ano); //(padrao, padrao , valor)
        resultado_teste = InterfaceDeTeste::apresentacaoSucesso();
    } catch (invalid_argument &erro) {
        erro_capturado = erro.what();
        resultado_teste = InterfaceDeTeste::apresentacaoErro(erro);
    }
    InterfaceDeTeste::checaResultado(esperando_resultado, resultado_teste);

    bool sucesso = (esperando_resultado == resultado_teste);
    if (!sucesso) {
        InterfaceDeTeste::registrarFalha("Ano (Data)", to_string(ano), erro_capturado);
        InterfaceDeTeste::setTestesProblema(InterfaceDeTeste::getTestesProblema() + 1);
    }
}

//-----------------------------------------------------------------------------------------------------------