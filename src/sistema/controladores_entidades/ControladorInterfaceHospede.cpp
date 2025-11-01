//
// Created by caleb on 10/10/2025.
//

#include "ControladorInterfaceHospede.h"

#include "FabricaGerenciavel.h"
#include "HospedeGerenciavel.h"
#include "Menu.h"
#include "PersistenciaHospede.h"
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
        TextoApresentacao::MostrarTituloEmCaixa("CRUD Gerente");
        FabricaGerenciavel<HospedeGerenciavel> fabrica;
        fabrica.executarMenu(status);
    };
}

void ControladorInterfaceHospede::opcoesDeHospedagem() {
    TextoApresentacao::MostrarTituloEmCaixa("Opcoes de Hospedagem");
    TextoApresentacao::MostrarTituloPergunta("\nEsta opcao ainda nao foi construida!\nRetornando...\n");
    return;
}

void ControladorInterfaceHospede::solicitandoHospedagem() {
    TextoApresentacao::MostrarTituloEmCaixa("Criar Solicitacao de Hospedagem");

    TextoApresentacao::MostrarTituloPergunta("Informe o Email");
    std::string email = TextoApresentacao::LerLinha();

    TextoApresentacao::MostrarTituloPergunta("Codigo do hotel desejado:");
    std::string idHotel = TextoApresentacao::LerLinha();

    TextoApresentacao::MostrarTituloPergunta("Codigo do quarto desejado:");
    std::string idQuarto = TextoApresentacao::LerLinha();

    TextoApresentacao::MostrarTituloPergunta("Data de chegada (dd/mm/aaaa):");
    std::string chegadaStr = TextoApresentacao::LerLinha();

    TextoApresentacao::MostrarTituloPergunta("Data de partida (dd/mm/aaaa):");
    std::string partidaStr = TextoApresentacao::LerLinha();

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
        TextoApresentacao::MostrarTituloRetorno("Solicitacao registrada com sucesso!");
    } catch (std::exception &e) {
        TextoApresentacao::MostrarTituloRetorno("Erro ao criar solicitacao: " + std::string(e.what()));
    }
}

void ControladorInterfaceHospede::statusDaSolicitandoHospedagem() const {
    TextoApresentacao::MostrarTituloEmCaixa("Status da Solicitacao de Hospedagem");

    TextoApresentacao::MostrarTituloPergunta("Informe o Email");
    std::string email = TextoApresentacao::LerLinha();

    const vector<SolicitacaoHospedagem> lista = PersistenciaSolicitacaoHospedagem::buscarPorEmail(email);

    if (lista.empty()) {
        TextoApresentacao::MostrarTituloRetorno("Nenhuma solicitacao encontrada.");
        return;
    }

    for (const SolicitacaoHospedagem &s: lista) {
        std::string statusStr = (s.getStatus() == StatusSolicitacaoHospedagem::PENDENTE)
                                    ? "Pendente"
                                    : (s.getStatus() == StatusSolicitacaoHospedagem::APROVADO)
                                          ? "Aprovada"
                                          : "Recusada";

        std::cout << "----------------------------------------\n";
        std::cout << "Hotel: " << s.getHotelId() << "\n";
        std::cout << "Quarto: " << s.getQuartoId() << "\n";
        std::cout << "Chegada: " << s.getChegada().toString() << "\n";
        std::cout << "Partida: " << s.getPartida().toString() << "\n";
        std::cout << "Status: " << statusStr;

        if (s.getStatus() == StatusSolicitacaoHospedagem::RECUSADO)
            std::cout << " | Motivo: " << s.getMotivoRecusa();

        std::cout << "\n----------------------------------------\n";
    }
}

void ControladorInterfaceHospede::avaliarSolicitacoes() {
    TextoApresentacao::MostrarTituloEmCaixa("Avaliar Solicitacoes de Hospedagem");

    auto pendentes = PersistenciaSolicitacaoHospedagem::buscarPorStatus(0); // status = pendente

    if (pendentes.empty()) {
        TextoApresentacao::MostrarTituloRetorno("Nenhuma solicitacao pendente.");
        return;
    }

    for (auto &solicitacao: pendentes) {
        cout << "\nHospede: " << solicitacao.getHospedeId()
                << "\nHotel: " << solicitacao.getHotelId()
                << "\nQuarto: " << solicitacao.getQuartoId()
                << "\nChegada: " << solicitacao.getChegada().toString()
                << "\nPartida: " << solicitacao.getPartida().toString()
                << "\nStatus atual: Pendente\n";

        TextoApresentacao::MostrarTituloPergunta("Deseja aprovar (A) ou recusar (R) esta solicitacao?");
        std::string escolha = TextoApresentacao::RecebeOpcao();

        if (escolha == "A" || escolha == "a") {
            solicitacao.setStatus(StatusSolicitacaoHospedagem::APROVADO); // aprovada
            solicitacao.setMotivoRecusa(""); // limpa motivo
            PersistenciaSolicitacaoHospedagem::atualizar(solicitacao);
            TextoApresentacao::MostrarTituloRetorno("Solicitacao aprovada com sucesso.");
        } else if (escolha == "R" || escolha == "r") {
            TextoApresentacao::MostrarTituloPergunta("Informe o motivo da recusa:");
            std::string motivo = TextoApresentacao::LerLinha();
            solicitacao.setStatus(StatusSolicitacaoHospedagem::RECUSADO); // recusada
            solicitacao.setMotivoRecusa(motivo);
            PersistenciaSolicitacaoHospedagem::atualizar(solicitacao);
            TextoApresentacao::MostrarTituloRetorno("Solicitacao recusada.");
        } else {
            TextoApresentacao::MostrarTituloRetorno("Opcao invalida. Solicitacao nao foi alterada.");
        }
    }
}