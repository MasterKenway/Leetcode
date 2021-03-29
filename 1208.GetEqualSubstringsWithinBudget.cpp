//
// Created by Kenway on 2/5/2021.
//
#include <string>

class Solution {
public:
    int equalSubstring(std::string s, std::string t, int maxCost) {
        int lastCost = 0, maxLength = 0, n = s.size(), right = 0, left = 0;
        while (right < n) {
            int cost = std::abs(s[right] - t[right]);
            if (lastCost + cost <= maxCost) {
                lastCost += cost;
                maxLength = std::max(maxLength, right - left + 1);
            } else {
                lastCost -= std::abs(s[left] - t[left]);
                left++;
            }
            right++;
        }
        return maxLength;
    }
};