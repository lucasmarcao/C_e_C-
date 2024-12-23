#include "Categoria.h"

Categoria::Categoria(int id, const std::string &desc) : id_categoria(id), descricao(desc) {}

int Categoria::getIdCategoria() const
{
    return id_categoria;
}

std::string Categoria::getDescricao() const
{
    return descricao;
}

void Categoria::setDescricao(const std::string &desc)
{
    descricao = desc;
}
