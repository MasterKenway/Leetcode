//
// Created by Kenway on 2/8/2021.
//
#include <vector>

class Solution {
public:
    int maxTurbulenceSize(std::vector<int>& arr) {
        int left = 0, right = 1, n = arr.size(), max = 0;

        while (right < n - 1) {
            if (left == right) {
                if (arr[left] == arr[left + 1]) {
                    left++;
                }
                right++;
            } else {
                if (arr[right - 1] < arr[right] && arr[right] > arr[right + 1]) {
                    right++;
                } else if (arr[right - 1] > arr[right] && arr[right] < arr[right + 1]) {
                    right++;
                } else {
                    left = right;
                }
            }



            max = std::max(right - left + 1, max);
        }

        return max;
    }
};