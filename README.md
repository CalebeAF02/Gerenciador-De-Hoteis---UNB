# 🏨 Gerenciador de Hotel - UnB

Projeto academico em **C++**, desenvolvido na Universidade de Brasilia (UnB), com foco em **Programacao Orientada a
Objetos (POO)** e persistencia de dados com **SQLite**.

O sistema simula um **gerenciador de hotel**, permitindo:

- Cadastro e login de **hospedes** e **gerentes**
- Registro e gerenciamento de **quartos**, **reservas** e **hoteis**
- Validacao de dados diretamente nas classes de dominio
- Navegacao por menus interativos via **interface de terminal (CLI)**

---

## 🚀 Atualizacoes Recentes

- ✅ Interface de terminal funcional com menus dinâmicos
- ✅ Persistencia com SQLite (`hotel.db`)
- ✅ Criacao, login, leitura e exclusao de gerentes
- ✅ Fluxo completo para hospedes com opcoes de hospedagem
- ✅ Validacao embutida nos dominios com tratamento de excecoes
- ✅ Remocao das classes de validacao externas (`validadores_abstratos`)
- 🔄 Funcao de atualizacao de gerente em desenvolvimento

---

## 🧭 Linha do Tempo de Funcionalidades

| Etapa | Funcionalidade      | Descricao                                            |
|-------|---------------------|------------------------------------------------------|
| 1️⃣   | Tela Inicial        | Escolha entre gerente ou hospede                     |
| 2️⃣   | Acesso como Gerente | Menu com opcoes de criar, logar e gerenciar          |
| 3️⃣   | Criar Gerente       | Cadastro com validacao de nome, email, ramal e senha |
| 4️⃣   | Login de Gerente    | Verificacao no banco com feedback de sucesso ou erro |
| 5️⃣   | Central de Servicos | Acesso às operacoes CRUD de gerentes                 |
| 6️⃣   | Ler Gerentes        | Listagem formatada dos gerentes cadastrados          |
| 7️⃣   | Remover Gerente     | Exclusao por email com confirmacao                   |
| 8️⃣   | Acesso como Hospede | Menu com opcoes de hospedagem e status               |
| 9️⃣   | Criar Solicitacao   | Interface para registrar interesse em hospedagem     |
| 🔟    | Ver Status          | Consulta ao status da solicitacao feita              |
| 🔜    | Atualizar Gerente   | (Em desenvolvimento) Edicao de dados do gerente      |

---

## 📸 Exemplos Visuais da Interface

---

### 🏁 Tela Inicial do Sistema

![Tela de boas-vindas com opcoes de acesso](imagens/tela_inicial.png)

---

### 🛏️ Menu para Hospedagem

![Menu para hospedagem com opcoes de solicitacao e status](imagens/menu_hospedagem.png)

---

### 🧑‍💼 Menu Inicial do Gerente

![Opcoes de criar gerente ou fazer login](imagens/menu_inicial_gerente.png)

---

### ❌ Tentativa de Login com Erro

![Erro de login: usuario nao encontrado ou senha incorreta](imagens/login_erro.png)

---

### 👤 Cadastro de Novo Gerente

![Cadastro de gerente com nome, email, ramal e senha](imagens/cadastro_gerente.png)

---

### 🔐 Login de Gerente com Sucesso

![Login realizado com sucesso e acesso à central de servicos](imagens/login_sucesso_menu_servicos.png)

---

### 🧠 Central de Servicos

![Menu principal apos login, com acesso aos modulos do sistema](imagens/central_servicos.png)

---

### 🧭 Menu CRUD de Gerentes

![Central de servicos com opcoes de criar, ler, atualizar e remover](imagens/menu_crud_gerente.png)

---

### 📋 Lista de Gerentes

![Exibicao dos gerentes cadastrados](imagens/lista_gerentes.png)

---

## 📂 Estrutura do Projeto

├── include/
│ ├── entidades/
│ ├── dominios/
│ ├── sistema/
│ ├── utilitarios/
├── src/
│ ├── sistema/
│ ├── persistencias/
│ ├── servicos/
│ ├── entidades/
│ ├── dominios/
├── libs/
│ ├── sqlite/
│ ├── testes/
├── README.md

---

## 🔹 Validacao Embutida nos Dominios

A validacao de dados agora e feita diretamente dentro das classes de dominio. Cada classe e responsavel por garantir sua
propria integridade, lancando excecoes (`std::invalid_argument`) quando os dados sao invalidos.

Exemplos:
Nome nome("Calebe"); // valido  
Email email("email@invalido"); // lanca excecao  
Senha senha("123"); // lanca excecao se nao atender aos criterios

### 🔹 Utilitarios Genericos

Algumas validacoes genericas ainda sao mantidas para entradas livres:

- ValidarString → valida strings genericas (menus, comandos)
- ValidarInt → valida inteiros fora dos dominios

---

## 🧪 Testes

- TesteValidadores: conjunto de testes unitarios para verificar os dominios
- Contadores estaticos para monitorar execucao:
    - contTotalTestes
    - contTotalTestesOk
    - contTotalTestesProblema

---

## 🛠️ Como Compilar

mkdir build && cd build  
cmake ..  
make  
./gerenciador_hotel_unb

⚠️ Certifique-se de que o SQLite esta corretamente incluido no projeto (libs/sqlite/sqlite3.c)

---

## 📚 Proximos Passos

1. Finalizar funcao de atualizacao de gerente
2. Implementar persistencia para hospedes e solicitacoes
3. Criar exportacao de dados para .tsv ou .csv
4. Ampliar cobertura dos testes
5. Migrar para interface grafica (Qt ou Web)

---

## 🎯 Objetivo Educacional

Este projeto visa aplicar conceitos de **POO em C++ moderno**, com foco em:

- Heranca e Polimorfismo
- Encapsulamento
- Tratamento de excecoes
- Arquitetura limpa e boas praticas
- Persistencia com banco de dados

---

## 👤 Autor

Projeto desenvolvido por **Calebe Alves** — Universidade de Brasilia (UnB)  
📎 Repositorio: https://github.com/CalebeAF02/gerenciador_hotel_unb