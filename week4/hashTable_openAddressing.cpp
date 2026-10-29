
#include <string>
#include <vector>
using namespace std;

class HashTable {
private:
    static const int SIZE = 10;
    vector<pair<string, int>> table;

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
        
        for(int i=0; i < SIZE; ++i) {
            if (table[index].first.empty() || table[index].first == key) {
            table[index] = {key, value};
            return;
        }
        index = (index + 1) % SIZE;
        }
    }
9
    bool search(const string& key, int& value) const {
        int index = hashFunction(key);
        
        for(int i=0; i < SIZE; ++i) {
            if (table[index].first.empty()) {
                return false;
            }
            if (table[index].first == key) {
                value = table[index].second;
                return true;
            }
            index = (index + 1) % SIZE;
        }
        return false;
    }
};