#include <stdio.h>
#include <stdlib.h>

// Definimos as cores RED e BLACK para facilitar o controle
typedef enum
{
    RED,
    BLACK
} Color;

// Estrutura de um nó da árvore rubro-negra
typedef struct Node
{
    int data;            // Valor do nó
    Color color;         // Cor do nó: RED ou BLACK
    struct Node *left;   // Ponteiro para o filho esquerdo
    struct Node *right;  // Ponteiro para o filho direito
    struct Node *parent; // Ponteiro para o nó pai
} Node;

// Estrutura da árvore rubro-negra
typedef struct RBTree
{
    Node *root; // Raiz da árvore
} RBTree;

// Função para criar um novo nó
Node *createNode(int data)
{
    // Alocação de memória para um novo nó
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    { // Verifica se a memória foi alocada corretamente
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    // Inicializa o nó com os valores
    newNode->data = data; // Atribui o valor ao nó
    newNode->color = RED; // Novo nó é sempre vermelho inicialmente
    newNode->left = NULL; // Nó não tem filhos ainda
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
}

// Função para realizar rotação à esquerda
void rotateLeft(RBTree *tree, Node *x)
{
    Node *y = x->right; // y é o filho direito de x
    x->right = y->left; // A subárvore à esquerda de y torna-se a subárvore à direita de x

    // Se y->left não for NULL, define seu pai como x
    if (y->left != NULL)
    {
        y->left->parent = x;
    }

    y->parent = x->parent; // O pai de y agora é o pai de x

    // Se o pai de x for NULL, y torna-se a nova raiz
    if (x->parent == NULL)
    {
        tree->root = y;
    }
    else if (x == x->parent->left)
    { // Se x era filho esquerdo, y assume essa posição
        x->parent->left = y;
    }
    else
    { // Caso contrário, y torna-se filho direito
        x->parent->right = y;
    }

    y->left = x; // x torna-se o filho esquerdo de y
    x->parent = y;
}

// Função para realizar rotação à direita
void rotateRight(RBTree *tree, Node *y)
{
    Node *x = y->left;  // x é o filho esquerdo de y
    y->left = x->right; // A subárvore à direita de x torna-se a subárvore à esquerda de y

    // Se x->right não for NULL, define seu pai como y
    if (x->right != NULL)
    {
        x->right->parent = y;
    }

    x->parent = y->parent; // O pai de x agora é o pai de y

    // Se o pai de y for NULL, x torna-se a nova raiz
    if (y->parent == NULL)
    {
        tree->root = x;
    }
    else if (y == y->parent->right)
    { // Se y era filho direito, x assume essa posição
        y->parent->right = x;
    }
    else
    { // Caso contrário, x torna-se filho esquerdo
        y->parent->left = x;
    }

    x->right = y; // y torna-se o filho direito de x
    y->parent = x;
}

// Função para corrigir violações após inserção
void fixViolation(RBTree *tree, Node *z)
{
    // Loop enquanto o pai de z for vermelho
    while (z->parent != NULL && z->parent->color == RED)
    {
        // Se o pai de z for filho esquerdo
        if (z->parent == z->parent->parent->left)
        {
            Node *y = z->parent->parent->right; // O tio de z

            // Caso 1: O tio de z é vermelho
            if (y != NULL && y->color == RED)
            {
                z->parent->color = BLACK;       // Pai de z torna-se preto
                y->color = BLACK;               // Tio de z torna-se preto
                z->parent->parent->color = RED; // Avô de z torna-se vermelho
                z = z->parent->parent;          // z sobe na árvore
            }
            else
            {
                // Caso 2: z é o filho direito
                if (z == z->parent->right)
                {
                    z = z->parent;
                    rotateLeft(tree, z); // Rotaciona à esquerda
                }
                // Caso 3: z é o filho esquerdo
                z->parent->color = BLACK;             // Pai de z torna-se preto
                z->parent->parent->color = RED;       // Avô de z torna-se vermelho
                rotateRight(tree, z->parent->parent); // Rotaciona à direita
            }
        }
        else
        {
            // Caso simétrico: pai de z é filho direito
            Node *y = z->parent->parent->left; // O tio de z

            if (y != NULL && y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    rotateRight(tree, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateLeft(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = BLACK; // A raiz deve sempre ser preta
}

// Função para inserir um novo nó na árvore
void insert(RBTree *tree, int data)
{
    // Cria um novo nó com o dado fornecido
    Node *z = createNode(data);
    Node *y = NULL;       // y será o pai de z
    Node *x = tree->root; // Começa pela raiz da árvore

    // Encontra a posição correta para inserir z
    while (x != NULL)
    {
        y = x;                 // Atualiza y para o nó atual
        if (z->data < x->data) // Vai para a subárvore esquerda se o valor for menor
            x = x->left;
        else
        {
            // Vai para a subárvore direita se o valor for maior
            x = x->right;
        }
    }

    z->parent = y; // Define o pai de z

    // Se y é NULL, significa que a árvore estava vazia, então z torna-se a raiz
    if (y == NULL)
    {
        tree->root = z;
    }
    else if (z->data < y->data)
    { // Se o dado de z é menor que o de y, z é o filho esquerdo
        y->left = z;
    }
    else
    { // Caso contrário, z é o filho direito
        y->right = z;
    }

    // Corrige as violações de propriedades da árvore rubro-negra
    fixViolation(tree, z);
}

// Função auxiliar para exibir a árvore (em ordem)
void inorderHelper(Node *root)
{
    if (root != NULL)
    {
        inorderHelper(root->left);                                              // Percorre a subárvore esquerda
        printf("%d (%s) \n", root->data, root->color == RED ? "RED" : "BLACK"); // Exibe o nó
        inorderHelper(root->right);                                             // Percorre a subárvore direita
    }
}

// Função para exibir a árvore em ordem
void inorder(RBTree *tree)
{
    inorderHelper(tree->root); // Chama a função auxiliar
    printf("\n");              // Pula uma linha após a exibição
}

// Função principal
int main()
{
    // Inicializa a árvore rubro-negra com a raiz nula
    RBTree tree;
    tree.root = NULL;

    // Insere alguns valores na árvore
    insert(&tree, 10);
    insert(&tree, 20);
    insert(&tree, 30);
    insert(&tree, 15);

    // Exibe a árvore em ordem
    printf("\n Inorder traversal da árvore rubro-negra: \n");
    inorder(&tree);

    return 0;
    // control + shift + '
    // gcc arvoreRubroNegra.c -o arvore.exe
    // ./arvore.exe
}

/*

Alterações e Melhorias []

Comentários Detalhados: Cada bloco de código foi
detalhadamente explicado, linha por linha, para facilitar
o entendimento.

Verificação de Erros: Adicionada verificação para garantir
que a alocação de memória foi bem-sucedida ao criar um nó.

Mais Legibilidade: Variáveis com nomes descritivos e a
estrutura do código foi organizada para ser mais legível.

Simetria: As funções de rotação e inser
ção foram cuidadosamente explicadas,
com passos detalhados, o que facilita
a depuração e a prevenção de erros.

*/