//
// Created by MasterKenway <zk@ikenway.net> on 1/23/2021.
//
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> addToArrayForm(std::vector<int> &A, int K) {
        std::vector<int> array = {};
        for (int i = A.size() - 1; i >= 0; --i) {
            int sum = A[i] + K % 10;
            K /= 10;
            if (sum >= 10) {
                K++;
            }
            array.push_back(sum % 10);
        }

        while (K != 0) {
            array.push_back(K % 10);
            K /= 10;
        }


        std::reverse(array.begin(), array.end());
        return array;
    }
};