cmake_minimum_required(VERSION 3.10)

# Define o nome do projeto
project(CppProject)

# Adiciona o diretório src ao caminho de busca
include_directories(src)

# Adiciona os arquivos fonte ao executável
add_executable(CppProject
    src/main.cpp
    src/BinaryOperatorNode.cpp
    src/LiteralNode.cpp
)