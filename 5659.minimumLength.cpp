    //
    // Created by Kenway on 2/6/2021.
    //
    #include <string>

    class Solution {
    public:
        int minimumLength(std::string s) {
            int i = 0, n = s.size(), left = 0, right = n - 1;
            while (left < right && left < n && right >= 0) {
                if (s[left] == s[right]) {
                    char target = s[left];
                    while (s[left] == target && left < n && left <= right) left++;
                    while (s[right] == target && right >= 0 && left <= right) right--;
                } else {
                    break;
                }
            }

            if (right >= left)
                return right - left + 1;
            else
                return 0;
        }
    };