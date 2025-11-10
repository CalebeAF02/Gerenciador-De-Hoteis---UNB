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

    this->executando = true;

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
            ConsoleIO::PrintMenssagem("Opcao Invalida!");
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
                ConsoleIO::SubPergunta("Informe o Nome: ");
                string valor = ConsoleIO::LerLinha();
                try {
                    hotel->setNome(Nome(valor));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                ConsoleIO::SubPergunta("Informe o Endereco: ");
                string valor = ConsoleIO::LerLinha();
                try {
                    hotel->setEndereco(Endereco(valor));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                ConsoleIO::SubPergunta("Informe o Telefone: ");
                string valor = ConsoleIO::LerLinha();
                try {
                    hotel->setTelefone(Telefone(valor));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                ConsoleIO::SubPergunta("Informe o Codigo: ");
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
                    ConsoleIO::PrintMenssagem("Hotel Cadastrado!");
                } else {
                    ConsoleIO::PrintMenssagem("Erro ao cadastrar hotel no banco!");
                    break;
                }
            } else {
                ConsoleIO::PrintMenssagem("Erro: Hotel nao cadastrado!");
                break;
            }
            delete hotel; // Liberar o ponteiro da memoria.
        }
    }
};

void ControladorInterfaceHotel::ler() {
    vector<HotelDTO *> lista = persistencia.listar();

    if (lista.empty()) {
        ConsoleIO::PrintMenssagem("Nenhum gerente cadastrado.");
        return;
    }
    Tabela tab;

    for (HotelDTO *item: lista) {
        Linha *objLinha = tab.criarObj();

        objLinha->atributo("id", item->getId());
        objLinha->atributo("Nome", item->getNome());
        objLinha->atributo("Endereco", item->getEndereco());
        objLinha->atributo("Telefone", item->getTelefone());
        objLinha->atributo("Codigo", item->getCodigo());
    }

    tab.exibirTabela("Lista De Hoteis");
}

void ControladorInterfaceHotel::atualizar() {
    ConsoleIO::SubPergunta("Informe o Id do hotel: ");
    string id_hotel = ConsoleIO::LerLinha();

    if (ValidadorNumerico::verificaSeENumero(id_hotel)) {
        PersistenciaHotel persistencia;
        bool alterado = false;

        int id_numero = stoi(id_hotel);
        optional<HotelDTO> existe_hotel = persistencia.buscaHotelPorID(id_numero);
        // transforma a string em numero e verica no banco, retornando um Hotel DTO opcional.
        // has_value  = verifica se tem valor
        if (existe_hotel.has_value()) {
            Tabela tab;
            vector<HotelDTO> lista;
            lista.push_back(*existe_hotel);

            for (HotelDTO item: lista) {
                Linha *objLinha = tab.criarObj();

                objLinha->atributo("Id", item.getId());
                objLinha->atributo("Nome", item.getNome());
                objLinha->atributo("Endereco", item.getEndereco());
                objLinha->atributo("Telefone", item.getTelefone());
                objLinha->atributo("Codigo", item.getCodigo());
            }

            tab.exibirTabela("Lista De Hoteis");

            // Perguntas para o usuario
            Hotel hotel(*existe_hotel); // Construtor em Hotel, para HotelDTO

            Menu menu;

            const int OPCAO_ALTERAR_NOME = menu.adcionarItens("Alterar Nome");
            const int OPCAO_ALTERAR_ENDERECO = menu.adcionarItens("Alterar Endereco");
            const int OPCAO_ALTERAR_TELEFONE = menu.adcionarItens("Alterar Telefone");
            const int OPCAO_ALTERAR_CODIGO = menu.adcionarItens("Alterar Codigo");
            const int OPCAO_VOLTAR_AO_SISTEMA = menu.adcionarItens("Voltar");

            int opcao = menu.executa("Atualizacao de Cadastro");

            if (opcao == OPCAO_ALTERAR_NOME) {
                ConsoleIO::SubPergunta("Novo nome: ");
                string valor = ConsoleIO::LerLinha();
                try {
                    hotel.setNome(Nome(valor));
                    alterado = true;
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                }
            } else if (opcao == OPCAO_ALTERAR_ENDERECO) {
                ConsoleIO::SubPergunta("Novo Endereco: ");
                string valor = ConsoleIO::LerLinha();
                try {
                    hotel.setEndereco(Endereco(valor));
                    alterado = true;
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                }
            } else if (opcao == OPCAO_ALTERAR_TELEFONE) {
                ConsoleIO::SubPergunta("Novo Telefone: ");
                string valor = ConsoleIO::LerLinha();
                try {
                    hotel.setTelefone(Telefone(valor));
                    alterado = true;
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                }
            } else if (opcao == OPCAO_ALTERAR_CODIGO) {
                ConsoleIO::SubPergunta("Novo Codigo: ");
                string valor = ConsoleIO::LerLinha();
                try {
                    hotel.setCodigo(Codigo(valor));
                    alterado = true;
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                }
            } else if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
                ConsoleIO::PrintMenssagem("Atualizacao cancelada.");
            } else {
                ConsoleIO::PrintMenssagem("Opcao invalida.");
            }


            if (alterado) {
                PersistenciaHotel persistencia;
                bool sucesso = persistencia.atualizar(id_numero, hotel);
                if (sucesso) {
                    ConsoleIO::PrintMenssagem("Hotel Atualizado!");
                } else {
                    ConsoleIO::PrintMenssagem("Erro ao atualizar hotel no banco!");
                }
            }
        } else {
            ConsoleIO::PrintMenssagem("Erro: Hotel nao encontrado");
        }
    } else {
        ConsoleIO::PrintMenssagem("Erro: Id Invalido");
    }
}

bool ControladorInterfaceHotel::remover() {
}