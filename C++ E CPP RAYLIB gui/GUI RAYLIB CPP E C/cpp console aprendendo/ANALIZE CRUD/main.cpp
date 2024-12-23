#include <iostream>
#include "Produto.h"
#include "Categoria.h"
#include "ProdutoCRUD.h"

int main()
{
    ProdutoCRUD produtoCRUD;
    Categoria cat(1, "Eletrônicos");
    unsigned int mamaeu = 34;

    Produto p1(1, "Notebook", "Notebook Dell Inspiron", 3500.00, "15 polegadas", cat);
    produtoCRUD.criarProduto(p1);

    Produto p2(2, "Smartphone", "Smartphone Samsung Galaxy", 1200.00, "6 polegadas", cat);
    produtoCRUD.criarProduto(p2);

    try
    {
        Produto produto = produtoCRUD.lerProduto(1);
        std::cout << "Produto: " << produto.getNomeProduto() << " - " << produto.getDescricaoProduto() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
