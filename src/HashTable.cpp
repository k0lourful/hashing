//
// Created by xt1zer on 11/11/2020.
//

#include "HashTable.h"

HashTable::HashTable(const int &s) : size(s) {
    values = new int[s];
    used = new int[s];
}

int HashTable::hash(const int &data) {
    return data % size;
}

void HashTable::insert(const int &data) {
    int bucket = hash(data);
    while (used[bucket] && values[bucket] != data)
        bucket = (bucket + 1) % size;
    if (!used[bucket]) {
        used[bucket] = true;
        values[bucket] = data;
    }
}

int HashTable::dist(int a, int b) {
    return (b - a + size) % size;
}

void HashTable::remove(const int &data) {
    int bucket = hash(data), gap;
    while (used[bucket] && values[bucket] != data)
        bucket = (bucket + 1) % size;
    if (used[bucket] && values[bucket] == data) {
        used[bucket] = false;
        gap = bucket;
        bucket = (bucket + 1) % size;
        while (used[bucket]) {
            if (bucket == hash(values[bucket]) || dist(hash(values[bucket]), bucket) < dist(gap, bucket))
                bucket = (bucket + 1) % size;
            else {
                used[gap] = true;
                values[gap] = values[bucket];
                used[bucket] = false;
                gap = bucket++;
            }
        }
    }
}

bool HashTable::find(const int &data) {
    int bucket = hash(data);
    while (used[bucket] && values[bucket] != data)
        bucket = (bucket + 1) % size;
    return used[bucket] && values[bucket] == data;
}
