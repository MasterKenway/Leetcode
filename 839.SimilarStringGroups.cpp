//
// Created by Kenway on 1/31/2021.
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
    int numSimilarGroups(std::vector<std::string> &strs) {
        int n = strs.size();
        DisJoinSet disJoinSet(n);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < strs.size(); ++j) {
                if (similar(i, j, strs))
                    disJoinSet.merge(i, j);
            }
        }

        return disJoinSet.size;
    }

    bool similar(int i, int j, std::vector<std::string> &strs) {
        int diff = 0;
        for (int k = 0; k < strs[0].size(); ++k) {
            if (strs[i][k] != strs[j][k]) {
                diff++;
            }
        }

        return diff == 2 || diff == 0;
    }

};