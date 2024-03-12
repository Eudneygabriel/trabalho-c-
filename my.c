#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

class Produto
{
private:
    std::string nome;
    int estoque_inicial;
    int comprado;
    int vendido;
    double preco_por_unidade;

public:
    Produto(const std::string &nome, int estoque_inicial, int comprado, int vendido, double preco_por_unidade) : nome(nome), estoque_inicial(estoque_inicial), comprado(comprado), vendido(vendido), preco_por_unidade(preco_por_unidade) {}

    double calcularLucroTotal() const
    {
        return (vendido * preco_por_unidade) - (comprado * preco_por_unidade);
    }

    std::string getNome() const
    {
        return nome;
    }

    int getEstoqueInicial() const
    {
        return estoque_inicial;
    }

    int getComprado() const
    {
        return comprado;
    }

    int getVendido() const
    {
        return vendido;
    }

    double getPrecoPorUnidade() const
    {
        return preco_por_unidade;
    }
};

void imprimirTabela(const std::vector<Produto> &produtos)
{

    std::cout << std::setw(5) << std::left << "No."
              << std::setw(15) << std::left << "Produto"
              << std::setw(10) << std::left << "Estoque"
              << std::setw(10) << std::left << "Compras"
              << std::setw(10) << std::left << "Vendidos"
              << std::setw(10) << std::left << "Preço"
              << std::setw(15) << std::left << "Lucro Total" << std::endl;

    std::cout << std::setfill('-') << std::setw(75) << "-" << std::endl;
    std::cout << std::setfill(' ');

    int contador = 1;

    for (const auto &produto : produtos)
    {
        std::cout << std::setw(5) << std::left << contador
                  << std::setw(15) << std::left << produto.getNome()
                  << std::setw(10) << std::left << produto.getEstoqueInicial()
                  << std::setw(10) << std::left << produto.getComprado()
                  << std::setw(10) << std::left << produto.getVendido()
                  << std::setw(10) << std::left << produto.getPrecoPorUnidade()
                  << std::setw(15) << std::left << produto.calcularLucroTotal() << std::endl;

        if (contador != produtos.size())
        {
            std::cout << std::setfill('-') << std::setw(75) << "-" << std::endl;
            std::cout << std::setfill(' ');
        }

        contador++;
    }

    std::cout << std::setfill('-') << std::setw(75) << "-" << std::endl;
    std::cout << std::setfill(' ');
}

int main()
{

    std::vector<Produto> produtos;
    produtos.push_back(Produto("Canetas", 50, 70, 30, 1.0));
    produtos.push_back(Produto("Cadernos", 20, 50, 15, 6.0));
    produtos.push_back(Produto("Uniformes", 15, 20, 5, 2.0));
    produtos.push_back(Produto("Lápis", 30, 20, 25, 10.0));
    produtos.push_back(Produto("Borrachas", 5, 60, 5, 6.0));

    git
        imprimirTabela(produtos);

    return 0;
}
