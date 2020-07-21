#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>map;
        int max = 0;

        for (int i = 0, j = 0; i < s.size(); ++i) {
            if (map.find(s[i]) != map.end()) {
                j = j > map[s[i]] + 1 ? j : map[s[i]] + 1;
            }
            max = max > (i - j + 1) ? max : (i - j + 1);
            map[s[i]] = i;
        }
        return max;
    }
};

/*
int main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << solution.lengthOfLongestSubstring("bbbbb") << endl;
    cout << solution.lengthOfLongestSubstring("pwwkew") << endl;
    cout << solution.lengthOfLongestSubstring("") << endl;
    cout << solution.lengthOfLongestSubstring("au") << endl;
    cout << solution.lengthOfLongestSubstring("abba") << endl;
}*/
