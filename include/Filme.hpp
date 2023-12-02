#ifndef FILME_HPP
#define FILME_HPP

#include <iostream>
#include <fstream>

class Filme {
public:
    int codigo;
    std::string titulo;
    double preco;
    int quantidadeEstoque;

    Filme(int codigo, const std::string& titulo, double preco, int quantidadeEstoque);

    void imprimir() const;
};

#endif
