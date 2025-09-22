# Gerenciador de Hotel - UnB

Este é um projeto acadêmico desenvolvido em C++ com foco em **Programação Orientada a Objetos (POO)**.  
Seu objetivo é simular um sistema de **gerenciamento de hotel**, permitindo o cadastro de pessoas, quartos e reservas, 
além da validação de dados por meio de classes especializadas.

---

## 🚀 Estrutura do Projeto

### 1. Classes de Entidades
- **Pessoa**: Representa hóspedes ou funcionários.  
  - Atributos principais: `nome`, `cpf`.  
  - Métodos de validação: `validarNome()`, `validarCpf()`.  
  - Regras:
    - Nome não pode ser vazio ou conter caracteres inválidos.
    - CPF deve seguir um formato válido.

- **Quarto**: Representa um quarto do hotel.  
  - Atributos principais: `numero`, `capacidade`, `preco`.  
  - Métodos de validação herdados de `ValidarInt`.  
  - Regras:
    - O número do quarto deve ser positivo.
    - Capacidade deve ser maior que zero.
    - Preço precisa ser um valor monetário válido.

- **Reserva**: Representa uma reserva feita no hotel.  
  - Atributos principais: `codigo`, `dataChegada`, `dataPartida`, `valor`.  
  - Métodos de validação: `validarChegada()`, `validarPartida()`, `validar(int, string)`, `validar(int, int)`.  
  - Regras:
    - Código deve ser único.
    - Datas precisam ser válidas (chegada < partida).
    - Valor deve ser positivo.

---

### 2. Classes de Validação
- **ValidarInt** (classe abstrata): Interface base para validadores de inteiros.  
- **ValidarCodigo**: Garante que o código da reserva segue o padrão esperado.  
- **ValidarDinheiro**: Valida valores monetários (ex: não permitir valores negativos).  
- **ValidarNome**: Usado pela classe `Pessoa` para verificar integridade do nome.  

Cada classe lança exceções (`std::invalid_argument`) em caso de erro.

---

### 3. Classe de Testes
- **TesteValidadores**: Conjunto de testes unitários para verificar os validadores.  
- Contadores estáticos:
  - `contTotalTestes`
  - `contTotalTestesOk`
  - `contTotalTestesProblema`

Isso permite acompanhar a cobertura e a confiabilidade do sistema.

---

## 📌 Status do Desenvolvimento

- ✅ **Classe Pessoa**: implementada com `validarNome()` e `validarCpf()`.  
- ✅ **Classe Quarto**: implementada herdando de `ValidarInt`.  
- ✅ **Classe Reserva**: implementada com múltiplos validadores.  
- ✅ **Validações gerais**: `ValidarInt`, `ValidarCodigo`, `ValidarDinheiro`, `ValidarNome`.  
- ✅ **Sistema de testes**: implementado parcialmente.  
- 🔄 **Integração entre classes**: em desenvolvimento.  
- ⏳ **Interface de usuário (CLI/GUI)**: não implementada.  

---

## 🛠️ Como Compilar

```bash
g++ -std=c++17 -Wall -Wextra -o gerenciador main.cpp Pessoa.cpp Quarto.cpp Reserva.cpp TesteValidadores.cpp
```

---

## 📚 Próximos Passos

1. Finalizar integração entre **Reserva** e **Pessoa**.  
2. Implementar associação entre **Reserva** e **Quarto**.  
3. Ampliar a suíte de testes.  
4. Criar uma interface simples para interação com o usuário.  

---

## ✨ Objetivo Educacional

Este projeto tem como principal finalidade **aprimorar os conceitos de POO**, como:  
- Herança e Polimorfismo.  
- Encapsulamento.  
- Tratamento de exceções.  
- Boas práticas em C++ moderno.  

---

## 📌 Autor

Projeto desenvolvido por **Calebe Alves** - Universidade de Brasília (UnB).  
Repositório: [GitHub - Gerenciador Hotel UnB](https://github.com/CalebeAF02/gerenciador_hotel_unb)
