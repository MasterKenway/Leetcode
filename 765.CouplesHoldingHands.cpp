//
// Created by Kenway on 2/14/2021.
//

#include <vector>
#include <malloc.h>

class DisJoinSet {
public:

    int size;
    int *parent;

    DisJoinSet(int n) {
        size = n;
        parent = (int *) malloc(sizeof(int) * n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return find(parent[x]);
    }

    void merge(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY)
            return;
        parent[rootY] = rootX;
        size--;
    }

};

class Solution {
public:
    int minSwapsCouples(std::vector<int> &row) {
        int n = row.size();
        DisJoinSet disJoinSet(n / 2);

        for (int i = 0; i < n; i += 2) {
            disJoinSet.merge(row[i], row[i - 1]);
        }

        return n / 2 - disJoinSet.size;
    }
};