//
// Created by caleb on 10/10/2025.
//

#include "ServicosHospede.h"

#include "FabricaGerenciavel.h"
#include "HospedeGerenciavel.h"
#include "Menu.h"
#include "PersistenciaHospede.h"
#include "sqlite3.h"
#include "GeradorCodigo.h"

void ServicosHospede::acessandoHospede()
{
    Menu menu;

    const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
    const int OPCAO_HOSPEDAGENS = menu.adcionarItens("Opcoes de Hospedagem");
    const int OPCAO_CRIAR_SOLOCITACAO_DE_HOSPEDAGEM = menu.adcionarItens("Criar Solicitacao de Hospedagem");
    const int OPCAO_STATUS_DA_SOLICITACAO_DE_HOSPEDAGEM = menu.adcionarItens("Status da Solicitacao de Hospedagem");

    while (executando == true)
    {
        int opcao = menu.executa("Faca o acesso para liberar os servicos");

        if (opcao == OPCAO_VOLTAR_AO_SISTEMA)
        {
            executando = false;
            cout << "Voltando a selecao de usuario!" << endl;
        }
        else if (opcao == OPCAO_HOSPEDAGENS)
        {
            opcoesDeHospedagem();
        }
        else if (opcao == OPCAO_CRIAR_SOLOCITACAO_DE_HOSPEDAGEM)
        {
            solicitandoHospedagem();
        }
        else if (opcao == OPCAO_STATUS_DA_SOLICITACAO_DE_HOSPEDAGEM)
        {
            statusDaSolicitandoHospedagem();
        }
        else
        {
            cout << "Opcao Invalida!" << endl;
        }
    }
};

bool ServicosHospede::fazerLoginHospede(string emailCopia)
{
    //_________________________ABRE CONEXÂO_______________________________
    sqlite3* db;
    char* mensagemErro = nullptr;

    int rc = sqlite3_open("hotel.db", &db);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao abrir banco: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    //_________________________------------_______________________________

    sqlite3_stmt* stmt = nullptr;

    PersistenciaHospede dao;
    vector<Hospede*> hospedes = dao.listar();

    const char* sql = "SELECT nome, email, endereco, cartao FROM hospedes WHERE email = ?;";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    // Bind dos parâmetros
    sqlite3_bind_text(stmt, 1, emailCopia.c_str(), -1, SQLITE_STATIC);

    bool loginOK = false;
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::string nome = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string endereco = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string cartao = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

        Hospede* hospedeLogado = new Hospede(Nome(nome), Email(email), Endereco(endereco), Cartao(cartao));

        this->logHospede = hospedeLogado;
        this->hospedeEstaLogado = true;
        loginOK = true;

        std::cout << "Login Realizado com Sucesso" << std::endl;
    }

    if (!loginOK)
    {
        std::cout << "Erro: Usuario nao encontrado ou senha incorreta!" << std::endl;
    }

    sqlite3_finalize(stmt);

    //_________________________FECHA CONEXÂO_______________________________
    sqlite3_close(db);
    //_________________________------------_______________________________
    return false;
};

void ServicosHospede::logandoHospede()
{
    bool lacoLogin = false;
    string emailCopia = "";

    while (!lacoLogin) // Enquanto esta falso , ele repete
    {
        TextoApresentacao::MostrarTituloEmCaixa("Logando com Hospede");

        bool tudoOK = true;
        if (tudoOK)
        {
            cout << "Informe o Email: " << endl;
            emailCopia = TextoApresentacao::LerLinha();
        }
        if (tudoOK)
        {
            if (fazerLoginHospede(emailCopia))
            {
                lacoLogin = true;
            }
            else
            {
                TextoApresentacao::MostrarOpcao("Voltar", 0);
                TextoApresentacao::MostrarOpcao("Tentar novamente", 1);
                string opcao = TextoApresentacao::LerLinha();
                if (opcao == "0")
                {
                    break;
                }
                else if (opcao == "1")
                {
                    lacoLogin = false;
                }
            }
        }
        else
        {
            cout << "Gerente nao cadastrado" << endl;
        }
    }
}

void ServicosHospede::exibirCentralDeServicosHospedes()
{
    bool status = true;
    while (this->getHospedeEstaLogado())
    {
        if (status)
        {
            TextoApresentacao::MostrarTituloEmCaixa("CRUD Gerente");
            FabricaGerenciavel<HospedeGerenciavel> fabrica;
            fabrica.executarMenu(status);
        }
        else
        {
            this->hospedeEstaLogado = false;
        }
    };
}

void ServicosHospede::opcoesDeHospedagem()
{
    TextoApresentacao::MostrarTituloEmCaixa("Opcoes de Hospedagem");
    TextoApresentacao::MostrarTituloPergunta("\nEsta opcao ainda nao foi construida!\nRetornando...\n");
    return;
}

void ServicosHospede::solicitandoHospedagem()
{
    TextoApresentacao::MostrarTituloEmCaixa("Criar Solicitacao de Hospedagem");

    if (!hospedeEstaLogado || logHospede == nullptr)
    {
        TextoApresentacao::MostrarTituloRetorno("Nenhum hospede esta logado.");
        return;
    }

    std::string codigoSolicitacao = GeradorCodigo::gerar("SOL");
    std::string emailHospede = logHospede->getEmail();

    TextoApresentacao::MostrarTituloPergunta("Codigo do hotel desejado:");
    std::string idHotel = TextoApresentacao::LerLinha();

    TextoApresentacao::MostrarTituloPergunta("Codigo do quarto desejado:");
    std::string idQuarto = TextoApresentacao::LerLinha();

    TextoApresentacao::MostrarTituloPergunta("Data de chegada (dd/mm/aaaa):");
    std::string chegadaStr = TextoApresentacao::LerLinha();

    TextoApresentacao::MostrarTituloPergunta("Data de partida (dd/mm/aaaa):");
    std::string partidaStr = TextoApresentacao::LerLinha();

    try
    {
        Data chegada(chegadaStr);
        Data partida(partidaStr);

        SolicitacaoHospedagem solicitacao(
            Codigo(codigoSolicitacao),
            emailHospede,
            idHotel,
            idQuarto,
            chegada,
            partida,
            0 // pendente
        );

        PersistenciaSolicitacaoHospedagem::salvar(solicitacao);
        TextoApresentacao::MostrarTituloRetorno("Solicitacao registrada com sucesso!");
    }
    catch (std::exception& e)
    {
        TextoApresentacao::MostrarTituloRetorno("Erro ao criar solicitacao: " + std::string(e.what()));
    }
}

void ServicosHospede::statusDaSolicitandoHospedagem()
{
    TextoApresentacao::MostrarTituloEmCaixa("Status da Solicitacao de Hospedagem");

    if (!hospedeEstaLogado || logHospede == nullptr)
    {
        TextoApresentacao::MostrarTituloRetorno("Nenhum hospede esta logado.");
        return;
    }

    std::string email = logHospede->getEmail();
    vector<SolicitacaoHospedagem> lista = PersistenciaSolicitacaoHospedagem::buscarPorEmail(email);

    if (lista.empty())
    {
        TextoApresentacao::MostrarTituloRetorno("Nenhuma solicitacao encontrada.");
        return;
    }

    for (const auto& s : lista)
    {
        std::string statusStr = (s.getStatus() == 0) ? "Pendente" : (s.getStatus() == 1) ? "Aprovada" : "Recusada";

        std::cout << "----------------------------------------\n";
        std::cout << "Codigo: " << s.getCodigo().getValor() << "\n";
        std::cout << "Hotel: " << s.getHotelId() << "\n";
        std::cout << "Quarto: " << s.getQuartoId() << "\n";
        std::cout << "Chegada: " << s.getChegada().toString() << "\n";
        std::cout << "Partida: " << s.getPartida().toString() << "\n";
        std::cout << "Status: " << statusStr;

        if (s.getStatus() == 2)
            std::cout << " | Motivo: " << s.getMotivoRecusa();

        std::cout << "\n----------------------------------------\n";
    }
}