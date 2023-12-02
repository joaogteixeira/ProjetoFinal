#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <fstream>

class Cliente {
public:
    std::string cpf;
    std::string nome;
    double saldo;

    Cliente(const std::string& cpf, const std::string& nome);

    void imprimir() const;
};

#endif
