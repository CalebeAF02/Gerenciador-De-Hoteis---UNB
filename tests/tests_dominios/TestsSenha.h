//
// Created by caleb on 25/10/2025.
//

#ifndef ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSSENHA_H
#define ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSSENHA_H

#include "TestsBase.h"
#include "Senha.h"
#include <vector>
#include <string>

class TestsSenha : public TestsBase
{
public:
    void executar() override;
    std::string nome() const override { return "TestsSenha"; }

private:
    void testarSenhasValidas();
    void testarSenhasMuitoCurtas();
    void testarSenhasSemMaiuscula();
    void testarSenhasSemMinuscula();
    void testarSenhasSemDigito();
    void testarSenhasSemEspecial();
    void testarSenhasComInicioInvalido();
};

#endif //ANTIGO_PROJETO_HOTEL_CLION_MAIN_IML_TESTSSENHA_H