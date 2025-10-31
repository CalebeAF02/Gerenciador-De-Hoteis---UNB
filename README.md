# 🏨 Gerenciador de Hotel - UnB

Projeto acadêmico em **C++**, desenvolvido na Universidade de Brasília (UnB), com foco em **Programação Orientada a
Objetos (POO)** e persistência de dados com **SQLite**.

O sistema simula um **gerenciador de hotel**, permitindo:

- Cadastro e login de **hóspedes** e **gerentes**
- Registro e gerenciamento de **quartos**, **reservas** e **hotéis**
- Validação de dados diretamente nas classes de domínio
- Navegação por menus interativos via **interface de terminal (CLI)**

---

## 🚀 Atualizações Recentes

- ✅ Interface de terminal funcional com menus dinâmicos
- ✅ Persistência com SQLite (`hotel.db`)
- ✅ Criação, login, leitura e exclusão de gerentes
- ✅ Fluxo completo para hóspedes com opções de hospedagem
- ✅ Validação embutida nos domínios com tratamento de exceções
- ✅ Remoção das classes de validação externas (`validadores_abstratos`)
- 🔄 Função de atualização de gerente em desenvolvimento

---

## 🧭 Linha do Tempo de Funcionalidades

| Etapa | Funcionalidade      | Descrição                                            |
|-------|---------------------|------------------------------------------------------|
| 1️⃣   | Tela Inicial        | Escolha entre gerente ou hóspede                     |
| 2️⃣   | Acesso como Gerente | Menu com opções de criar, logar e gerenciar          |
| 3️⃣   | Criar Gerente       | Cadastro com validação de nome, email, ramal e senha |
| 4️⃣   | Login de Gerente    | Verificação no banco com feedback de sucesso ou erro |
| 5️⃣   | Central de Serviços | Acesso às operações CRUD de gerentes                 |
| 6️⃣   | Ler Gerentes        | Listagem formatada dos gerentes cadastrados          |
| 7️⃣   | Remover Gerente     | Exclusão por email com confirmação                   |
| 8️⃣   | Acesso como Hóspede | Menu com opções de hospedagem e status               |
| 9️⃣   | Criar Solicitação   | Interface para registrar interesse em hospedagem     |
| 🔟    | Ver Status          | Consulta ao status da solicitação feita              |
| 🔜    | Atualizar Gerente   | (Em desenvolvimento) Edição de dados do gerente      |

---

## 📸 Exemplos Visuais da Interface

### 🏁 Tela Inicial do Sistema

![Tela de boas-vindas com opções de acesso](imagens/tela_inicial.png)

### 🛏️ Menu para Hospedagem

![Menu para hospedagem com opções de solicitação e status](imagens/menu_hospedagem.png)

### 🧑‍💼 Menu Inicial do Gerente

![Opções de criar gerente ou fazer login](imagens/menu_inicial_gerente.png)

### ❌ Tentativa de Login com Erro

![Erro de login: usuário não encontrado ou senha incorreta](imagens/login_erro.png)

### 👤 Cadastro de Novo Gerente
![Cadastro de gerente com nome, email, ramal e senha](imagens/cadastro_gerente.png)

### 🔐 Login de Gerente com Sucesso

![Login realizado com sucesso e acesso à central de serviços](imagens/login_sucesso_menu_servicos.png)

### 🧠 Central de Serviços

![Menu principal após login, com acesso aos módulos do sistema](imagens/central_servicos.png)

### 🧭 Menu CRUD de Gerentes

![Central de serviços com opções de criar, ler, atualizar e remover](imagens/menu_crud_gerente.png)

### 📋 Lista de Gerentes

![Exibição dos gerentes cadastrados](imagens/lista_gerentes.png)

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
│ │ └── sqlite3.h
│ ├── extern/
│ │ └── libsqlite3.a
├── tests/
├── imagens/
├── README.md

---

## 🔹 Validação Embutida nos Domínios

A validação de dados agora é feita diretamente dentro das classes de domínio. Cada classe é responsável por garantir sua
própria integridade, lançando exceções (`std::invalid_argument`) quando os dados são inválidos.

Exemplos:

Nome nome("Calebe"); // válido  
Email email("email@invalido"); // lança exceção  
Senha senha("123"); // lança exceção se não atender aos critérios

### 🔹 Utilitários Genéricos

Algumas validações genéricas ainda são mantidas para entradas livres:

- ValidarString → valida strings genéricas (menus, comandos)
- ValidarInt → valida inteiros fora dos domínios

---

## 🧪 Testes

- TesteValidadores: conjunto de testes unitários para verificar os domínios
- Contadores estáticos para monitorar execução:
- contTotalTestes
- contTotalTestesOk
- contTotalTestesProblema

---

## 🛠️ Como Compilar

mkdir build && cd build  
cmake ..  
make  
./gerenciador_hotel_unb

✅ Este projeto já inclui o SQLite como biblioteca estática:

- libs/sqlite/sqlite3.h → cabeçalho da API
- libs/extern/libsqlite3.a → biblioteca compilada
  Nenhuma instalação externa é necessária. Basta clonar e compilar.

---

## 🤝 Como Contribuir

Se você deseja colaborar com o projeto, siga estas etapas:

1. Clone o repositório :
   git clone https://github.com/CalebeAF02/Gerenciador-De-Hoteis---UNB.git
   cd Gerenciador-De-Hoteis---UNB

2. Crie uma branch :

   git checkout -b nome-da-sua-branch

3. Compile e teste localmente :

   mkdir build && cd build
   cmake ..
   make

4. Commit e push :

   git add .
   git commit -m "feat: descrição clara da funcionalidade"
   git push origin nome-da-sua-branch

5. Abra um Pull Request no GitHub

---

## 📚 Próximos Passos

- Finalizar função de atualização de gerente
- Implementar persistência para hóspedes e solicitações
- Criar exportação de dados para .tsv ou .csv
- Ampliar cobertura dos testes
- Migrar para interface gráfica (Qt ou Web)

---

##🎯 Objetivo Educacional

Este projeto visa aplicar conceitos de POO em C++ moderno, com foco em:

- Herança e Polimorfismo
- Encapsulamento
- Tratamento de exceções
- Arquitetura limpa e boas práticas
- Persistência com banco de dados

---

##👤 Autores

Projeto desenvolvido por:

- [Calebe Alves](https://github.com/CalebeAF02) — Universidade de Brasília (UnB)
- [Artur Silva](https://github.com/TUTUBOY-PRO) — Universidade de Brasília (UnB)

📎 Repositorio: https://github.com/CalebeAF02/gerenciador_hotel_unb

---
