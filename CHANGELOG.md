# Changelog

Todas as mudanças notáveis neste projeto serão documentadas aqui.

Este projeto segue o formato [Keep a Changelog](https://keepachangelog.com/pt-BR/1.0.0/) e [Semantic Versioning](https://semver.org/lang/pt-BR/).

---

## [Unreleased]

### 2025-09-20
- Início do projeto.
- Criação da estrutura de testes.
- Implementação da classe `Reserva`.
- Testes de validação: Endereço, Senha, Cartão, Telefone.

### 2025-09-21
- Implementação completa da classe `Reserva`.
- Criação de todos os validadores.
- Início dos testes automatizados.

### 2025-09-22
- Criação do arquivo `README.md`.
- Correções nos atributos da classe `Reserva`.
- Ajustes em testes de validadores.

### 2025-09-23
- Atualizações em validações: Senha, Ramal, Cartão, Telefone, Endereço.
- Correções em testes.
- Tentativas de resolver erros de commit.

### 2025-09-24
- Refatoração dos validadores.
- Atualização do `README.md`.
- Mudança de métodos `virtual` para `static`.

### 2025-09-25
- Organização das pastas.
- Correção de bug relacionado à conta antiga.

### 2025-09-26
- Padronização da estrutura de arquivos.
- Organização do projeto em estilo profissional.

### 2025-09-27
- Refatoração de includes, defines e testes.
- Criação do objeto `Gerente`.

### 2025-09-28
- Criação da pasta `Sistema`.
- Implementação dos métodos `menuSistema`, `fazerLogin`, `exibirCentralDeServicos`.
- Criação da classe abstrata `linhaTSV`.

### 2025-09-30
- Confirmação inicial da estrutura no repositório.

### 2025-10-01
- Refatoração das classes `Pessoa`, `Gerente`, `Hospede`, `Nome`, `Email`.
- Validação incorporada nas classes de domínio.
- Reorganização do projeto conforme documentação.

### 2025-10-02
- Exclusão do diretório `cmake-build-debug`.

### 2025-10-07
- Atualizações em aulas e criação de objetos.

### 2025-10-08
- Atualização da classe `Reserva` com lógica de anos bissextos.

### 2025-10-11
- Criação do sistema de serviços para `Gerente` e `Hospede`.

### 2025-10-12
- Refatoração de entradas e saídas nos serviços.

### 2025-10-16
- Implementação de fábricas para `Pessoa`, `Gerente` e `Hospede`.

### 2025-10-17
- Criação do fluxo de autenticação de gerente com login e menu CRUD protegido.

### 2025-10-19
- Integração da biblioteca SQLite ao projeto.
- Criação da tabela `Gerente` no banco.

### 2025-10-20
- Atualização do `README.md` com imagens da interface.
- Organização visual e correção do fluxo de login.

### 2025-10-23
- Refatoração da `PersistenciaGerente`.
- Criação de todas as tabelas no banco SQLite.
- Correções no controle de retorno de métodos de persistência.

### 2025-10-26
- Refatoração dos Smoke Tests em testes únicos.
- Implementação de sistema de modelagem com interfaces e módulos.
- Novo sistema de autenticação de usuário.

### 2025-10-28
- Organização das massas de dados.
- Merge com versão finalizada do projeto anterior.

### 2025-10-29
- Reorganização completa das pastas e código.

### 2025-10-31
- Renomeação de `sqlite3.c` para `sqlite3.cpp`.
- Atualização do `CMakeLists.txt` para compilar corretamente o novo arquivo.