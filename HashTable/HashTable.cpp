// Hash tables store the data in key value pair

// Hashing is a technique of mapping a large set of data to tabular indexes
// using a hash function.

// A hash function is used for mapping each element of a dataset to indexes in table

// It is a method for representing dictionaries for large datasets

// allows to lookupds updating and retrieval in constant time i.e. o(1)

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class HashTable
{
private:
    int capacity;
    vector<list<pair<int, int>>> table;

public:
    HashTable(int c);
    int hashFunction(int key);
    void insertItem(int key, int data);
    void deleteItem(int key);
    int search(int key);
    void displayHash();
};

HashTable::HashTable(int c) : capacity(c)
{
    table.resize(capacity);
}

int HashTable::hashFunction(int key)
{
    return key % capacity;
}

void HashTable::insertItem(int key, int data)
{
    int index = hashFunction(key);
    table[index].push_back(make_pair(key, data));
}

void HashTable::deleteItem(int key)
{
    int index = hashFunction(key);
    list<pair<int, int>> &bucket = table[index];
    for (list<pair<int, int>>::iterator it = bucket.begin(); it != bucket.end(); it++)
    {
        if (it->first == key)
        {
            bucket.erase(it);
            return;
        }
    }
}

int HashTable::search(int key)
{
    int index = hashFunction(key);
    list<pair<int, int>> &bucket = table[index];
    for (auto it = bucket.begin(); it != bucket.end(); it++)
    {
        if (it->first == key)
        {
            return it->second; // de-referencing "it" pointer
        }
    }
    return -1;
}

void HashTable::displayHash()
{
    for (int i = 0; i < this->capacity; i++)
    {
        cout << "table[" << i << "]";
        for (pair<int, int> &item : table[i])
        {
            cout << "-->(" << item.first << ", " << item.second << ")";
        }
        cout << endl;
        cout << endl;
    }
}

int main()
{
    HashTable h(10);

    h.insertItem(231, 123);
    h.insertItem(321, 432);
    h.insertItem(212, 523);
    h.insertItem(321, 43); // Collision
    h.insertItem(433, 423);
    h.insertItem(262, 111);

    h.displayHash();

    h.deleteItem(321);
    h.displayHash();

    int searchResult = h.search(433);
    if (searchResult != -1)
    {
        std::cout << "Key 433 found with value: " << searchResult << std::endl;
    }
    else
    {
        std::cout << "Key 433 not found." << std::endl;
    }
    return 0;
}