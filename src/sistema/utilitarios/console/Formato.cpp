#include "Formato.hpp"

#include <algorithm>
#include <limits>

#include "IO.hpp"
//-----------------------------------------------------------------------------------------------------------
string Formato::RepetirCaracterMesmaLinha(int qntCaracteres, char c) {
    int i = 0;
    string temp = "";
    while (i < (qntCaracteres)) {
        temp += c;
        i++;
    }
    return temp;
};

void Formato::RepetirCaracter(int qntCaracteres, char c) {
    int i = 0;
    while (i < (qntCaracteres)) {
        cout << c;

        i++;
    }
};
//-----------------------------------------------------------------------------------------------------------
void Formato::TituloEmCaixa(const string &titulo) {
    const int LARGURA = 70; // Mais largo, ideal para o relatório de teste

    cout << "\n";
    RepetirCaracter(LARGURA, '=');
    cout << "\n";

    // Centralização
    int padding_total = LARGURA - titulo.length() - 2;
    int padding_esq = padding_total / 2;
    int padding_dir = padding_total - padding_esq;

    cout << "|";
    RepetirCaracter(padding_esq, ' ');
    cout << titulo;
    RepetirCaracter(padding_dir, ' ');
    cout << "|" << endl;

    RepetirCaracter(LARGURA, '=');
    cout << "\n";
};
//-----------------------------------------------------------------------------------------------------------
void Formato::SeparadorDeCategoria(const string &titulo) {
    const int LARGURA = 70; // Mais largo, ideal para o relatório de teste

    cout << "\n";
    RepetirCaracter(LARGURA, '-');
    cout << "\n";

    // Centralização
    int padding_total = LARGURA - titulo.length() - 2;
    int padding_esq = padding_total / 2;
    int padding_dir = padding_total - padding_esq;

    cout << "|";
    RepetirCaracter(padding_esq, ' ');
    cout << titulo;
    RepetirCaracter(padding_dir, ' ');
    cout << "|" << endl;

    RepetirCaracter(LARGURA, '-');
    cout << "\n";
};
//-----------------------------------------------------------------------------------------------------------
void Formato::OpcaoEmCaixa(const string &texto, const int &numero) {
    cout << "------------------------------\n";
    cout << "| [" << numero << "] " << texto << "\n";
    cout << "------------------------------\n";
};

void Formato::OpcaoEmCaixa(const string &texto, const string &numero) {
    cout << "------------------------------\n";
    cout << "| [" << numero << "] " << texto << "\n";
    cout << "------------------------------\n";
};
//-----------------------------------------------------------------------------------------------------------
void Formato::OpcaoSimples(const string &texto, const int &numero) {
    cout << "[" << numero << "] " << texto << "\n";
};
//-----------------------------------------------------------------------------------------------------------
void Formato::TabelaGenerica(
    const string &titulo,
    const vector<string> &titulosTabela,
    const vector<vector<string> > &dadosTabela
) {
    if (dadosTabela.empty()) {
        IO::Println("Nenhum dado para exibir.");
        return;
    }

    // O número de colunas é determinado pelo cabeçalho
    int numColunas = titulosTabela.size();
    if (numColunas == 0 || dadosTabela[0].size() != numColunas) {
        IO::Println("Erro: Headers e dados incompatíveis.");
        return;
    }

    // =======================================================
    // ETAPA 1: CALCULAR OS TAMANHOS MÁXIMOS
    // =======================================================
    vector<int> maxLarguras(numColunas);
    int margem = 2; // Margem de 2 espaços

    // Inicializa com o tamanho dos cabeçalhos
    for (int j = 0; j < numColunas; ++j) {
        maxLarguras[j] = titulosTabela[j].length();
    }

    // Itera sobre todos os dados para encontrar a largura máxima
    for (const vector<string> &linha: dadosTabela) {
        for (int j = 0; j < numColunas; ++j) {
            if (linha[j].length() > maxLarguras[j]) {
                maxLarguras[j] = linha[j].length();
            }
        }
    }

    // Adiciona a margem
    for (int j = 0; j < numColunas; ++j) {
        maxLarguras[j] += margem;
    }

    // Calcula o tamanho total da linha da tabela
    int larguraTotal = 0;
    for (int largura: maxLarguras) {
        larguraTotal += largura;
    }
    // Adiciona as bordas verticais ('|' no início, fim, e entre colunas)
    larguraTotal += (numColunas + 1);

    if (!titulo.empty()) {
        int espaco = ((larguraTotal - titulo.length()) / 2);
        RepetirCaracter(larguraTotal, '=');
        cout << "\n|";
        RepetirCaracter(espaco - 1, ' ');
        cout << titulo;
        RepetirCaracter(espaco - 1, ' ');
        cout << "|\n";
        RepetirCaracter(larguraTotal, '=');
    }


    // =======================================================
    // ETAPA 2: EXIBIR O CABEÇALHO
    // =======================================================

    cout << "\n|";

    for (int j = 0; j < numColunas; ++j) {
        cout << " " << titulosTabela[j]; // 1 espaço inicial
        // Completa com espaços brancos: largura total da coluna - (tamanho do header + 1 espaço inicial)
        RepetirCaracter(maxLarguras[j] - titulosTabela[j].length() - 1, ' ');
        cout << "|";
    }
    cout << "\n";

    RepetirCaracter(larguraTotal, '-');


    // =======================================================
    // ETAPA 3: EXIBIR OS DADOS
    // =======================================================

    for (const auto &linha: dadosTabela) {
        cout << "\n|";

        for (int j = 0; j < numColunas; ++j) {
            cout << " " << linha[j]; // 1 espaço inicial
            // Completa com espaços brancos: largura total da coluna - (tamanho do dado + 1 espaço inicial)
            RepetirCaracter(maxLarguras[j] - linha[j].length() - 1, ' ');
            cout << "|";
        }
    }
    cout << "\n";
    RepetirCaracter(larguraTotal, '-');
    cout << "\n";
};
//-----------------------------------------------------------------------------------------------------------