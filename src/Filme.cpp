#include "Filme.hpp"

Filme::Filme(int codigo, const std::string& titulo, double preco, int quantidadeEstoque)
    : codigo(codigo), titulo(titulo), preco(preco), quantidadeEstoque(quantidadeEstoque) {}

void Filme::imprimir() const {
    std::cout << "Código: " << codigo << ", Título: " << titulo << ", Preço: " << preco << ", Estoque: " << quantidadeEstoque << std::endl;
}
