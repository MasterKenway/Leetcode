//
// Created by Kenway on 2/18/2021.
//
#include <vector>

//class Solution {
//public:
//    int minKBitFlips(std::vector<int> &A, int K) {
//        int n = A.size(), currCounter = 0, res = 0;
//        std::vector<int> counter(n, 0);
//
//        for (int i = 0; i < n; ++i) {
//            if (A[i] + counter[i] % 2 == 0) {
//                if (i + K > n) return -1;
//                res++;
//                currCounter++;
//                counter[i + K]--;
//            }
//        }
//
//        return res;
//    }
//};

class Solution {
public:
    int minKBitFlips(std::vector<int> &A, int K) {
        int n = A.size(), currCounter = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] > 1) {
                currCounter--;
                A[i] -= 2;
            }
            if ((A[i] + currCounter) % 2 == 0) {
                if (i + K > n) return -1;
                res++;
                currCounter++;
                A[i + K] += 2;
            }
        }
        return res;
    }
};