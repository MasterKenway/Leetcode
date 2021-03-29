//
// Created by MasterKenway <zk@ikenway.net> on 1/25/2021.
//
#include <vector>
#include <string>


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
    int regionsBySlashes(std::vector<std::string> &grid) {
        int size = grid.size();
        DisJoinSet disJoinSet = DisJoinSet(size * size * 4);
        /**
         *   0
         *  3 1
         *   2
         */
        auto id = [&](int x, int y, int k) {
            return (x * size + y) * 4 + k;
        };

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (grid[i][j] == '/') {
                    disJoinSet.merge(id(i, j, 0), id(i, j, 3));
                    disJoinSet.merge(id(i, j, 1), id(i, j, 2));
                } else if (grid[i][j] == '\\') {
                    disJoinSet.merge(id(i, j, 0), id(i, j, 1));
                    disJoinSet.merge(id(i, j, 3), id(i, j, 2));
                } else {
                    disJoinSet.merge(id(i, j, 0), id(i, j, 1));
                    disJoinSet.merge(id(i, j, 3), id(i, j, 2));
                    disJoinSet.merge(id(i, j, 0), id(i, j, 3));
                }

                if (j + 1 < size)
                    disJoinSet.merge(id(i, j, 1), id(i, j + 1, 3));
                if (i + 1 < size)
                    disJoinSet.merge(id(i, j, 2), id(i + 1, j, 0));
            }
        }

        return disJoinSet.size;
    }
};
