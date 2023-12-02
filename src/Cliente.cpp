#include "Cliente.hpp"

Cliente::Cliente(const std::string& cpf, const std::string& nome)
    : cpf(cpf), nome(nome), saldo(0.0) {}

void Cliente::imprimir() const {
    std::cout << "CPF: " << cpf << ", Nome: " << nome << ", Saldo: " << saldo << std::endl;
}
