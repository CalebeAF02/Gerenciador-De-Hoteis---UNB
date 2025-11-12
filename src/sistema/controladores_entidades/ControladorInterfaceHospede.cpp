//
// Created by caleb on 10/10/2025.
//

#include "ControladorInterfaceHospede.hpp"

#include "FabricaGerenciavel.hpp"
#include "Menu.hpp"
#include "PersistenciaHospede.hpp"
#include "sqlite3.h"

void ControladorInterfaceHospede::exibirMenu() {
    bool executando = true;

    Menu menu;

    const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
    const int OPCAO_HOSPEDAGENS = menu.adcionarItens("Opcoes de Hospedagem");
    const int OPCAO_CRIAR_SOLOCITACAO_DE_HOSPEDAGEM = menu.adcionarItens("Criar Solicitacao de Hospedagem");
    const int OPCAO_STATUS_DA_SOLICITACAO_DE_HOSPEDAGEM = menu.adcionarItens("Status da Solicitacao de Hospedagem");

    while (executando == true) {
        int opcao = menu.executa("Faca o acesso para liberar os servicos");

        if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
            executando = false;
            IO::Println("Voltando a selecao de usuario!");
        } else if (opcao == OPCAO_HOSPEDAGENS) {
            opcoesDeHospedagem();
        } else if (opcao == OPCAO_CRIAR_SOLOCITACAO_DE_HOSPEDAGEM) {
            solicitandoHospedagem();
        } else if (opcao == OPCAO_STATUS_DA_SOLICITACAO_DE_HOSPEDAGEM) {
            statusDaSolicitandoHospedagem();
        } else {
            IO::Println("Opcao Invalida!");
        }
    }
};

void ControladorInterfaceHospede::exibirMenuCRUD() {
    bool executando = true;

    while (executando) {
        FabricaGerenciavel<ControladorInterfaceHospede> fabrica;
        fabrica.executarMenu("Menu CRUD Hospede",executando);
        if (executando == false) {
            break;
        }
    };
}

void ControladorInterfaceHospede::opcoesDeHospedagem() {
    bool executando = true;

    Formato::TituloEmCaixa("Opcoes de Hospedagem");
    IO::Println("Esta opcao ainda nao foi construida! Retornando...");
}

void ControladorInterfaceHospede::solicitandoHospedagem() {
    bool executando = true;

    while (executando) {
        Formato::TituloEmCaixa("Criar Solicitacao de Hospedagem");

        IO::Print("Informe o Email: ");
        string email = IO::LerLinha();

        IO::Print("Codigo do hotel desejado: ");
        string idHotel = IO::LerLinha();

        IO::Print("Codigo do quarto desejado: ");
        string idQuarto = IO::LerLinha();

        IO::Print("Data de chegada (dd/mm/aaaa): ");
        string chegadaStr = IO::LerLinha();

        IO::Print("Data de partida (dd/mm/aaaa): ");
        string partidaStr = IO::LerLinha();

        IO::Println(idHotel.length() + " e " + idQuarto.length());
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
            IO::Println("Solicitacao registrada com sucesso!");
        } catch (exception &e) {
            IO::Println("Erro ao criar solicitacao: " + string(e.what()));
        }
        if (IO::tentarNovamente()) {
            break;
        }
    }
}

void ControladorInterfaceHospede::statusDaSolicitandoHospedagem() const {
    Formato::TituloEmCaixa("Status da Solicitacao de Hospedagem");

    IO::Print("Informe o Email: ");
    string email = IO::LerLinha();

    const vector<SolicitacaoHospedagem> lista = PersistenciaSolicitacaoHospedagem::buscarPorEmail(email);

    if (lista.empty()) {
        IO::Println("Nenhuma solicitacao encontrada.");
        return;
    }

    for (const SolicitacaoHospedagem &s: lista) {
        string statusStr = (s.getStatus() == StatusSolicitacaoHospedagem::PENDENTE)
                               ? "Pendente"
                               : (s.getStatus() == StatusSolicitacaoHospedagem::APROVADO)
                                     ? "Aprovada"
                                     : "Recusada";

        IO::Println("Hotel: " + s.getHotelId());
        IO::Println("Quarto: " + s.getQuartoId());
        IO::Println("Chegada: " + s.getChegada().toString());
        IO::Println("Partida: " + s.getPartida().toString());
        IO::Println("Status: " + statusStr);

        if (s.getStatus() == StatusSolicitacaoHospedagem::RECUSADO)
            cout << "\n | Motivo: " << s.getMotivoRecusa();
    }
}

void ControladorInterfaceHospede::avaliarSolicitacoes() {
    Formato::TituloEmCaixa("Avaliar Solicitacoes de Hospedagem");

    auto pendentes = PersistenciaSolicitacaoHospedagem::buscarPorStatus(0); // status = pendente

    if (pendentes.empty()) {
        IO::Println("Nenhuma solicitacao pendente.");
        return;
    }

    for (auto &solicitacao: pendentes) {
        IO::Println("Hospede: " + solicitacao.getHospedeId());
        IO::Println("Hotel: " + solicitacao.getHotelId());
        IO::Println("Quarto: " + solicitacao.getQuartoId());
        IO::Println("Chegada: " + solicitacao.getChegada().toString());
        IO::Println("Partida: " + solicitacao.getPartida().toString());
        IO::Println("Status atual: Pendente");

        IO::Println("Deseja aprovar (A) ou recusar (R) esta solicitacao?");
        string escolha = IO::LerOpcao();

        if (escolha == "A" || escolha == "a") {
            solicitacao.setStatus(StatusSolicitacaoHospedagem::APROVADO); // aprovada
            solicitacao.setMotivoRecusa(""); // limpa motivo
            PersistenciaSolicitacaoHospedagem::atualizar(solicitacao);
            IO::Println("Solicitacao aprovada com sucesso.");
        } else if (escolha == "R" || escolha == "r") {
            IO::Println("Informe o motivo da recusa:");
            string motivo = IO::LerLinha();
            solicitacao.setStatus(StatusSolicitacaoHospedagem::RECUSADO); // recusada
            solicitacao.setMotivoRecusa(motivo);
            PersistenciaSolicitacaoHospedagem::atualizar(solicitacao);
            IO::Println("Solicitacao recusada.");
        } else {
            IO::Println("Opcao invalida. Solicitacao nao foi alterada.");
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
            Formato::TituloEmCaixa("Criando Novo Hospede");

            IO::Print("Informe o Nome: ");
            string nomeStr = IO::LerLinha();
            try {
                hospede->setNome(Nome(nomeStr));
            } catch (invalid_argument &erro) {
                IO::Println(erro.what());
                tudoOK = false;
            }
            if (tudoOK) {
                IO::Print("Informe o Email: ");
                string emailStr = IO::LerLinha();
                try {
                    hospede->setEmail(Email(emailStr));
                } catch (invalid_argument &erro) {
                    IO::Println(erro.what());
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                IO::Print("Informe o Endereco: ");
                string enderecoStr = IO::LerLinha();
                try {
                    hospede->setEndereco(Endereco(enderecoStr));
                } catch (invalid_argument &erro) {
                    IO::Println(erro.what());
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                IO::Print("Informe o Cartao: ");
                string cartaoStr = IO::LerLinha();
                try {
                    ;
                    hospede->setCartao(Cartao(cartaoStr));
                } catch (invalid_argument &erro) {
                    IO::Println(erro.what());
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                IO::Println("Hospede Cadastrado");
                criado = true;

                PersistenciaHospede persistencia;
                persistencia.criar(*hospede);

                criado = true;
                IO::Println("Hospede cadastrado!");
                // coloca os Hospedes da listaGerentes que esta na memoria para o arquivo Dados_Gerentes.tsv .
            } else {
                IO::Println("Erro: Hospede nao cadastrado!");
            }
            delete hospede; // Liberar o ponteiro da memoria.
        }
    }
};

void ControladorInterfaceHospede::ler() {
    vector<Hospede *> listaHospedes = persistencia.listar(); // Vetor para Construir OBJETOS - HOSPEDE

    if (listaHospedes.empty()) {
        IO::Println("Nenhum hospede cadastrado.");
        return;
    }

    Formato::TituloEmCaixa("Lista de Hospedes");

    for (const auto &g: listaHospedes) {
        IO::Println("Nome: " + g->getNome());
        IO::Println("Email: " + g->getEmail());
        IO::Println("Endereco: " + g->getEndereco());
        IO::Println("Cartao: " + g->getCartao());
    }
}

void ControladorInterfaceHospede::atualizar() {
    IO::Println("Funcao atualizar ainda nao implementada.");
}

bool ControladorInterfaceHospede::remover() {
    IO::Print("Informe o Email: ");
    string emailStr = IO::LerLinha();
    bool status = true; //persistencia.excluirPorEmail(emailStr);

    if (status) {
        IO::Println("Foi excluido com sucesso!");
    } else {
        IO::Println("Hospede nao encontrado!");
    }
    return status;
}
