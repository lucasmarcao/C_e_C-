#include "Produto.h"

Produto::Produto(int id, const std::string &nome, const std::string &descricao, double preco, const std::string &tam, const Categoria &cat)
    : id_produto(id), nome_produto(nome), descricao_produto(descricao), preco_fixo(preco), tamanho(tam), categoria(cat) {}

int Produto::getIdProduto() const
{
    return id_produto;
}

std::string Produto::getNomeProduto() const
{
    return nome_produto;
}

std::string Produto::getDescricaoProduto() const
{
    return descricao_produto;
}

double Produto::getPrecoFixo() const
{
    return preco_fixo;
}

std::string Produto::getTamanho() const
{
    return tamanho;
}

Categoria Produto::getCategoria() const
{
    return categoria;
}

void Produto::setNomeProduto(const std::string &nome)
{
    nome_produto = nome;
}

void Produto::setDescricaoProduto(const std::string &descricao)
{
    descricao_produto = descricao;
}

void Produto::setPrecoFixo(double preco)
{
    preco_fixo = preco;
}

void Produto::setTamanho(const std::string &tam)
{
    tamanho = tam;
}

void Produto::setCategoria(const Categoria &cat)
{
    categoria = cat;
}
