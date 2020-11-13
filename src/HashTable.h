#pragma once

class HashTable {
    int *values;
    bool *used;
    int size;

public:
    HashTable() : size(0) {}

    HashTable(const int &s) : size(s), values(new int[s]), used(new bool[s]) {}

    ~HashTable() { clear(); delete[] values; delete[] used; size = 0; }

    void createTable(const int &s);

    int getSize() const;

    int getValue(const int &ind) const;

    int hash(const int &data) const;

    int insert(const int &data);

    int dist(int a, int b) const;

    int remove(const int &data);

    bool find(const int &data) const;

    void generateRandomTable(const int &s);

    void clear();
};
