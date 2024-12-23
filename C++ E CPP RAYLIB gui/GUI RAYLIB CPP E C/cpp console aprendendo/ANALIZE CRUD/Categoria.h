#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

class Categoria
{
private:
    int id_categoria;
    std::string descricao;

public:
    Categoria(int id, const std::string &desc);

    int getIdCategoria() const;
    std::string getDescricao() const;

    void setDescricao(const std::string &desc);
};

#endif
