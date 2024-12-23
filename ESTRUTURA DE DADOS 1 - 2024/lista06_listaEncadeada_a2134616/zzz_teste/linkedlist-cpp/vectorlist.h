#pragma once

// Definicao do TAD Lista Sequencial

class VectorList {
private:
    int size;
    int capacity;
    int* data;

    bool resize(int new_size);

public:
    VectorList();
    ~VectorList();
    bool push_back(int elem);
    bool pop_back();
    int get(int pos);
    void print();
};

