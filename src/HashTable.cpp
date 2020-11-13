#include "HashTable.h"
#include <random>

void HashTable::createTable(const int &s) {
    if (size) clear();
    size = s;
    values = new int[s * 1.5];
    used = new bool[s * 1.5]();
}

int HashTable::getSize() const {
    return size;
}

int HashTable::getValue(const int &ind) const {
    if (used[hash(ind)]) return INT32_MIN;
    return values[hash(ind)];
}

int HashTable::hash(const int &data) const {
    return data % size;
}

int HashTable::insert(const int &data) {
    if (!size) return -1;

    int bucket = hash(data);
    while (used[bucket] && values[bucket] != data)
        bucket = (bucket + 1) % size;
    if (!used[bucket]) {
        used[bucket] = true;
        values[bucket] = data;
    } else return 1;

    return 0;
}

int HashTable::dist(int a, int b) const {
    return (b - a + size) % size;
}

int HashTable::remove(const int &data) {
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
    else return 1;
    return 0;
}

bool HashTable::find(const int &data) const {
    int bucket = hash(data);
    while (used[bucket] && values[bucket] != data)
        bucket = (bucket + 1) % size;
    return used[bucket] && values[bucket] == data;
}

void HashTable::clear() {
    for (int i = 0; i < size; ++i) {
//        values[i] = 0;
        used[i] = false;
    }
}

void HashTable::generateRandomTable(const int &s) {
    if (size) clear();

    size = s;
    values = new int[s * 1.5];
    used = new bool[s * 1.5](); // initialise array with false

    std::random_device dev;
    std::mt19937 engine(dev());
    std::uniform_int_distribution<int> uid(0, 20);
    for (int i = 0; i < s; ++i)
        insert(i + s * uid(engine));
}
