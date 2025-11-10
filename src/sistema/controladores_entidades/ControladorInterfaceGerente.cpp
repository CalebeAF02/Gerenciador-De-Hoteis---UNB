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
            ConsoleIO::PrintMenssagem("Voce Saiu da Central de servicos e foi deslogado!");
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
            ConsoleIO::PrintMenssagem("Opcao Invalida!");
        }
    };
}

//-----------------------------------------------------------------------------------------------------------
void ControladorInterfaceGerente::exibirMenuCRUD() {
    this->executando = true;

    while (this->getEstaLogado()) {
        FabricaGerenciavel<ControladorInterfaceGerente> fabrica;
        fabrica.executarMenu(executando);
        if (executando == false) {
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

            ConsoleIO::SubPergunta("Informe o Nome: ");
            string nomeStr = ConsoleIO::LerLinha();
            try {
                gerente->setNome(Nome(nomeStr));
            } catch (invalid_argument &erro) {
                cout << erro.what() << endl;
                tudoOK = false;
            }
            if (tudoOK) {
                ConsoleIO::SubPergunta("Informe o Email: ");
                string emailStr = ConsoleIO::LerLinha();
                try {
                    gerente->setEmail(Email(emailStr));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                ConsoleIO::SubPergunta("Informe o Ramal: ");
                string ramalStr = ConsoleIO::LerLinha();
                try {
                    gerente->setRamal(Ramal(ramalStr));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                ConsoleIO::SubPergunta("Informe o Senha: ");
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
                    ConsoleIO::PrintMenssagem("Gerente Cadastrado!");
                } else {
                    ConsoleIO::PrintMenssagem("Erro ao cadastrar gerente no banco!");
                    break; // ← Aqui você interrompe o loop e volta ao menu anterior
                }
            } else {
                ConsoleIO::PrintMenssagem("Err: Gerente não cadastrado!");
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
        ConsoleIO::PrintMenssagem("Nenhum gerente cadastrado.");
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
    ConsoleIO::SubPergunta("Informe o Id do Gerente: ");
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
            ConsoleIO::SubPergunta("Novo nome: ");
            string valor = ConsoleIO::LerLinha();
            try {
                gerente.setNome(Nome(valor));
                alterado = true;
            } catch (invalid_argument &erro) {
                cout << erro.what() << endl;
            }
        } else if (opcao == OPCAO_ALTERAR_EMAIL) {
            ConsoleIO::SubPergunta("Novo Email: ");
            string valor = ConsoleIO::LerLinha();
            try {
                gerente.setEmail(Email(valor));
                alterado = true;
            } catch (invalid_argument &erro) {
                cout << erro.what() << endl;
            }
        } else if (opcao == OPCAO_ALTERAR_RAMAL) {
            ConsoleIO::SubPergunta("Novo ramal: ");
            string valor = ConsoleIO::LerLinha();
            try {
                gerente.setRamal(Ramal(valor));
                alterado = true;
            } catch (invalid_argument &erro) {
                cout << erro.what() << endl;
            }
        } else if (opcao == OPCAO_ALTERAR_SENHA) {
            ConsoleIO::SubPergunta("Nova senha: ");
            string valor = ConsoleIO::LerLinha();
            try {
                gerente.setSenha(Senha(valor));
                alterado = true;
            } catch (invalid_argument &erro) {
                cout << erro.what() << endl;
            }
        } else if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
            ConsoleIO::PrintMenssagem("Atualizacao cancelada.");
            return;
        } else {
            ConsoleIO::PrintMenssagem("Opcao invalida.");
            return;
        }

        if (alterado) {
            bool sucesso = persistencia.atualizar(id_numero, gerente);
            if (sucesso)
                ConsoleIO::PrintMenssagem("Cadastro atualizado com sucesso!");
            else
                ConsoleIO::PrintMenssagem("Erro ao atualizar cadastro no banco.");
        }
    } else {
        ConsoleIO::PrintMenssagem("Erro: Id Invalido");
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