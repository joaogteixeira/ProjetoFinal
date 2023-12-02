#include <iostream>
#include <limits>  
#include "Locadora.hpp"

int main() {
    Locadora locadora;
    int opcao;

    do {
        std::cout << "\n===== Locadora de Filmes =====\n";
        std::cout << "1. Cadastrar Filme\n";
        std::cout << "2. Cadastrar Cliente\n";
        std::cout << "3. Visualizar Filmes Disponíveis\n";
        std::cout << "4. Alugar Filme\n";
        std::cout << "5. Devolver Filme\n";
        std::cout << "6. Depositar Dinheiro\n";
        std::cout << "7. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                int codigo;
                std::string titulo;
                double preco;
                int quantidadeEstoque;

                std::cout << "Digite o código do filme: ";
                std::cin >> codigo;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

                std::cout << "Digite o título do filme: ";
                std::getline(std::cin, titulo);

                std::cout << "Digite o preço do filme: ";
                std::cin >> preco;

                std::cout << "Digite a quantidade em estoque: ";
                std::cin >> quantidadeEstoque;

                locadora.cadastrarFilme(codigo, titulo, preco, quantidadeEstoque);
                break;
            }
            case 2: {
                std::string cpf, nome;
                std::cout << "Digite o CPF do cliente: ";
                std::cin >> cpf;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

                std::cout << "Digite o nome do cliente: ";
                std::getline(std::cin, nome);

                locadora.cadastrarCliente(cpf, nome);
                break;
            }
            case 3:
                locadora.visualizarFilmesDisponiveis();
                break;
            case 4: {
                std::string cpf;
                int codigo;

                std::cout << "Digite o CPF do cliente: ";
                std::cin >> cpf;
                std::cout << "Digite o código do filme: ";
                std::cin >> codigo;

                locadora.alugarFilme(cpf, codigo);
                break;
            }
            case 5: {
                std::string cpf;
                std::cout << "Digite o CPF do cliente: ";
                std::cin >> cpf;
                locadora.devolverFilme(cpf);
                break;
            }
            case 6: {
                std::string cpf;
                double valor;
                std::cout << "Digite o CPF do cliente: ";
                std::cin >> cpf;
                std::cout << "Digite o valor a ser depositado: ";
                std::cin >> valor;
                locadora.depositarDinheiro(cpf, valor);
                break;
            }
            case 7:
                locadora.salvarEmArquivo();
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 7);

    return 0;
}
