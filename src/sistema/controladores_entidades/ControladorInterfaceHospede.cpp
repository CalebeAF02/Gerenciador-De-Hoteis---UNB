//
// Created by caleb on 10/10/2025.
//

#include "ControladorInterfaceHospede.hpp"

#include "FabricaGerenciavel.hpp"
#include "../../../libs/menu/Menu.hpp"
#include "PersistenciaHospede.hpp"
#include "sqlite3.h"


void ControladorInterfaceHospede::exibirMenuCRUD() {
    bool executando = true;

    while (executando) {
        FabricaGerenciavel<ControladorInterfaceHospede> fabrica;
        fabrica.executarMenu("Menu CRUD Hospede", executando);
        if (executando == false) {
            break;
        }
    };
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