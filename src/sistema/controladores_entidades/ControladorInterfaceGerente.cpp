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
            exibirMenuCRUD();
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
void ControladorInterfaceGerente::exibirMenuCRUD() {
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
                PersistenciaGerente persistencia;
                bool sucesso = persistencia.inserir(*gerente);

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
    vector<GerenteDTO *> lista = persistencia.listar();

    if (lista.empty()) {
        cout << "Nenhum gerente cadastrado.\n";
        return;
    }
    Tabela tab;

    for (GerenteDTO *item: lista) {
        Linha *objLinha = tab.criarObj();

        objLinha->atributo("id", item->getId());
        objLinha->atributo("Nome", item->getNome());
        objLinha->atributo("Email", item->getEmail());
        objLinha->atributo("Ramal", item->getRamal());
    }

    tab.exibirTabela("Lista De Gerentes");
}

//-----------------------------------------------------------------------------------------------------------
void ControladorInterfaceGerente::atualizar() {
    ConsoleIO::PrintMensagem("Informe o Id do Gerente: ");
    string id_gerente = ConsoleIO::LerLinha();

    if (ValidadorNumerico::verificaSeENumero(id_gerente)) {

        PersistenciaGerente persistencia;
        bool alterado = false;

        int id_numero = stoi(id_gerente);
        optional<GerenteDTO> existe_gerente = persistencia.buscaGerentePorID(id_numero);

        Tabela tab;
        vector<GerenteDTO> lista;
        lista.push_back(*existe_gerente);

        for (GerenteDTO item: lista) {
            Linha *objLinha = tab.criarObj();

            objLinha->atributo("Id", item.getId());
            objLinha->atributo("Nome", item.getNome());
            objLinha->atributo("Email", item.getEmail());
            objLinha->atributo("Ramal", item.getRamal());
        }

        tab.exibirTabela("Gerente");

        // Perguntas para o usuario
        Gerente gerente(*existe_gerente); // Construtor em Gerente para GerenteDTO

        Menu menu;

        const int OPCAO_ALTERAR_NOME = menu.adcionarItens("Alterar Nome");
        const int OPCAO_ALTERAR_EMAIL = menu.adcionarItens("Alterar Email");
        const int OPCAO_ALTERAR_RAMAL = menu.adcionarItens("Alterar Ramal");
        const int OPCAO_ALTERAR_SENHA = menu.adcionarItens("Alterar Senha");
        const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");

        int opcao = menu.executa("Atualizacao de Cadastro");

        if (opcao == OPCAO_ALTERAR_NOME) {
            ConsoleIO::PrintMensagem("Novo nome:");
            string valor = ConsoleIO::LerLinha();
            try {
                gerente.setNome(Nome(valor));
                alterado = true;
            } catch (invalid_argument &erro) {
                cout << erro.what() << endl;
            }
        } else if (opcao == OPCAO_ALTERAR_EMAIL) {
            ConsoleIO::PrintMensagem("Novo Email:");
            string valor = ConsoleIO::LerLinha();
            try {
                gerente.setEmail(Email(valor));
                alterado = true;
            } catch (invalid_argument &erro) {
                cout << erro.what() << endl;
            }
        } else if (opcao == OPCAO_ALTERAR_RAMAL) {
            ConsoleIO::PrintMensagem("Novo ramal:");
            string valor = ConsoleIO::LerLinha();
            try {
                gerente.setRamal(Ramal(valor));
                alterado = true;
            } catch (invalid_argument &erro) {
                cout << erro.what() << endl;
            }
        }else if (opcao == OPCAO_ALTERAR_SENHA) {
            ConsoleIO::PrintMensagem("Nova senha:");
            string valor = ConsoleIO::LerLinha();
            try {
                gerente.setSenha(Senha(valor));
                alterado = true;
            } catch (invalid_argument &erro) {
                cout << erro.what() << endl;
            }
        } else if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
            ConsoleIO::PrintMensagem("Atualizacao cancelada.");
            return;
        } else {
            ConsoleIO::PrintMensagem("Opcao invalida.");
            return;
        }

        if (alterado) {
            bool sucesso = persistencia.atualizar(id_numero, gerente);
            if (sucesso)
                ConsoleIO::PrintMensagem("Cadastro atualizado com sucesso!");
            else
                ConsoleIO::PrintMensagem("Erro ao atualizar cadastro no banco.");
        }
    }else {
        ConsoleIO::PrintMensagem("Erro: Id Invalido");
    }
}

//-----------------------------------------------------------------------------------------------------------
bool ControladorInterfaceGerente::remover() {
    /*
    cout << "Informe o Email: \n";
    string emailStr = ConsoleIO::LerLinha();
    bool status = persistencia.excluirPorEmail(gerenteLogado);

    if (status == true) {
        cout << "Foi excluido com sucesso!\n";
    } else {
        cout << "Gerente nao encontrado!\n";
    }
    return status;
    */
}
//-----------------------------------------------------------------------------------------------------------
