//
// Created by Kenway on 4/1/2021.
//

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int clumsy(int N) {
        queue<int> queue;
        vector<char> operations = {'+', '-'};
        for (int i = N; i > 0; i -= 4) {
            int tmp = i;
            if (i - 1 > 0) tmp *= (i - 1);
            if (i - 2 > 0) tmp /= (i - 2);
            queue.emplace(tmp);
            if (i - 3 > 0) queue.emplace(i - 3);
        }

        int res = queue.front(), opIndex = 0;
        queue.pop();
        while (!queue.empty()) {
            if (operations[opIndex] == '+') {
                res += queue.front();
            } else {
                res -= queue.front();
            }
            queue.pop();
            opIndex = (opIndex + 1) % 4;
        }
        return res;
    }
};