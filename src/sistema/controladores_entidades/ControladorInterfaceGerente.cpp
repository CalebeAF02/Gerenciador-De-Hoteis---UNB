//
// Created by caleb on 01/11/2025.
//

#include "../../../include/sistema/controladores_entidades/ControladorInterfaceGerente.h"

#include "ControladorInterfaceGerente.h"

void ControladorInterfaceGerente::exibirMenu() {
    Menu menu;

    const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
    const int OPCAO_GERENCIE_GERENTES = menu.adcionarItens("Gerencie Gerentes");
    const int OPCAO_GERENCIE_HOSPEDES = menu.adcionarItens("Gerencie Hospedes");
    const int OPCAO_GERENCIE_HOTEIS = menu.adcionarItens("Gerencie Hoteis");
    const int OPCAO_GERENCIE_QUARTOS = menu.adcionarItens("Gerencie Quartos");
    const int OPCAO_GERENCIE_RESERVAS = menu.adcionarItens("Gerencie Reservas");
    const int OPCAO_AVALIAR_SOLICITACOES = menu.adcionarItens("Avaliar Solicitacoes de Hospedagem");

    while (this->getEstaLogado()) {
        int opcao = menu.executa("Seja bem vindo a central de servicos");

        if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
            this->sair();
            cout << "Voce Saiu da Central de servicos e foi deslogado!\n";
        } else if (opcao == OPCAO_GERENCIE_GERENTES) {
            exibirMenuCRUDGerentes();
        } else if (opcao == OPCAO_GERENCIE_HOSPEDES) {
            ControladorInterfaceHospede servicosHospede;
            servicosHospede.exibirMenuCRUD();
        } else if (opcao == OPCAO_GERENCIE_HOTEIS) {
            ControladorInterfaceHotel servicosHotel;
            servicosHotel.exibirMenuCRUD();
        } else if (opcao == OPCAO_GERENCIE_QUARTOS) {
            ControladorInterfaceQuarto servicosQuarto;
            servicosQuarto.exibirMenuCRUD();
        } else if (opcao == OPCAO_GERENCIE_RESERVAS) {
            ControladorInterfaceReserva servicosReserva;
            servicosReserva.exibirMenuCRUD();
        } else if (opcao == OPCAO_AVALIAR_SOLICITACOES) {
            ControladorInterfaceHospede servicosHospede;
            servicosHospede.avaliarSolicitacoes();
        } else {
            cout << "Opcao Invalida!" << endl;
        }
    };
}

void ControladorInterfaceGerente::exibirMenuCRUDGerentes() {
    bool status = true;
    while (this->getEstaLogado()) {
        FabricaGerenciavel<ControladorInterfaceGerente> fabrica;
        fabrica.executarMenu(status);
        if (status == false) {
            break;
        }
    };
}


void ControladorInterfaceGerente::criar() {
    bool criado = false;
    bool tudoOK = true;

    while (!criado) // Enquanto craido esta falso , ele repete
    {
        Gerente *gerente = new Gerente();

        if (gerente) {
            //Preencher atribultos com validacao
            if (tudoOK == false) {
                cout << "\nRetornando...\n\n";
                break;
            }

            TextoApresentacao::MostrarTituloEmCaixa("Criando Novo Gerente");

            cout << "Informe o Nome: \n";
            string nomeStr = TextoApresentacao::LerLinha();
            try {
                gerente->setNome(Nome(nomeStr));
            } catch (invalid_argument &erro) {
                cout << erro.what() << endl;
                tudoOK = false;
            }
            if (tudoOK) {
                cout << "Informe o Email: \n";
                string emailStr = TextoApresentacao::LerLinha();
                try {
                    gerente->setEmail(Email(emailStr));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                cout << "Informe o Ramal: \n";
                string ramalStr = TextoApresentacao::LerLinha();
                try {
                    gerente->setRamal(Ramal(ramalStr));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                cout << "Informe o Senha: \n";
                string senhaStr = TextoApresentacao::LerLinha();
                try {
                    gerente->setSenha(Senha(senhaStr));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                PersistenciaGerente dao;
                bool sucesso = dao.adicionarAoBD(*gerente);

                if (sucesso) {
                    criado = true;
                    cout << "Gerente Cadastrado!\n";
                    // coloca os Gerentes da listaGerentes que esta na memoria para o arquivo Dados_Gerentes.tsv .
                } else {
                    cout << "Erro ao cadastrar gerente no banco!\n";
                    cout << "Retornando ao menu de acesso...\n";
                    break; // ← Aqui você interrompe o loop e volta ao menu anterior
                }
            } else {
                cout << "Ops* Gerente não cadastrado!\n";
                cout << "Retornando ao menu de acesso...\n";
                break; // ← Também retorna se houver erro de validação
            }
            delete gerente; // Liberar o ponteiro da memoria.
        }
    }
};

void ControladorInterfaceGerente::ler() {
    vector<Gerente *> listaGerentes = dao.listarBD();

    if (listaGerentes.empty()) {
        cout << "Nenhum gerente cadastrado.\n";
        return;
    }

    TextoApresentacao::MostrarTituloEmCaixa("Lista de Gerentes");

    for (const auto &g: listaGerentes) {
        cout << "Nome: " << g->getNome() << endl;
        cout << "Email: " << g->getEmail() << endl;
        cout << "Ramal: " << g->getRamal() << endl;
        cout << "-----------------------------\n";
    }
}

void ControladorInterfaceGerente::atualizar() {
    if (gerenteLogado == nullptr) {
        TextoApresentacao::MostrarTituloEmCaixa("Atualizacao de Cadastro");
        std::cout << "\nVoce precisa estar logado para atualizar seu cadastro.\n\n";
        return;
    }

    PersistenciaGerente dao;
    bool alterado = false;

    TextoApresentacao::MostrarTituloEmCaixa("Atualizacao de Cadastro");
    TextoApresentacao::MostrarOpcaoEmCaixa("Alterar Nome", 1);
    TextoApresentacao::MostrarOpcaoEmCaixa("Alterar Ramal", 2);
    TextoApresentacao::MostrarOpcaoEmCaixa("Alterar Senha", 3);
    TextoApresentacao::MostrarOpcaoEmCaixa("Cancelar", 0);

    std::string opcaoStr = TextoApresentacao::RecebeOpcao();
    int opcao = std::stoi(opcaoStr);

    switch (opcao) {
        case 1: {
            TextoApresentacao::MostrarTituloPergunta("Novo nome:");
            std::string novoNome = TextoApresentacao::LerLinha();
            try {
                gerenteLogado->setNome(Nome(novoNome));
                alterado = true;
            } catch (std::invalid_argument &erro) {
                std::cout << erro.what() << std::endl;
            }
            break;
        }
        case 2: {
            TextoApresentacao::MostrarTituloPergunta("Novo ramal:");
            std::string novoRamal = TextoApresentacao::LerLinha();
            try {
                gerenteLogado->setRamal(Ramal(novoRamal));
                alterado = true;
            } catch (std::invalid_argument &erro) {
                std::cout << erro.what() << std::endl;
            }
            break;
        }
        case 3: {
            TextoApresentacao::MostrarTituloPergunta("Nova senha:");
            std::string novaSenha = TextoApresentacao::LerLinha();
            try {
                gerenteLogado->setSenha(Senha(novaSenha));
                alterado = true;
            } catch (std::invalid_argument &erro) {
                std::cout << erro.what() << std::endl;
            }
            break;
        }
        case 0:
            std::cout << "Atualizacao cancelada.\n";
            return;
        default:
            std::cout << "Opcao invalida.\n";
            return;
    }

    if (alterado) {
        bool sucesso = dao.atualizarGerenteNoBD(*gerenteLogado);
        if (sucesso)
            TextoApresentacao::MostrarTituloRetorno("Cadastro atualizado com sucesso!");
        else
            TextoApresentacao::MostrarTituloRetorno("Erro ao atualizar cadastro no banco.");
    }
}

bool ControladorInterfaceGerente::remover() {
    cout << "Informe o Email: \n";
    string emailStr = TextoApresentacao::LerLinha();
    bool status = dao.excluirPorEmailDoBD(gerenteLogado);

    if (status == true) {
        cout << "Foi excluido com sucesso!\n";
    } else {
        cout << "Gerente nao encontrado!\n";
    }
    return status;
}
