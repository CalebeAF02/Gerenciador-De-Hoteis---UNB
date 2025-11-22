//
// Created by caleb on 14/11/2025.
//

#include "ControladoraApresentacaoHotel.hpp"

namespace Hotelaria {
    void ControladoraApresentacaoHotel::setControladoraServicoHotel(InterfaceServicoHotel *controladora_servico_hotel) {
        this->servico = controladora_servico_hotel;
    }

    void ControladoraApresentacaoHotel::exibirMenuCRUD() {
        bool executando = true;
        Menu menu;

        const int OPCAO_VOLTAR = menu.adcionarItens("Voltar ao Menu Anterior");
        const int OPCAO_CRIAR = menu.adcionarItens("Criar Novo Hotel");
        const int OPCAO_LISTAR = menu.adcionarItens("Listar Todos os Hoteis");
        const int OPCAO_ATUALIZAR = menu.adcionarItens("Atualizar Hotel (Editar)");
        const int OPCAO_REMOVER = menu.adcionarItens("Remover Hotel (Excluir)");

        while (executando) {
            int opcao = menu.executa("Gerenciamento de Hoteis (CRUD)");

            if (opcao == OPCAO_VOLTAR) {
                executando = false;
                IO::Println("Voltando ao menu de acesso.");
            } else if (opcao == OPCAO_CRIAR) {
                criar();
            } else if (opcao == OPCAO_LISTAR) {
                listar();
            } else if (opcao == OPCAO_ATUALIZAR) {
                atualizar();
            } else if (opcao == OPCAO_REMOVER) {
                remover();
            } else {
                IO::Println("Opcao Invalida! Tente novamente.");
            }
        }
    }

    void ControladoraApresentacaoHotel::criar() {
        bool criado = false;
        bool tudoOK = true;

        while (!criado) {
            Hotel *hotel = new Hotel();

            Formato::TituloEmCaixa("Criando Novo Hotel");
            if (tudoOK) {
                IO::Print("Informe o Nome: ");
                string valor = IO::LerLinha();
                try {
                    hotel->setNome(Nome(valor));
                } catch (invalid_argument &erro) {
                    IO::Println(erro.what());
                    tudoOK = false;
                    break;
                }
                if (tudoOK) {
                    IO::Print("Informe o Endereco: ");
                    string valor = IO::LerLinha();
                    try {
                        hotel->setEndereco(Endereco(valor));
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                        tudoOK = false;
                        break;
                    }
                }
                if (tudoOK) {
                    IO::Print("Informe o Telefone: ");
                    string valor = IO::LerLinha();
                    try {
                        hotel->setTelefone(Telefone(valor));
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                        tudoOK = false;
                        break;
                    }
                }
                if (tudoOK) {
                    IO::Print("Informe o Codigo: ");
                    string valor = IO::LerLinha();
                    try {
                        hotel->setCodigo(Codigo(valor));
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                        tudoOK = false;
                        break;
                    }
                }
                if (tudoOK) {
                    bool sucesso = servico->criar(*hotel);

                    if (sucesso) IO::Println("Hotel Cadastrado com Sucesso!");
                    else IO::Println("Falha ao cadastrar (Erro de Servico/Banco).");

                    criado = sucesso;
                }
                delete hotel;
            }
        }
    }

    void ControladoraApresentacaoHotel::listar() {
        vector<HotelDTO *> lista;

        if (lista.empty()) {
            IO::Println("Nenhum gerente cadastrado.");
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

    void ControladoraApresentacaoHotel::atualizar() {
        IO::Print("Informe o Id do hotel: ");
        string id_hotel = IO::LerLinha();

        if (Utils::verificaSeENumero(id_hotel)) {
            bool alterado = false;

            int id_numero = stoi(id_hotel);
            optional<HotelDTO> existe_hotel = servico->pesquisar(id_numero);
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
                    IO::Print("Novo nome: ");
                    string valor = IO::LerLinha();
                    try {
                        hotel.setNome(Nome(valor));
                        alterado = true;
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                    }
                } else if (opcao == OPCAO_ALTERAR_ENDERECO) {
                    IO::Print("Novo Endereco: ");
                    string valor = IO::LerLinha();
                    try {
                        hotel.setEndereco(Endereco(valor));
                        alterado = true;
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                    }
                } else if (opcao == OPCAO_ALTERAR_TELEFONE) {
                    IO::Print("Novo Telefone: ");
                    string valor = IO::LerLinha();
                    try {
                        hotel.setTelefone(Telefone(valor));
                        alterado = true;
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                    }
                } else if (opcao == OPCAO_ALTERAR_CODIGO) {
                    IO::Print("Novo Codigo: ");
                    string valor = IO::LerLinha();
                    try {
                        hotel.setCodigo(Codigo(valor));
                        alterado = true;
                    } catch (invalid_argument &erro) {
                        IO::Println(erro.what());
                    }
                } else if (opcao == OPCAO_VOLTAR_AO_SISTEMA) {
                    IO::Println("Atualizacao cancelada.");
                } else {
                    IO::Println("Opcao invalida.");
                }


                if (alterado) {
                    bool sucesso = servico->editar(id_numero, hotel);
                    if (sucesso) {
                        IO::Println("Hotel Atualizado!");
                    } else {
                        IO::Println("Erro ao atualizar hotel no banco!");
                    }
                }
            } else {
                IO::Println("Erro: Hotel nao encontrado");
            }
        } else {
            IO::Println("Erro: Id Invalido");
        }
    };

    void ControladoraApresentacaoHotel::remover() {
        IO::Println("\nEsta opcao ainda nao foi construida!\nRetornando...\n");
    };
}
