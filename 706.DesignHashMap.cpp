//
// Created by Kenway on 3/14/2021.
//
#include <vector>
#include <list>

class MyHashMap {
public:
    static const int base = 512;
    std::vector<std::list<std::pair<int, int>>> map;

    /** Initialize your data structure here. */
    MyHashMap() {
        map.assign(base, std::list<std::pair<int, int>>());
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int keyValue = key % base;
        auto iter = map[keyValue].begin();
        while (iter != map[keyValue].end()) {
            if (iter->first == key) {
                iter->second = value;
                return;
            }
            iter++;
        }
        map[keyValue].push_back(std::make_pair(key, value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int keyValue = key % base;
        auto iter = map[keyValue].begin();
        while (iter != map[keyValue].end()) {
            if (iter->first == key) {
                return iter->second;
            }
            iter++;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int keyValue = key % base;
        auto iter = map[keyValue].begin();
        while (iter != map[keyValue].end()) {
            if (iter->first == key) {
                map[keyValue].erase(iter);
                return;
            }
            iter++;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */