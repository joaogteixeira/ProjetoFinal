# ProjetoFinal 

Esse projeto final é um sistema de locadora virtual implementado em C++. utilizando conceitos aprendindo nas aulas de PROGRAMAÇÃO E DESENVOLVIMENTO DE SOFTWARE II

## Funcionalidades

1. **Cadastrar Filmes:**
   - Permite cadastrar novos filmes, incluindo informações como código, título, preço e quantidade em estoque.

2. **Cadastrar Clientes:**
   - Possibilita cadastrar novos clientes, informando o CPF e o nome.

3. **Visualizar Filmes Disponíveis:**
   - Exibe a lista de filmes disponíveis para locação, incluindo detalhes como código, título, preço e quantidade em estoque.

4. **Alugar Filmes:**
   - Permite aos clientes alugar filmes disponíveis, deduzindo o valor do saldo do cliente e atualizando o estoque do filme.

5. **Devolver Filmes:**
   - Permite aos clientes devolver filmes, atualizando o estoque e informando o valor total a pagar.

6. **Depositar Dinheiro na Conta do Cliente:**
   - Oferece a opção de depositar dinheiro na conta de um cliente, aumentando o saldo disponível.
  
## Estrutura do Projeto

O projeto está organizado nas seguintes pastas:

- `include`: Contém os arquivos de cabeçalho (`.hpp`).
- `src`: Contém os arquivos de implementação (`.cpp`).
- `teste`: Contém os arquivos de teste de unidade.

## Compilação e Execução

Para compilar o projeto, utilize o seguinte comando:

```bash
make
