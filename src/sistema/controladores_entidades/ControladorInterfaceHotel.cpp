//
// Created by caleb on 10/10/2025.
//

#include "ControladorInterfaceHotel.hpp"

void ControladorInterfaceHotel::exibirMenu() {
}

void ControladorInterfaceHotel::exibirMenuCRUD() {
    Menu menu;

    const int OPCAO_VOLTAR_ANTERIOR = menu.adcionarItens("Voltar");
    const int OPCAO_CRIAR_HOTEL = menu.adcionarItens("Criar Hotel");
    const int OPCAO_LER_HOTEL = menu.adcionarItens("Ler Hoteis");
    const int OPCAO_ATUALIZAR_HOTEL = menu.adcionarItens("Atualizar Hotel");

    bool executando = true;
    while (executando) {
        int opcao = menu.executa("Seja bem vindo a central de servicos");

        if (opcao == OPCAO_VOLTAR_ANTERIOR) {
            executando = false;
        } else if (opcao == OPCAO_CRIAR_HOTEL) {
            criar();
        } else if (opcao == OPCAO_LER_HOTEL) {
            ler();
        } else if (opcao == OPCAO_ATUALIZAR_HOTEL) {
            atualizar();
        } else {
            cout << "Opcao Invalida!" << endl;
        }
    };
}

void ControladorInterfaceHotel::criar() {
    bool criado = false;
    bool tudoOK = true;

    while (!criado) // Enquanto craido esta falso , ele repete
    {
        Hotel *hotel = new Hotel();

        if (hotel) {
            ConsoleFormatter::MostrarTituloEmCaixa("Criando Novo Hotel");
            if (tudoOK) {
                cout << "Informe o Nome: \n";
                string valor = ConsoleIO::LerLinha();
                try {
                    hotel->setNome(Nome(valor));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                cout << "Informe o Endereco: \n";
                string valor = ConsoleIO::LerLinha();
                try {
                    hotel->setEndereco(Endereco(valor));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                cout << "Informe o Telefone: \n";
                string valor = ConsoleIO::LerLinha();
                try {
                    hotel->setTelefone(Telefone(valor));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                cout << "Informe o Codigo: \n";
                string valor = ConsoleIO::LerLinha();
                try {
                    hotel->setCodigo(Codigo(valor));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                PersistenciaHotel persistencia;
                bool sucesso = persistencia.inserir(hotel);

                if (sucesso) {
                    criado = true;
                    cout << "Hotel Cadastrado!\n";
                } else {
                    cout << "Erro ao cadastrar hotel no banco!\n";
                    cout << "Retornando ao menu de acesso...\n";
                    break;
                }
            } else {
                cout << "Ops* Hotel nao cadastrado!\n";
                cout << "Retornando ao menu de acesso...\n";
                break;
            }
            delete hotel; // Liberar o ponteiro da memoria.
        }
    }
};

void ControladorInterfaceHotel::ler() {
    vector<HotelDTO *> lista = persistencia.listar();

    if (lista.empty()) {
        cout << "Nenhum gerente cadastrado.\n";
        return;
    }

    // 1. CABEÇALHOS
    vector<string> titulosTabela = {"Id", "Nome", "Endereco", "Telefone", "Codigo"};

    // 2. DADOS (Iterar sobre listaGerentes e extrair)
    vector<vector<string> > dadosTabela;
    for (const HotelDTO *const &g: lista) {
        dadosTabela.push_back({
            to_string(g->getId()),
            g->getNome(),
            g->getEndereco(),
            g->getTelefone(),
            g->getCodigo()
        });
    }

    // 3. CHAMADA GENÉRICA
    ConsoleFormatter::MostrarTabelaGenerica("Lista de Hoteis", titulosTabela, dadosTabela);
}
void ControladorInterfaceHotel::atualizar() {
    ConsoleFormatter::MostrarTituloEmCaixa("Atualizando Hotel");

    ConsoleIO::PrintMensagem("Informe o Id do hotel: ");
    string id_hotel = ConsoleIO::LerLinha();

    if (ValidadorNumerico::verificaSeENumero(id_hotel)) {
        PersistenciaHotel persistencia_hotel;
        int trasformar = stoi(id_hotel);
        optional<HotelDTO> existe_hotel = persistencia_hotel.buscaHotelPorID(trasformar);
        // transforma a string em numero e verica no banco, retornando um Hotel DTO opcional.
        // has_value  = verifica se tem valor
        if (existe_hotel.has_value()) {
            vector<HotelDTO> lista;
            lista.push_back(*existe_hotel);

            // 1. CABEÇALHOS
            vector<string> titulosTabela = {"Id", "Nome", "Endereco", "Telefone", "Codigo"};

            // 2. DADOS (Iterar sobre listaGerentes e extrair)
            vector<vector<string> > dadosTabela;
            for (const HotelDTO &g: lista) {
                dadosTabela.push_back({
                    to_string(g.getId()),
                    g.getNome(),
                    g.getEndereco(),
                    g.getTelefone(),
                    g.getCodigo()
                });
            }
            // 3. CHAMADA GENÉRICA
            ConsoleFormatter::MostrarTabelaGenerica("Hotel", titulosTabela, dadosTabela);
        }else {
            ConsoleIO::PrintMensagem("Erro: Hotel nao encontrado");
        }

    }else {
        ConsoleIO::PrintMensagem("Erro: Id Invalido");
    }
}

bool ControladorInterfaceHotel::remover() {
}