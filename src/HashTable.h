#pragma once

class HashTable {
    int *values;
    int *used;
    int size;

public:
//    HashTable();
    HashTable(const int& s);

    int hash(const int &data);

    void insert(const int &data);

    int dist(int a, int b);

    void remove(const int &data);

    bool find(const int &data);

};
