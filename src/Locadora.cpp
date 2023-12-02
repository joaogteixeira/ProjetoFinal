#include "Locadora.hpp"
#include <algorithm>

void Locadora::cadastrarFilme(int codigo, const std::string& titulo, double preco, int quantidadeEstoque) {
  try {
      filmes.emplace_back(codigo, titulo, preco, quantidadeEstoque);
  } catch (const std::invalid_argument& e) {
      std::cerr << "Erro ao cadastrar filme: " << e.what() << std::endl;
  }
}

void Locadora::cadastrarCliente(const std::string& cpf, const std::string& nome) {
  try {
          clientes.emplace_back(cpf, nome);
      } catch (const std::invalid_argument& e) {
          std::cerr << "Erro ao cadastrar cliente: " << e.what() << std::endl;
      }
  }


void Locadora::visualizarFilmesDisponiveis() const {
    std::cout << "\nFilmes Disponíveis:\n";
    for (const Filme& filme : filmes) {
        filme.imprimir();
    }
}

void Locadora::alugarFilme(const std::string& cpf, int codigo) {
  try {
       auto clientIt = std::find_if(clientes.begin(), clientes.end(),
        [cpf](const Cliente& cliente) { return cliente.cpf == cpf; });

    auto filmIt = std::find_if(filmes.begin(), filmes.end(),
        [codigo](const Filme& filme) { return filme.codigo == codigo; });

    if (clientIt != clientes.end() && filmIt != filmes.end()) {
        Cliente& cliente = *clientIt;
        Filme& filme = *filmIt;

        if (cliente.saldo >= filme.preco) {
            cliente.saldo -= filme.preco;

            filmesAlugados[cpf].push_back(codigo);

            filme.quantidadeEstoque--;

            std::cout << "Filme alugado com sucesso!\n";
        } else {
            std::cout << "Saldo insuficiente. Não é possível alugar o filme.\n";
        }
    } else {
        std::cout << "Cliente ou filme não encontrado.\n";
    }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Erro ao alugar filme: " << e.what() << std::endl;
    }
}

void Locadora::devolverFilme(const std::string& cpf) {
    if (filmesAlugados.find(cpf) != filmesAlugados.end() && !filmesAlugados[cpf].empty()) {
        int codigo = filmesAlugados[cpf].back();
        for (Filme& filme : filmes) {
            if (filme.codigo == codigo) {
                filme.quantidadeEstoque++;
                filmesAlugados[cpf].pop_back();
                std::cout << "Filme devolvido com sucesso!\n";
                return;
            }
        }
    }
    std::cout << "Nenhum filme para devolver.\n";
}

void Locadora::depositarDinheiro(const std::string& cpf, double valor) {
    for (Cliente& cliente : clientes) {
        if (cliente.cpf == cpf) {
            cliente.saldo += valor;
            std::cout << "Depósito realizado com sucesso!\n";
            return;
        }
    }
    std::cout << "Cliente não encontrado.\n";
}

void Locadora::salvarEmArquivo() const {
    std::ofstream arquivoFilmes("filmes.txt");
    for (const Filme& filme : filmes) {
        arquivoFilmes << filme.codigo << ' ' << filme.titulo << ' ' << filme.preco << ' ' << filme.quantidadeEstoque << '\n';
    }

    std::ofstream arquivoClientes("clientes.txt");
    for (const Cliente& cliente : clientes) {
        arquivoClientes << cliente.cpf << ' ' << cliente.nome << ' ' << cliente.saldo << '\n';
    }
}
