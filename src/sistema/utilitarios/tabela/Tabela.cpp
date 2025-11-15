//
// Created by caleb on 09/11/2025.
//

#include "../../../../include/sistema/utilitarios/tabela/Tabela.hpp"

#include "Formato.hpp"
#include "../../../../libs/IO/IO.hpp"
#include "TamanhoAtributo.hpp"

namespace VisualizadorDeTabela {
    Linha *Tabela::criarObj() {
        shared_ptr<Linha> linha = make_shared<Linha>();

        linhas.push_back(linha);
        return linha.get();
    }

    void Tabela::exibirTabela(string titulo) {
        if (linhas.empty()) {
            IO::Println("Nenhum dado para exibir.");
            return;
        }

        // Descobri o tamanho maximo da linha
        vector<TamanhoAtributo> colunas;
        for (shared_ptr<Linha> &linha: linhas) {
            for (shared_ptr<Atributo> atributo: linha->getAtributos()) {
                bool ja_existe = false;
                for (TamanhoAtributo &coluna: colunas) {
                    if (atributo->getNome() == coluna.getNome()) {
                        if (atributo->getValor().length() > coluna.getTamanho()) {
                            coluna.setTamanho(atributo->getValor().length());
                        }
                        ja_existe = true;
                        break;
                    }
                }
                if (!ja_existe) {
                    int tamanho = atributo->getNome().length();
                    if (atributo->getValor().length() > tamanho) {
                        tamanho = atributo->getValor().length();
                    }
                    colunas.push_back(TamanhoAtributo(atributo->getNome(), tamanho));
                }
            }
        }

        int larguraTotal = 0;
        for (TamanhoAtributo coluna: colunas) {
            larguraTotal += coluna.getTamanho();
        }

        //Exibir Titulo da tabela
        int espco_titulo = larguraTotal + colunas.size() + (colunas.size() * 2);
        int espaco_entre = (espco_titulo - titulo.length()) / 2;
        Formato::RepetirCaracter(larguraTotal + colunas.size() + 1 + (colunas.size() * 2), '-');
        cout << "\n|";
        cout << Formato::RepetirCaracterMesmaLinha(espaco_entre, ' ') << titulo <<
                Formato::RepetirCaracterMesmaLinha(espaco_entre, ' ') << "|" << endl;
        Formato::RepetirCaracter(larguraTotal + colunas.size() + 1 + (colunas.size() * 2), '-');
        cout << "\n";

        //Exibir Cabeçalho
        string linha_cabecalho = "| ";
        for (TamanhoAtributo &coluna: colunas) {
            int falta_espacos = coluna.getTamanho() - coluna.getNome().length();
            linha_cabecalho += coluna.getNome();
            linha_cabecalho += Formato::RepetirCaracterMesmaLinha(falta_espacos, ' ');
            linha_cabecalho += " | ";
        }
        cout << linha_cabecalho << endl;
        Formato::RepetirCaracter(larguraTotal + colunas.size() + 1 + (colunas.size() * 2), '-');
        cout << "\n";

        // Exibir linha da tabela
        for (shared_ptr<Linha> &linha: linhas) {
            string linha_texto = "| ";
            for (shared_ptr<Atributo> atributo: linha->getAtributos()) {
                for (TamanhoAtributo &coluna: colunas) {
                    if (atributo->getNome() == coluna.getNome()) {
                        int falta_espacos = coluna.getTamanho() - atributo->getValor().length();
                        linha_texto += atributo->getValor();
                        linha_texto += Formato::RepetirCaracterMesmaLinha(falta_espacos, ' ');

                        linha_texto += " | ";
                        break;
                    }
                }
            }
            cout << linha_texto << endl;
        }
        Formato::RepetirCaracter(larguraTotal + colunas.size() + 1 + (colunas.size() * 2), '-');
        cout << "\n";
    };
}