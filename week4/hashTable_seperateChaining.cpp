#include <vector>
#include<string>
#include <list>

using namespace std;

class HashTable {
private:
    static const int SIZE = 10;
    vector<list<pair<string, int>>> table;

    int hashFunction(const string& key) const {
        int hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % SIZE;
        }
        return hash % SIZE;
    }
public:
    HashTable() : table(SIZE) {}

    void insert(const string& key, int value) {
        int index = hashFunction(key);
        for (auto& item :table[index]) {
            if(item.first == key) {
                item.second = value;
                return;
            }
        }
        table[index].push_back({key, value});
    }

    bool search(const string& key, int& value) const {
        int index = hashFunction(key);
        
        for (const auto& item : table[index]) {
            if (item.first == key) {
                value = item.second;
                return true;
            }
        }
        return false;
    }
};