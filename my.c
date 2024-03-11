#include <iostream>

class Caneta
{
private:
    int quantidade;
    int preco;

public:
    Caneta(int quantidadeInicial, int precoUnitario) : quantidade(quantidadeInicial), preco(precoUnitario) {}

    void vender(int quantidadeVendida)
    {
        quantidade -= quantidadeVendida;
    }

    void comprar(int quantidadeComprada)
    {
        quantidade += quantidadeComprada;
    }

    int calcularLucro() const
    {
        return (quantidade * preco) - 30; // 30€ de lucro final
    }
};

int main()
{
    Caneta caneta(50, 1); // Inicializa com 50 canetas e preço de 1€ cada

    caneta.vender(30);  // Vende 30 canetas
    caneta.comprar(70); // Compra mais 70 canetas

    int lucroFinal = caneta.calcularLucro(); // Calcula o lucro final

    std::cout << "Lucro final: " << lucroFinal << " euros" << std::endl;

    return 0;
}
