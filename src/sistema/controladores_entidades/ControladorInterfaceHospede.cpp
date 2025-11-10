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

    this->executando = true;

    while (executando == true) {
        int opcao = menu.executa("Faca o acesso para liberar os servicos");

        if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
            executando = false;
            ConsoleIO::PrintMenssagem("Voltando a selecao de usuario!");
        } else if (opcao == OPCAO_HOSPEDAGENS) {
            opcoesDeHospedagem();
        } else if (opcao == OPCAO_CRIAR_SOLOCITACAO_DE_HOSPEDAGEM) {
            solicitandoHospedagem();
        } else if (opcao == OPCAO_STATUS_DA_SOLICITACAO_DE_HOSPEDAGEM) {
            statusDaSolicitandoHospedagem();
        } else {
            ConsoleIO::PrintMenssagem("Opcao Invalida!");
        }
    }
};

void ControladorInterfaceHospede::exibirMenuCRUD() {
    this->executando = true;

    while (executando) {
        ConsoleFormatter::MostrarTituloEmCaixa("CRUD Gerente");
        FabricaGerenciavel<ControladorInterfaceHospede> fabrica;
        fabrica.executarMenu(executando);
    };
}

void ControladorInterfaceHospede::opcoesDeHospedagem() {
    ConsoleFormatter::MostrarTituloEmCaixa("Opcoes de Hospedagem");
    ConsoleIO::PrintMenssagem("Esta opcao ainda nao foi construida! Retornando...");
    return;
}

void ControladorInterfaceHospede::solicitandoHospedagem() {
    ConsoleFormatter::MostrarTituloEmCaixa("Criar Solicitacao de Hospedagem");

    ConsoleIO::SubPergunta("Informe o Email: ");
    string email = ConsoleIO::LerLinha();

    ConsoleIO::SubPergunta("Codigo do hotel desejado: ");
    string idHotel = ConsoleIO::LerLinha();

    ConsoleIO::SubPergunta("Codigo do quarto desejado: ");
    string idQuarto = ConsoleIO::LerLinha();

    ConsoleIO::SubPergunta("Data de chegada (dd/mm/aaaa): ");
    string chegadaStr = ConsoleIO::LerLinha();

    ConsoleIO::SubPergunta("Data de partida (dd/mm/aaaa): ");
    string partidaStr = ConsoleIO::LerLinha();

    ConsoleIO::PrintMenssagem(idHotel.length() + " e " + idQuarto.length());
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
        ConsoleIO::PrintMenssagem("Solicitacao registrada com sucesso!");
    } catch (exception &e) {
        ConsoleIO::PrintMenssagem("Erro ao criar solicitacao: " + string(e.what()));
    }
}

void ControladorInterfaceHospede::statusDaSolicitandoHospedagem() const {
    ConsoleFormatter::MostrarTituloEmCaixa("Status da Solicitacao de Hospedagem");

    ConsoleIO::SubPergunta("Informe o Email: ");
    string email = ConsoleIO::LerLinha();

    const vector<SolicitacaoHospedagem> lista = PersistenciaSolicitacaoHospedagem::buscarPorEmail(email);

    if (lista.empty()) {
        ConsoleIO::PrintMenssagem("Nenhuma solicitacao encontrada.");
        return;
    }

    for (const SolicitacaoHospedagem &s: lista) {
        string statusStr = (s.getStatus() == StatusSolicitacaoHospedagem::PENDENTE)
                               ? "Pendente"
                               : (s.getStatus() == StatusSolicitacaoHospedagem::APROVADO)
                                     ? "Aprovada"
                                     : "Recusada";

        ConsoleIO::PrintMenssagem("Hotel: " + s.getHotelId());
        ConsoleIO::PrintMenssagem("Quarto: " + s.getQuartoId());
        ConsoleIO::PrintMenssagem("Chegada: " + s.getChegada().toString());
        ConsoleIO::PrintMenssagem("Partida: " + s.getPartida().toString());
        ConsoleIO::PrintMenssagem("Status: " + statusStr);

        if (s.getStatus() == StatusSolicitacaoHospedagem::RECUSADO)
            cout << "\n | Motivo: " << s.getMotivoRecusa();
    }
}

void ControladorInterfaceHospede::avaliarSolicitacoes() {
    ConsoleFormatter::MostrarTituloEmCaixa("Avaliar Solicitacoes de Hospedagem");

    auto pendentes = PersistenciaSolicitacaoHospedagem::buscarPorStatus(0); // status = pendente

    if (pendentes.empty()) {
        ConsoleIO::PrintMenssagem("Nenhuma solicitacao pendente.");
        return;
    }

    for (auto &solicitacao: pendentes) {
        ConsoleIO::PrintMenssagem("Hospede: " + solicitacao.getHospedeId());
        ConsoleIO::PrintMenssagem("Hotel: " + solicitacao.getHotelId());
        ConsoleIO::PrintMenssagem("Quarto: " + solicitacao.getQuartoId());
        ConsoleIO::PrintMenssagem("Chegada: " + solicitacao.getChegada().toString());
        ConsoleIO::PrintMenssagem("Partida: " + solicitacao.getPartida().toString());
        ConsoleIO::PrintMenssagem("Status atual: Pendente");

        ConsoleIO::Pergunta("Deseja aprovar (A) ou recusar (R) esta solicitacao?");
        string escolha = ConsoleIO::LerOpcao();

        if (escolha == "A" || escolha == "a") {
            solicitacao.setStatus(StatusSolicitacaoHospedagem::APROVADO); // aprovada
            solicitacao.setMotivoRecusa(""); // limpa motivo
            PersistenciaSolicitacaoHospedagem::atualizar(solicitacao);
            ConsoleIO::PrintMenssagem("Solicitacao aprovada com sucesso.");
        } else if (escolha == "R" || escolha == "r") {
            ConsoleIO::Pergunta("Informe o motivo da recusa:");
            string motivo = ConsoleIO::LerLinha();
            solicitacao.setStatus(StatusSolicitacaoHospedagem::RECUSADO); // recusada
            solicitacao.setMotivoRecusa(motivo);
            PersistenciaSolicitacaoHospedagem::atualizar(solicitacao);
            ConsoleIO::PrintMenssagem("Solicitacao recusada.");
        } else {
            ConsoleIO::PrintMenssagem("Opcao invalida. Solicitacao nao foi alterada.");
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
            ConsoleFormatter::MostrarTituloEmCaixa("Criando Novo Hospede");

            ConsoleIO::SubPergunta("Informe o Nome: ");
            string nomeStr = ConsoleIO::LerLinha();
            try {
                hospede->setNome(Nome(nomeStr));
            } catch (invalid_argument &erro) {
                cout << erro.what() << endl;
                tudoOK = false;
            }
            if (tudoOK) {
                ConsoleIO::SubPergunta("Informe o Email: ");
                string emailStr = ConsoleIO::LerLinha();
                try {
                    hospede->setEmail(Email(emailStr));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                ConsoleIO::SubPergunta("Informe o Endereco: ");
                string enderecoStr = ConsoleIO::LerLinha();
                try {
                    hospede->setEndereco(Endereco(enderecoStr));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                ConsoleIO::SubPergunta("Informe o Cartao: ");
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
                ConsoleIO::PrintMenssagem("Hospede Cadastrado");
                criado = true;

                PersistenciaHospede persistencia;
                persistencia.criar(*hospede);

                criado = true;
                ConsoleIO::PrintMenssagem("Hospede cadastrado!");
                // coloca os Hospedes da listaGerentes que esta na memoria para o arquivo Dados_Gerentes.tsv .
            } else {
                ConsoleIO::PrintMenssagem("Erro: Hospede nao cadastrado!");
            }
            delete hospede; // Liberar o ponteiro da memoria.
        }
    }
};

void ControladorInterfaceHospede::ler() {
    vector<Hospede *> listaHospedes = persistencia.listar(); // Vetor para Construir OBJETOS - HOSPEDE

    if (listaHospedes.empty()) {
        ConsoleIO::PrintMenssagem("Nenhum hospede cadastrado.");
        return;
    }

    ConsoleFormatter::MostrarTituloEmCaixa("Lista de Hospedes");

    for (const auto &g: listaHospedes) {
        ConsoleIO::PrintMenssagem("Nome: " + g->getNome());
        ConsoleIO::PrintMenssagem("Email: " + g->getEmail());
        ConsoleIO::PrintMenssagem("Endereco: " + g->getEndereco());
        ConsoleIO::PrintMenssagem("Cartao: " + g->getCartao());
    }
}

void ControladorInterfaceHospede::atualizar() {
    ConsoleIO::PrintMenssagem("Funcao atualizar ainda nao implementada.");
}

bool ControladorInterfaceHospede::remover() {
    ConsoleIO::SubPergunta("Informe o Email: ");
    string emailStr = ConsoleIO::LerLinha();
    bool status = true; //persistencia.excluirPorEmail(emailStr);

    if (status) {
        ConsoleIO::PrintMenssagem("Foi excluido com sucesso!");
    } else {
        ConsoleIO::PrintMenssagem("Hospede nao encontrado!");
    }
    return status;
}
