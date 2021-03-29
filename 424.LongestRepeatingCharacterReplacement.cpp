//
// Created by Kenway on 2/2/2021.
//
#include <string>
#include <unordered_map>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int size = s.size(), left = 0, right = 0, max = 0;
        std::unordered_map<int, int> map;
        while (right < size) {
            map[s[right]]++;
            max = std::max(max, map[s[right]]);
            if (right - left - max >= k) {
                max[s[right]]--;
                left++;
            }

            right++;
        }
    }
};

//class Solution {
//public:
//    int characterReplacement(std::string s, int k) {
//        int size = s.length(), max = 0;
//        std::unordered_map<char, bool> map;
//
//        for (int i = 0; i < size; ++i) {
//            map.insert(std::make_pair(s[i], true));
//        }
//
//        for (auto iter : map) {
//            int i = 0, j = 0;
//            std::vector<std::pair<int, int>> list;
//            while (i < size) {
//                while (i < size && s[i] != iter.first) i++;
//                if (i < size) {
//                    j = i + 1;
//                    while (j < size && s[j] == iter.first) j++;
//                    j = j < size && j != i + 1 ? j : j - 1;
//                    list.push_back(std::make_pair(i , j));
//                    i = j;
//                }
//                i++;
//            }
//
//            if (!list.empty()) {
//                for (auto iter2 = list) {
//                    max = max >
//                }
//
//                for (i = 1; i < list.size(); ++i) {
//                    int temp = list[i].first - list[i - 1].second;
//
//                }
//            }
//        }
//
//        return
//    }
//};