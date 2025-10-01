# 🏨 Gerenciador de Hotel - UnB

Projeto acadêmico em **C++**, desenvolvido na Universidade de Brasília (UnB), com foco em **Programação Orientada a
Objetos (POO)**.

O sistema simula um **gerenciador de hotel**, permitindo:

- Cadastro de hóspedes, gerentes e funcionários.
- Registro de quartos e reservas.
- Validação de dados através de **classes especializadas**.

---

## 🚀 Estrutura do Projeto

### 🔹 1. Classes de Entidades

- **Pessoa** (classe base):
    - Atributos: `nome`, `email`.
    - Regras:
        - Nome não pode ser vazio ou inválido.
        - Email deve seguir o formato válido.

- **Gerente** (herda de Pessoa):
    - Atributos adicionais: `ramal`, `senha`.
    - Regras:
        - Ramal e senha devem ser válidos.

- **Hospede** (herda de Pessoa):
    - Atributos adicionais: `endereco`, `cartao`.
    - Regras:
        - Endereco deve ter entre 5 e 30 caracteres.
        - Cartao deve ter 16 caracteres.
-
- **Hotel**:
    - Atributos: `nome`, `endereco`, `telefone`, `codigo`.
    - Regras:
        - Nome não pode ser vazio.
        - Quantidade de quartos > 0.
        - Telefone deve ter DDD válido.
        - Codigo deve ter 10 caracteres.


- **Quarto**:
    - Atributos: `numero`, `capacidade`, `dinheiro`, `ramal`.
    - Regras:
        - Número > 0.
        - Capacidade > 0.
        - Dinheiro > 0.
        - Ramal > 0.

- **Reserva**:
    - Atributos: `dataChegada`, `dataPartida`, `dinheiro`, `codigo`.
    - Regras:
        - Chegada < partida.
        - dinheiro > 0.
        - Código deve ser único.


- **Data** (classe utilitária):
    - Atributos: `dia`, `mes`, `ano`.
    - Regras:
        - Datas devem ser válidas (ex.: 31/02 inválido).

---

### 🔹 2. Classes de Validação

- **ValidarString** → valida strings genéricas.
- **ValidarInt** → valida inteiros.
- **ValidarNome** → usado por `Gerente`, `Hospede`.
- **ValidarEmail** → usado por `Gerente`, `Hospede`.
- **ValidarEndereco** → usado por `Hospede`, `Hotel`.
- **ValidarDinheiro** → valida `Dinheiro`.
- **ValidarCodigo** → valida `Codigos`, `Reservas`.
- **ValidarRamal** → valida ramais internos uados por `Gerente`, `Quarto`.

⚠️ Todas as validações lançam exceções (`std::invalid_argument`) em caso de erro.

---

### 🔹 3. Testes

- **TesteValidadores**: conjunto de testes unitários para verificar os validadores.
- Contadores estáticos para monitorar execução:
    - `contTotalTestes`
    - `contTotalTestesOk`
    - `contTotalTestesProblema`

---

## 📌 Status do Projeto

- ✅ Classe `Pessoa` implementada.
- ✅ Classes `Gerente`, `Hospede` implementadas.
- ✅ Classes `Hotel`, `Quarto`, `Reserva` implementadas.
- ✅ Validadores principais finalizados.
- ✅ Testes básicos implementados.
- 🔄 Integração entre **Reserva**, **Hospede** e **Quarto** (em andamento).
- ⏳ Interface de usuário (CLI/GUI) ainda não implementada.

---

## 🛠️ Como Compilar

```bash
g++ -std=c++20 -Wall -Wextra -o gerenciador main.cpp Pessoa.cpp Quarto.cpp Reserva.cpp TesteValidadores.cpp
```

---

## 📚 Próximos Passos

1. Finalizar integração entre **Reserva** ↔ **Pessoa**.
2. Implementar associação **Reserva** ↔ **Quarto**.
3. Ampliar cobertura dos testes.
4. Criar interface simples (CLI/GUI).

---

## 🎯 Objetivo Educacional

Este projeto visa aplicar conceitos de **POO em C++ moderno**, com foco em:

- Herança e Polimorfismo.
- Encapsulamento.
- Tratamento de exceções.
- Arquitetura limpa e boas práticas.

---

## 👤 Autor

Projeto desenvolvido por **Calebe Alves** - Universidade de Brasília (UnB).  
📎 Repositório: [GitHub - Gerenciador Hotel UnB](https://github.com/CalebeAF02/gerenciador_hotel_unb)  
