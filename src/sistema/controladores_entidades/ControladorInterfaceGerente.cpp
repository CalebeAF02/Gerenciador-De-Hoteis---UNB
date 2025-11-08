//
// Created by caleb on 01/11/2025.
//

#include "../../../include/sistema/controladores_entidades/ControladorInterfaceGerente.hpp"

#include "ControladorInterfaceGerente.hpp"
//-----------------------------------------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------------------------------------
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

            ConsoleFormatter::MostrarTituloEmCaixa("Criando Novo Gerente");

            cout << "Informe o Nome: \n";
            string nomeStr = ConsoleIO::LerLinha();
            try {
                gerente->setNome(Nome(nomeStr));
            } catch (invalid_argument &erro) {
                cout << erro.what() << endl;
                tudoOK = false;
            }
            if (tudoOK) {
                cout << "Informe o Email: \n";
                string emailStr = ConsoleIO::LerLinha();
                try {
                    gerente->setEmail(Email(emailStr));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                cout << "Informe o Ramal: \n";
                string ramalStr = ConsoleIO::LerLinha();
                try {
                    gerente->setRamal(Ramal(ramalStr));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                cout << "Informe o Senha: \n";
                string senhaStr = ConsoleIO::LerLinha();
                try {
                    gerente->setSenha(Senha(senhaStr));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                PersistenciaGerente dao;
                bool sucesso = dao.inserirAoBD(*gerente);

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
//-----------------------------------------------------------------------------------------------------------
void ControladorInterfaceGerente::ler() {
    vector<Gerente *> listaGerentes = dao.listarBD();

    if (listaGerentes.empty()) {
        cout << "Nenhum gerente cadastrado.\n";
        return;
    }

    // 1. CABEÇALHOS
    vector<string> titulosTabela = {"Nome", "Email", "Ramal"};

    // 2. DADOS (Iterar sobre listaGerentes e extrair)
    vector<vector<string> > dadosTabela;
    for (const Gerente *const &g: listaGerentes) {
        dadosTabela.push_back({
            g->getNome(),
            g->getEmail(),
            g->getRamal()
        });
    }

    // 3. CHAMADA GENÉRICA
    ConsoleFormatter::MostrarTabelaGenerica("Lista de Gerentes", titulosTabela, dadosTabela);
}
//-----------------------------------------------------------------------------------------------------------
void ControladorInterfaceGerente::atualizar() {
    if (gerenteLogado == nullptr) {
        ConsoleFormatter::MostrarTituloEmCaixa("Atualizacao de Cadastro");
        cout << "\nVoce precisa estar logado para atualizar seu cadastro.\n\n";
        return;
    }

    PersistenciaGerente dao;
    bool alterado = false;

    ConsoleFormatter::MostrarTituloEmCaixa("Atualizacao de Cadastro");
    ConsoleFormatter::MostrarOpcaoEmCaixa("Alterar Nome", 1);
    ConsoleFormatter::MostrarOpcaoEmCaixa("Alterar Ramal", 2);
    ConsoleFormatter::MostrarOpcaoEmCaixa("Alterar Senha", 3);
    ConsoleFormatter::MostrarOpcaoEmCaixa("Cancelar", 0);

    string opcaoStr = ConsoleIO::ReceberOpcao();
    int opcao = stoi(opcaoStr);

    switch (opcao) {
        case 1: {
            ConsoleIO::PrintMensagem("Novo nome:");
            string novoNome = ConsoleIO::LerLinha();
            try {
                gerenteLogado->setNome(Nome(novoNome));
                alterado = true;
            } catch (invalid_argument &erro) {
                cout << erro.what() << endl;
            }
            break;
        }
        case 2: {
            ConsoleIO::PrintMensagem("Novo ramal:");
            string novoRamal = ConsoleIO::LerLinha();
            try {
                gerenteLogado->setRamal(Ramal(novoRamal));
                alterado = true;
            } catch (invalid_argument &erro) {
                cout << erro.what() << endl;
            }
            break;
        }
        case 3: {
            ConsoleIO::PrintMensagem("Nova senha:");
            string novaSenha = ConsoleIO::LerLinha();
            try {
                gerenteLogado->setSenha(Senha(novaSenha));
                alterado = true;
            } catch (invalid_argument &erro) {
                cout << erro.what() << endl;
            }
            break;
        }
        case 0:
            cout << "Atualizacao cancelada.\n";
            return;
        default:
            cout << "Opcao invalida.\n";
            return;
    }

    if (alterado) {
        bool sucesso = dao.atualizarGerenteNoBD(*gerenteLogado);
        if (sucesso)
            ConsoleIO::PrintMensagem("Cadastro atualizado com sucesso!");
        else
            ConsoleIO::PrintMensagem("Erro ao atualizar cadastro no banco.");
    }
}
//-----------------------------------------------------------------------------------------------------------
bool ControladorInterfaceGerente::remover() {
    cout << "Informe o Email: \n";
    string emailStr = ConsoleIO::LerLinha();
    bool status = dao.excluirPorEmailDoBD(gerenteLogado);

    if (status == true) {
        cout << "Foi excluido com sucesso!\n";
    } else {
        cout << "Gerente nao encontrado!\n";
    }
    return status;
}
//-----------------------------------------------------------------------------------------------------------