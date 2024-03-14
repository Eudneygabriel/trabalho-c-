#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>

class Produto
{
private:
    std::string nome;
    int estoque_atual;
    int comprado;
    int vendido;
    double preco_por_unidade;

public:
    Produto(const std::string &nome, int estoque_inicial, int comprado, int vendido, double preco_por_unidade) : nome(nome), estoque_atual(estoque_inicial), comprado(comprado), vendido(vendido), preco_por_unidade(preco_por_unidade) {}

    double calcularLucroTotal() const
    {
        return (vendido * preco_por_unidade) - (comprado * preco_por_unidade);
    }

    void comprar(int quantidade)
    {
        comprado += quantidade;
        estoque_atual += quantidade;
    }

    double vender(int quantidade)
    {
        if (quantidade > estoque_atual)
        {
            std::cout << "Estoque insuficiente para " << nome << "!" << std::endl;
            return 0.0;
        }
        vendido += quantidade;
        estoque_atual -= quantidade;
        return quantidade * preco_por_unidade;
    }

    std::string getNome() const
    {
        return nome;
    }

    int getEstoqueAtual() const
    {
        return estoque_atual;
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
                  << std::setw(10) << std::left << produto.getEstoqueAtual()
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

void calcularTroco(double troco)
{
    // Mapa para armazenar as denominações de notas e suas quantidades
    std::map<int, int> denominacoes = {{100, 0}, {50, 0}, {20, 0}, {10, 0}, {5, 0}};

    // Vetor com as denominações de moedas
    std::vector<double> moedas = {1.0, 0.5, 0.25, 0.1, 0.05, 0.01};

    std::cout << "Troco: " << std::fixed << std::setprecision(2) << troco << " €" << std::endl;

    // Calcula as notas necessárias para o troco
    for (auto &denominacao : denominacoes)
    {
        while (troco >= denominacao.first)
        {
            denominacao.second++;
            troco -= denominacao.first;
        }
    }

    // Calcula as moedas necessárias para o troco
    for (auto moeda : moedas)
    {
        int quantidade = troco / moeda;
        if (quantidade > 0)
        {
            std::cout << "Moedas de " << std::fixed << std::setprecision(2) << moeda << " €: " << quantidade << std::endl;
            troco -= quantidade * moeda;
        }
    }
}

int main()
{

    std::vector<Produto> produtos;
    produtos.push_back(Produto("Canetas", 50, 70, 30, 1.0));
    produtos.push_back(Produto("Cadernos", 20, 50, 15, 6.0));
    produtos.push_back(Produto("Uniformes", 15, 20, 5, 2.0));
    produtos.push_back(Produto("Lápis", 30, 20, 25, 10.0));
    produtos.push_back(Produto("Borrachas", 5, 60, 5, 6.0));

    bool continuar = true;
    while (continuar) {
        imprimirTabela(produtos);

        // Operações de compra e venda
        int opcao;
        std::cout << "Selecione uma opção:\n"
                  << "1. Compra\n"
                  << "2. Venda\n"
                  << "3. Sair\n"
                  << "Opção: ";
        std::cin >> opcao;

        if (opcao == 1)
        {
            int totalProdutos;
            std::cout << "Quantos produtos deseja comprar? ";
            std::cin >> totalProdutos;

            double totalCompra = 0.0;
            for (int i = 0; i < totalProdutos; ++i)
            {
                int indice;
                std::cout << "Digite o índice do produto " << i + 1 << ": ";
                std::cin >> indice;

                if (indice >= 1 && indice <= produtos.size())
                {
                    int quantidade;
                    std::cout << "Digite a quantidade do produto " << produtos[indice - 1].getNome() << ": ";
                    std::cin >> quantidade;

                    totalCompra += produtos[indice - 1].getPrecoPorUnidade() * quantidade;
                    produtos[indice - 1].comprar(quantidade);
                    std::cout << "Compra do produto " << produtos[indice - 1].getNome() << " realizada com sucesso!" << std::endl;
                }
                else
                {
                    std::cout << "Índice inválido!" << std::endl;
                }
            }

            std::cout << "Valor total da compra: " << totalCompra << " €" << std::endl;
        }
        else if (opcao == 2)
        {
            int totalProdutos;
            std::cout << "Quantos produtos deseja vender? ";
            std::cin >> totalProdutos;

            double totalVenda = 0.0;
            for (int i = 0; i < totalProdutos; ++i)
            {
                int indice;
                std::cout << "Digite o índice do produto " << i + 1 << ": ";
                std::cin >> indice;

                if (indice >= 1 && indice <= produtos.size())
                {
                    int quantidade;
                    std::cout << "Digite a quantidade do produto " << i + 1 << ": ";
                    std::cin >> quantidade;

                    double valorVenda = produtos[indice - 1].vender(quantidade);
                    if (valorVenda > 0.0)
                    {
                        totalVenda += valorVenda;
                        std::cout << "Venda do produto " << produtos[indice - 1].getNome() << " realizada com sucesso!" << std::endl;
                    }
                }
                else
                {
                    std::cout << "Índice inválido!" << std::endl;
                }   
            }

            std::cout << "Valor total da venda: " << totalVenda << " €" << std::endl;
            double valorPago, troco;
            std::cout << "Digite o valor pago pelo cliente: ";
            std::cin >> valorPago;
            troco = valorPago - totalVenda;
            std::cout << "Troco: " << troco << " €" << std::endl;
            calcularTroco(troco);
        }
        else if (opcao == 3)
        {
            continuar = false;
        }
        else
        {
            std::cout << "Opção inválida!" << std::endl;
        }
    } 

    return 0;
}