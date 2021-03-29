//
// Created by Kenway on 3/13/2021.
//
#include <vector>
#include <list>

class MyHashSet {
private:
    std::vector<std::list<int>> set;
    static const int base = 512;

    int hash(int key) {
        return key % base;
    }

public:
    /** Initialize your data structure here. */
    MyHashSet() {
        set.assign(base, std::list<int>());
    }

    void add(int key) {
        int value = hash(key);
        auto iter = set[value].begin();
        while (iter != set[value].end()) {
            if (*iter == key) {
                return;
            }
            iter++;
        }
        set[value].push_back(key);
    }

    void remove(int key) {
        int value = key % base;
        auto iter = set[value].begin();
        while (iter != set[value].end()) {
            if (*iter == key) {
                set[value].erase(iter);
                break;
            }
            iter++;
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int value = key % base;
        auto iter = set[value].begin();
        while (iter != set[value].end()) {
            if (*iter == key) {
                return true;
            }
            iter++;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
