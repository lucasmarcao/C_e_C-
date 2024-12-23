#ifndef PRODUTO_CRUD_H
#define PRODUTO_CRUD_H

#include "ProdutoCRUD.h"
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

    // void ProdutoCRUD::criarProduto(const Produto &produto)
    // {
    // }

    // Produto ProdutoCRUD::lerProduto(int id) const
    // {
    // }

    // void ProdutoCRUD::atualizarProduto(int id, const Produto &produto)
    // {
    // }

    // void ProdutoCRUD::deletarProduto(int id)
    // {
    // }
    std::vector<Produto> listarProdutos() const;
};

#endif
