# README.md

# Projeto de Avaliação de Expressões

Este projeto implementa uma estrutura para avaliação de expressões matemáticas utilizando uma árvore de nós. O projeto é composto por classes que representam diferentes tipos de nós, incluindo operadores binários e literais numéricos.

## Estrutura do Projeto

- **src/**
  - `AbstractNode.h`: Define a classe abstrata `AbstractNode`, que serve como base para outros tipos de nós.
  - `BinaryOperatorNode.h`: Define a classe `BinaryOperatorNode`, que representa um operador binário.
  - `BinaryOperatorNode.cpp`: Implementa a lógica da classe `BinaryOperatorNode`.
  - `LiteralNode.h`: Define a classe `LiteralNode`, que representa um literal numérico.
  - `LiteralNode.cpp`: Implementa a lógica da classe `LiteralNode`.
  - `main.cpp`: Ponto de entrada do programa, onde as instâncias de nós são criadas e avaliadas.

## Compilação e Execução

Para compilar e executar o projeto, siga os passos abaixo:

1. Certifique-se de ter o CMake instalado em seu sistema.
2. Navegue até o diretório do projeto:
   ```bash
   cd cpp-project
   ```
3. Crie um diretório de build e navegue até ele:
   ```bash
   mkdir build
   cd build
   ```
4. Execute o CMake para configurar o projeto:
   ```bash
   cmake ..
   ```
5. Compile o projeto:
   ```bash
   make
   ```
6. Execute o programa:
   ```bash
   ./cpp-project
   ```

## Descrição

Este projeto permite a criação de expressões matemáticas utilizando uma árvore de nós, onde cada nó pode ser um operador binário ou um literal. A avaliação das expressões é realizada através da implementação do método `evaluate()` em cada classe derivada.

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou pull requests para melhorias e correções.