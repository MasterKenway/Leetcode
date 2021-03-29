//
// Created by MasterKenway <zk@ikenway.net> on 1/23/2021.
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
    int makeConnected(int n, std::vector<std::vector<int>> &connections) {
        int noNeedConn = 0;
        DisJoinSet disJoinSet = DisJoinSet(n);
        for (int i = 0; i < connections.size(); ++i) {
            if (disJoinSet.find(connections[i][0]) == disJoinSet.find(connections[i][1]))
                noNeedConn++;
            else
                disJoinSet.merge(disJoinSet.parent[connections[i][0]], disJoinSet.parent[connections[i][1]]);
        }

        if (noNeedConn >= disJoinSet.size - 1) return disJoinSet.size - 1;
        return -1;
    }
};

