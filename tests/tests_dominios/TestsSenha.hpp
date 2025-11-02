#ifndef TESTSSENHA_H
#define TESTSSENHA_H

#include "InterfaceDeTeste.hpp"
#include "Senha.hpp"
#include <vector>
#include <string>

class TestsSenha : public InterfaceDeTeste {
public:
    void executar() override;

    std::string nomeDoTeste() const override { return "TestsSenha"; }

private:
    void testarSenhasValidas();

    void testarSenhasMuitoCurtas();

    void testarSenhasSemMaiuscula();

    void testarSenhasSemMinuscula();

    void testarSenhasSemDigito();

    void testarSenhasSemEspecial();

    void testarSenhasComSequenciaDeLetras();

    void testarSenhasComSequenciaDeDigitos();
};

#endif // TESTSSENHA_H
