#include <iostream>
#include <vector>
#include <string>
#include <cstring> // Para manipulação de strings em C++
using namespace std;

// Estrutura para representar uma Categoria
struct Categoria
{
    unsigned int id_categoria;
    char descricao[100];
};

// Função para criar uma nova categoria
void criarCategoria(vector<Categoria> &categorias)
{
    Categoria novaCategoria;

    cout << "Digite o ID da Categoria: ";
    cin >> novaCategoria.id_categoria;
    cin.ignore(); // Limpar o buffer para evitar problemas na leitura de strings
    cout << "Digite a Descrição da Categoria: ";
    cin.getline(novaCategoria.descricao, 100);

    categorias.push_back(novaCategoria);
    cout << "Categoria adicionada com sucesso!\n";
}

// Função para ler (listar) todas as categorias
void listarCategorias(const vector<Categoria> &categorias)
{
    if (categorias.empty())
    {
        cout << "Nenhuma categoria encontrada.\n";
        return;
    }

    cout << "\nCategorias cadastradas:\n";
    for (const auto &categoria : categorias)
    {
        cout << "ID: " << categoria.id_categoria << ", Descrição: " << categoria.descricao << endl;
    }
}

// Função para atualizar uma categoria existente
void atualizarCategoria(vector<Categoria> &categorias)
{
    unsigned int id;
    cout << "Digite o ID da Categoria que deseja atualizar: ";
    cin >> id;
    cin.ignore(); // Limpar o buffer

    for (auto &categoria : categorias)
    {
        if (categoria.id_categoria == id)
        {
            cout << "Digite a nova descrição: ";
            cin.getline(categoria.descricao, 100);
            cout << "Categoria atualizada com sucesso!\n";
            return;
        }
    }

    cout << "Categoria com ID " << id << " não encontrada.\n";
}

// Função para deletar uma categoria
void deletarCategoria(vector<Categoria> &categorias)
{
    unsigned int id;
    cout << "Digite o ID da Categoria que deseja deletar: ";
    cin >> id;
    cin.ignore(); // Limpar o buffer

    for (auto it = categorias.begin(); it != categorias.end(); ++it)
    {
        if (it->id_categoria == id)
        {
            categorias.erase(it);
            cout << "Categoria deletada com sucesso!\n";
            return;
        }
    }

    cout << "Categoria com ID " << id << " não encontrada.\n";
}

// Função principal
int main()
{
    vector<Categoria> categorias;
    int opcao;

    do
    {
        cout << "\nSistema de Gerenciamento de Categorias\n";
        cout << "1. Criar Categoria\n";
        cout << "2. Listar Categorias\n";
        cout << "3. Atualizar Categoria\n";
        cout << "4. Deletar Categoria\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore(); // Limpar o buffer para evitar problemas na leitura de strings

        switch (opcao)
        {
        case 1:
            criarCategoria(categorias);
            break;
        case 2:
            listarCategorias(categorias);
            break;
        case 3:
            atualizarCategoria(categorias);
            break;
        case 4:
            deletarCategoria(categorias);
            break;
        case 0:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 0);

    return 0;
}
