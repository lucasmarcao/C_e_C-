#pragma once

// Definicao do TAD Lista Sequencial

class VectorList {
private:
    int size;
    int capacity;
    int* data;

public:
    VectorList();
    ~VectorList();
    bool push_back(int elem);
    bool resize(int new_size);
    void print();
};

