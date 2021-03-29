//
// Created by Kenway on 2/11/2021.
//
#include <vector>
#include <queue>

class KthLargest {
public:
    unsigned int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> small;
    std::priority_queue<int> large;

    KthLargest(int k, std::vector<int> &nums) {
        this->k = k;
        for (auto item : nums) {
            this->large.push(item);
        }

        while (small.size() < k - 1 && !large.empty()) {
            small.push(large.top());
            large.pop();
        }
    }

    int add(int val) {
        if (!small.empty() && val > small.top()) {
            small.push(val);

            while (small.size() > k - 1 && !large.empty()) {
                large.push(small.top());
                small.pop();
            }
        } else {
            large.push(val);
        }

        return large.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */