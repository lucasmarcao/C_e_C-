#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include "Categoria.h"

class Produto
{
private:
    int id_produto;
    std::string nome_produto;
    std::string descricao_produto;
    double preco_fixo;
    std::string tamanho;
    Categoria categoria;

public:
    Produto(int id, const std::string &nome, const std::string &descricao, double preco, const std::string &tam, const Categoria &cat);

    int getIdProduto() const;
    std::string getNomeProduto() const;
    std::string getDescricaoProduto() const;
    double getPrecoFixo() const;
    std::string getTamanho() const;
    Categoria getCategoria() const;

    void setNomeProduto(const std::string &nome);
    void setDescricaoProduto(const std::string &descricao);
    void setPrecoFixo(double preco);
    void setTamanho(const std::string &tam);
    void setCategoria(const Categoria &cat);
};

#endif
