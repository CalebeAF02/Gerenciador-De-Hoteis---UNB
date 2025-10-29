//
// Created by caleb on 10/10/2025.
//

#include "ServicosGerente.h"

#include "FabricaGerenciavel.h"
#include "GerenteGerenciavel.h"
#include "HospedeGerenciavel.h"
#include "Menu.h"
#include "ServicosHospede.h"
#include "ServicosHotel.h"
#include "ServicosQuarto.h"
#include "ServicosReserva.h"
#include "sqlite3.h"

void ServicosGerente::acessandoGerente()
{
    Menu menu;

    const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
    const int OPCAO_CRIAR_UM_GERENTE = menu.adcionarItens("Criar Gerente");
    const int OPCAO_FAZER_LOGIN = menu.adcionarItens("Fazer Login");

    while (executando == true)
    {
        int opcao = menu.executa("Faca o acesso para liberar os servicos");

        if (opcao == OPCAO_VOLTAR_AO_SISTEMA)
        {
            executando = false;
            cout << "Voltando a selecao de usuario!" << endl;
        }
        else if (opcao == OPCAO_CRIAR_UM_GERENTE)
        {
            FabricaGerenciavel<GerenteGerenciavel> fabrica;
            fabrica.criar(); // apenas cria o gerente, sem abrir o menu
        }
        else if (opcao == OPCAO_FAZER_LOGIN)
        {
            logandoGerente();
            if (getGerenteEstaLogado())
            {
                cout << "Agora Voce Possui Super-Poderes" << endl;
                exibirCentralDeServicos();
            }
        }
        else
        {
            cout << "Opcao Invalida!" << endl;
        }
    }
};

bool ServicosGerente::fazerLoginGerente(string emailCopia, string senhaCopia)
{
    PersistenciaGerente dao;
    Gerente* gerenteLogado = dao.autenticarGerentePeloBD(emailCopia, senhaCopia);

    if (gerenteLogado != nullptr)
    {
        this->logGerente = gerenteLogado;
        this->gerenteEstaLogado = true;
        std::cout << "Login realizado com sucesso!\n";
        return true;
    }
    else
    {
        std::cout << "Erro: Usuario nao encontrado ou senha incorreta!\n";
        return false;
    }

    /*
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

    PersistenciaGerente dao;
    vector<Gerente*> gerentes = dao.listarBD();

    const char* sql = "SELECT nome, email, ramal, senha FROM gerentes WHERE email = ? AND senha = ?;";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    // Bind dos parâmetros
    sqlite3_bind_text(stmt, 1, emailCopia.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, senhaCopia.c_str(), -1, SQLITE_STATIC);

    bool loginOK = false;
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::string nome = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string ramal = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string senha = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

        Gerente* gerenteLogado = new Gerente(Nome(nome), Email(email), Ramal(ramal), Senha(senha));

        this->logGerente = gerenteLogado;
        this->gerenteEstaLogado = true;
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
    return loginOK;
    */
};

void ServicosGerente::logandoGerente()
{
    bool lacoLogin = false;
    string emailCopia = "";
    string senhaCopia = "";

    while (!lacoLogin) // Enquanto esta falso , ele repete
    {
        TextoApresentacao::MostrarTituloEmCaixa("Logando com Gerente");

        bool tudoOK = true;
        if (tudoOK)
        {
            cout << "Informe o Email: \n";
            emailCopia = TextoApresentacao::LerLinha();
        }
        if (tudoOK)
        {
            cout << "Informe o Senha: \n";
            senhaCopia = TextoApresentacao::LerLinha();
        }
        if (tudoOK)
        {
            if (fazerLoginGerente(emailCopia, senhaCopia))
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
};

void ServicosGerente::exibirCentralDeServicos()
{
    Menu menu;

    const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");
    const int OPCAO_GERENCIE_GERENTES = menu.adcionarItens("Gerencie Gerentes");
    const int OPCAO_GERENCIE_HOSPEDES = menu.adcionarItens("Gerencie Hospedes");
    const int OPCAO_GERENCIE_HOTEIS = menu.adcionarItens("Gerencie Hoteis");
    const int OPCAO_GERENCIE_QUARTOS = menu.adcionarItens("Gerencie Quartos");
    const int OPCAO_GERENCIE_RESERVAS = menu.adcionarItens("Gerencie Reservas");
    const int OPCAO_AVALIAR_SOLICITACOES = menu.adcionarItens("Avaliar Solicitacoes de Hospedagem");

    while (this->getGerenteEstaLogado())
    {
        int opcao = menu.executa("Seja bem vindo a central de servicos");

        if (opcao == OPCAO_VOLTAR_AO_SISTEMA)
        {
            this->gerenteEstaLogado = false;
            cout << "Voce Saiu da Central de servicos e foi deslogado!\n";
        }
        else if (opcao == OPCAO_GERENCIE_GERENTES)
        {
            exibirCentralDeServicosGerentes();
        }
        else if (opcao == OPCAO_GERENCIE_HOSPEDES)
        {
            ServicosHospede servicosHospede;
            servicosHospede.exibirCentralDeServicosHospedes();
        }
        else if (opcao == OPCAO_GERENCIE_HOTEIS)
        {
            ServicosHotel servicosHotel;
            servicosHotel.exibirCentralDeServicosHotel();
        }
        else if (opcao == OPCAO_GERENCIE_QUARTOS)
        {
            ServicosQuarto servicosQuarto;
            servicosQuarto.exibirCentralDeServicosQuartos();
        }
        else if (opcao == OPCAO_GERENCIE_RESERVAS)
        {
            ServicosReserva servicosReserva;
            servicosReserva.exibirCentralDeServicosReservas();
        }
        else if (opcao == OPCAO_AVALIAR_SOLICITACOES)
        {
            HospedeGerenciavel crud;
            crud.avaliarSolicitacoes();
        }
        else
        {
            cout << "Opcao Invalida!" << endl;
        }
    };
}

void ServicosGerente::exibirCentralDeServicosGerentes()
{
    bool status = true;
    while (this->getGerenteEstaLogado())
    {
        FabricaGerenciavel<GerenteGerenciavel> fabrica;
        fabrica.executarMenu(status);
        if (status == false)
        {
            break;
        }
    };
}

void ServicosGerente::excluirMeuCadastro()
{
    if (!gerenteEstaLogado || logGerente == nullptr)
    {
        cout << "Voce precisa estar logado para excluir seu cadastro.\n";
        return;
    }
    PersistenciaGerente persistencia;
    bool sucesso = persistencia.excluirPorEmailDoBD(logGerente);

    if (sucesso)
    {
        gerenteEstaLogado = false;
        logGerente = nullptr;
        executando = false; // ou redireciona para menu principal
    }
    else
    {
        cout << "Nao foi possivel excluir seu cadastro.\n";
    }
}