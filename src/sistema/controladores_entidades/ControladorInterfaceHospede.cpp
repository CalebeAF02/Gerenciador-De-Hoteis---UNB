//
// Created by caleb on 10/10/2025.
//

#include "ControladorInterfaceHospede.hpp"

#include "FabricaGerenciavel.hpp"
#include "Menu.hpp"
#include "PersistenciaHospede.hpp"
#include "sqlite3.h"

void ControladorInterfaceHospede::exibirMenu() {
    Menu menu;

    const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
    const int OPCAO_HOSPEDAGENS = menu.adcionarItens("Opcoes de Hospedagem");
    const int OPCAO_CRIAR_SOLOCITACAO_DE_HOSPEDAGEM = menu.adcionarItens("Criar Solicitacao de Hospedagem");
    const int OPCAO_STATUS_DA_SOLICITACAO_DE_HOSPEDAGEM = menu.adcionarItens("Status da Solicitacao de Hospedagem");

    while (executando == true) {
        int opcao = menu.executa("Faca o acesso para liberar os servicos");

        if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
            executando = false;
            cout << "Voltando a selecao de usuario!" << endl;
        } else if (opcao == OPCAO_HOSPEDAGENS) {
            opcoesDeHospedagem();
        } else if (opcao == OPCAO_CRIAR_SOLOCITACAO_DE_HOSPEDAGEM) {
            solicitandoHospedagem();
        } else if (opcao == OPCAO_STATUS_DA_SOLICITACAO_DE_HOSPEDAGEM) {
            statusDaSolicitandoHospedagem();
        } else {
            cout << "Opcao Invalida!" << endl;
        }
    }
};

void ControladorInterfaceHospede::exibirMenuCRUD() {
    bool status = true;
    while (status) {
        ConsoleFormatter::MostrarTituloEmCaixa("CRUD Gerente");
        FabricaGerenciavel<ControladorInterfaceHospede> fabrica;
        fabrica.executarMenu(status);
    };
}

void ControladorInterfaceHospede::opcoesDeHospedagem() {
    ConsoleFormatter::MostrarTituloEmCaixa("Opcoes de Hospedagem");
    ConsoleIO::PrintMensagem("\nEsta opcao ainda nao foi construida!\nRetornando...\n");
    return;
}

void ControladorInterfaceHospede::solicitandoHospedagem() {
    ConsoleFormatter::MostrarTituloEmCaixa("Criar Solicitacao de Hospedagem");

    ConsoleIO::PrintMensagem("Informe o Email");
    string email = ConsoleIO::LerLinha();

    ConsoleIO::PrintMensagem("Codigo do hotel desejado:");
    string idHotel = ConsoleIO::LerLinha();

    ConsoleIO::PrintMensagem("Codigo do quarto desejado:");
    string idQuarto = ConsoleIO::LerLinha();

    ConsoleIO::PrintMensagem("Data de chegada (dd/mm/aaaa):");
    string chegadaStr = ConsoleIO::LerLinha();

    ConsoleIO::PrintMensagem("Data de partida (dd/mm/aaaa):");
    string partidaStr = ConsoleIO::LerLinha();

    cout << idHotel.length() << " e " << idQuarto.length();
    try {
        Data chegada(chegadaStr);
        Data partida(partidaStr);

        SolicitacaoHospedagem solicitacao(
            email,
            idHotel,
            idQuarto,
            chegada,
            partida,
            StatusSolicitacaoHospedagem::PENDENTE,
            ""

        );

        PersistenciaSolicitacaoHospedagem::salvar(solicitacao);
        ConsoleIO::PrintMensagem("Solicitacao registrada com sucesso!");
    } catch (exception &e) {
        ConsoleIO::PrintMensagem("Erro ao criar solicitacao: " + string(e.what()));
    }
}

void ControladorInterfaceHospede::statusDaSolicitandoHospedagem() const {
    ConsoleFormatter::MostrarTituloEmCaixa("Status da Solicitacao de Hospedagem");

    ConsoleIO::PrintMensagem("Informe o Email");
    string email = ConsoleIO::LerLinha();

    const vector<SolicitacaoHospedagem> lista = PersistenciaSolicitacaoHospedagem::buscarPorEmail(email);

    if (lista.empty()) {
        ConsoleIO::PrintMensagem("Nenhuma solicitacao encontrada.");
        return;
    }

    for (const SolicitacaoHospedagem &s: lista) {
        string statusStr = (s.getStatus() == StatusSolicitacaoHospedagem::PENDENTE)
                               ? "Pendente"
                               : (s.getStatus() == StatusSolicitacaoHospedagem::APROVADO)
                                     ? "Aprovada"
                                     : "Recusada";

        cout << "----------------------------------------\n";
        cout << "Hotel: " << s.getHotelId() << "\n";
        cout << "Quarto: " << s.getQuartoId() << "\n";
        cout << "Chegada: " << s.getChegada().toString() << "\n";
        cout << "Partida: " << s.getPartida().toString() << "\n";
        cout << "Status: " << statusStr;

        if (s.getStatus() == StatusSolicitacaoHospedagem::RECUSADO)
            cout << "\n | Motivo: " << s.getMotivoRecusa();

        cout << "\n----------------------------------------\n";
    }
}

void ControladorInterfaceHospede::avaliarSolicitacoes() {
    ConsoleFormatter::MostrarTituloEmCaixa("Avaliar Solicitacoes de Hospedagem");

    auto pendentes = PersistenciaSolicitacaoHospedagem::buscarPorStatus(0); // status = pendente

    if (pendentes.empty()) {
        ConsoleIO::PrintMensagem("Nenhuma solicitacao pendente.");
        return;
    }

    for (auto &solicitacao: pendentes) {
        cout << "\nHospede: " << solicitacao.getHospedeId()
                << "\nHotel: " << solicitacao.getHotelId()
                << "\nQuarto: " << solicitacao.getQuartoId()
                << "\nChegada: " << solicitacao.getChegada().toString()
                << "\nPartida: " << solicitacao.getPartida().toString()
                << "\nStatus atual: Pendente\n";

        ConsoleIO::PrintMensagem("Deseja aprovar (A) ou recusar (R) esta solicitacao?");
        string escolha = ConsoleIO::ReceberOpcao();

        if (escolha == "A" || escolha == "a") {
            solicitacao.setStatus(StatusSolicitacaoHospedagem::APROVADO); // aprovada
            solicitacao.setMotivoRecusa(""); // limpa motivo
            PersistenciaSolicitacaoHospedagem::atualizar(solicitacao);
            ConsoleIO::PrintMensagem("Solicitacao aprovada com sucesso.");
        } else if (escolha == "R" || escolha == "r") {
            ConsoleIO::PrintMensagem("Informe o motivo da recusa:");
            string motivo = ConsoleIO::LerLinha();
            solicitacao.setStatus(StatusSolicitacaoHospedagem::RECUSADO); // recusada
            solicitacao.setMotivoRecusa(motivo);
            PersistenciaSolicitacaoHospedagem::atualizar(solicitacao);
            ConsoleIO::PrintMensagem("Solicitacao recusada.");
        } else {
            ConsoleIO::PrintMensagem("Opcao invalida. Solicitacao nao foi alterada.");
        }
    }
}


void ControladorInterfaceHospede::criar() {
    bool criado = false;
    bool tudoOK = true;

    while (!criado) // Enquanto craido esta falso , ele repete
    {
        Hospede *hospede = new Hospede();

        if (hospede) {
            //Preencher atribultos com validacao
            if (tudoOK == false) {
                cout << "\nRetornando...\n\n";
                break;
            }

            ConsoleFormatter::MostrarTituloEmCaixa("Criando Novo Hospede");

            cout << "Informe o Nome: " << endl;
            string nomeStr = ConsoleIO::LerLinha();
            try {
                hospede->setNome(Nome(nomeStr));
            } catch (invalid_argument &erro) {
                cout << erro.what() << endl;
                tudoOK = false;
            }
            if (tudoOK) {
                cout << "Informe o Email: " << endl;
                string emailStr = ConsoleIO::LerLinha();
                try {
                    hospede->setEmail(Email(emailStr));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                cout << "Informe o Endereco: " << endl;
                string enderecoStr = ConsoleIO::LerLinha();
                try {
                    hospede->setEndereco(Endereco(enderecoStr));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                cout << "Informe o Cartao: " << endl;
                string cartaoStr = ConsoleIO::LerLinha();
                try {
                    ;
                    hospede->setCartao(Cartao(cartaoStr));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                cout << "Hospede Cadastrado" << endl;
                criado = true;

                PersistenciaHospede persistencia;
                persistencia.criar(*hospede);

                criado = true;
                cout << "Hospede cadastrado!\n";
                // coloca os Hospedes da listaGerentes que esta na memoria para o arquivo Dados_Gerentes.tsv .
            } else {
                cout << "Ops* Hospede nao cadastrado!\n";
            }
            delete hospede; // Liberar o ponteiro da memoria.
        }
    }
};

void ControladorInterfaceHospede::ler() {
    vector<Hospede *> listaHospedes = persistencia.listar(); // Vetor para Construir OBJETOS - HOSPEDE

    if (listaHospedes.empty()) {
        cout << "Nenhum hospede cadastrado.\n";
        return;
    }

    ConsoleFormatter::MostrarTituloEmCaixa("Lista de Gerentes");

    for (const auto &g: listaHospedes) {
        cout << "Nome: " << g->getNome() << endl;
        cout << "Email: " << g->getEmail() << endl;
        cout << "Endereco: " << g->getEndereco() << endl;
        cout << "Cartao: " << g->getCartao() << endl;
        cout << "-----------------------------\n";
    }
}

void ControladorInterfaceHospede::atualizar() {
    cout << "Funcao atualizar ainda nao implementada.\n";
}

bool ControladorInterfaceHospede::remover() {
    cout << "Informe o Email: \n";
    string emailStr = ConsoleIO::LerLinha();
    bool status = true; //persistencia.excluirPorEmail(emailStr);

    if (status == true) {
        cout << "Foi excluido com sucesso!\n";
    } else {
        cout << "Gerente nao encontrado!\n";
    }
    return status;
}