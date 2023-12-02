#ifndef LOCADORA_HPP
#define LOCADORA_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "Filme.hpp"
#include "Cliente.hpp"

class Locadora {
private:
    std::vector<Filme> filmes;
    std::vector<Cliente> clientes;
    std::map<std::string, std::vector<int>> filmesAlugados;

public:
    void cadastrarFilme(int codigo, const std::string& titulo, double preco, int quantidadeEstoque);

    void cadastrarCliente(const std::string& cpf, const std::string& nome);

    void visualizarFilmesDisponiveis() const;

    void alugarFilme(const std::string& cpf, int codigo);

    void devolverFilme(const std::string& cpf);

    void depositarDinheiro(const std::string& cpf, double valor);

    void salvarEmArquivo() const;
};

#endif
