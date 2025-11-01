//
// Created by caleb on 10/10/2025.
//

#include "ControladorInterfaceHotel.h"

void ControladorInterfaceHotel::exibirMenu() {

}

void ControladorInterfaceHotel::exibirMenuCRUD() {
    Menu menu;

    const int OPCAO_VOLTAR_ANTERIOR = menu.adcionarItens("Voltar");
    const int OPCAO_CRIAR_HOTEL = menu.adcionarItens("Criar Hotel");

    bool executando = true;
    while (executando) {
        int opcao = menu.executa("Seja bem vindo a central de servicos");

        if (opcao == OPCAO_VOLTAR_ANTERIOR) {
            executando = false;
        } else if (opcao == OPCAO_CRIAR_HOTEL) {
            criar();
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
            //Preencher atribultos com validacao
            if (tudoOK == false) {
                cout << "\nRetornando...\n\n";
                break;
            }

            TextoApresentacao::MostrarTituloEmCaixa("Criando Novo Hotel");
            if (tudoOK) {
                cout << "Informe o Nome: \n";
                string valor = TextoApresentacao::LerLinha();
                try {
                    hotel->setNome(Nome(valor));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                cout << "Informe o Endereco: \n";
                string valor = TextoApresentacao::LerLinha();
                try {
                    hotel->setEndereco(Endereco(valor));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                cout << "Informe o Telefone: \n";
                string valor = TextoApresentacao::LerLinha();
                try {
                    hotel->setTelefone(Telefone(valor));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                cout << "Informe o Codigo: \n";
                string valor = TextoApresentacao::LerLinha();
                try {
                    hotel->setCodigo(Codigo(valor));
                } catch (invalid_argument &erro) {
                    cout << erro.what() << endl;
                    tudoOK = false;
                }
            }
            if (tudoOK) {
                PersistenciaHotel dao;
                bool sucesso = dao.inserirAoBD(hotel);

                if (sucesso) {
                    criado = true;
                    cout << "Hotel Cadastrado!\n";
                } else {
                    cout << "Erro ao cadastrar hotel no banco!\n";
                    cout << "Retornando ao menu de acesso...\n";
                    break;
                }
            } else {
                cout << "Ops* Hotel não cadastrado!\n";
                cout << "Retornando ao menu de acesso...\n";
                break;
            }
            delete hotel; // Liberar o ponteiro da memoria.
        }
    }
};

void ControladorInterfaceHotel::ler() {
}

void ControladorInterfaceHotel::atualizar() {
}

bool ControladorInterfaceHotel::remover() {
}

