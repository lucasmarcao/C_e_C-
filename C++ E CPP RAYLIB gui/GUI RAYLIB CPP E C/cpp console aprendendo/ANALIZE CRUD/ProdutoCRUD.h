#ifndef PRODUTO_CRUD_H
#define PRODUTO_CRUD_H

#include "Produto.h"
#include <vector>

class ProdutoCRUD
{
private:
    std::vector<Produto> produtos;

public:
    void criarProduto(const Produto &produto);
    Produto lerProduto(int id) const;
    void atualizarProduto(int id, const Produto &produto);
    void deletarProduto(int id);

    std::vector<Produto> listarProdutos() const;
};

#endif
