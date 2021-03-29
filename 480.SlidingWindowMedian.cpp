//
// Created by Kenway on 2/3/2021.
//
#include <unordered_map>
#include <queue>
#include <vector>

class MedianFinder {
public:
    int smallSize, bigSize;
    std::priority_queue<int> small;
    std::priority_queue<int, std::vector<int>, std::greater<int>> big;
    std::unordered_map<int, int> delay;

    /** initialize your data structure here. */
    MedianFinder() {
        smallSize = 0;
        bigSize = 0;
    }

    void addNum(int num) {
        if (smallSize != 0 && num <= small.top()) {
            small.push(num);
            smallSize++;
        } else {
            big.push(num);
            bigSize++;
        }

        make_balance();
    }

    void removeNum(int num) {
        delay[num]++;

        if (small.top() <= num) {
            if (small.top() == num) {
                small.pop();
                smallSize--;
                delay[num]--;
                valid(small);
            }
            smallSize--;
        } else if (big.top() >= num) {
            if (big.top() == num) {
                big.pop();
                bigSize--;
                delay[num]--;
                valid(big);

            }
            bigSize--;
        }
        make_balance();
    }

    void make_balance() {
        if (smallSize != 0 && smallSize - 1 > bigSize) {
            big.push(small.top());
            small.pop();
            smallSize--;
            bigSize++;
            valid(small);
        } else if (bigSize != 0 && smallSize < bigSize) {
            small.push(big.top());
            big.pop();
            bigSize--;
            smallSize++;
            valid(big);
        }
    }

    template<typename T>
    void valid(T &heap) {
        while (!heap.empty()) {
            int num = heap.top();
            if (delay[num] != 0) {
                heap.pop();
                delay[num]--;
            } else {
                break;
            }
        }
    }

    double findMedian() {
        double mid;
        if (smallSize == bigSize) {
            mid = (double) (small.top() + big.top()) / 2;
        } else {
            mid = small.top();
        }
        return mid;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(std::vector<int> &nums, int k) {
        MedianFinder medianFinder;
        std::vector<double> res;
        for (int i = 0; i < nums.size(); ++i) {
            medianFinder.addNum(nums[i]);
            if (i >= k - 1) {
                res.push_back(medianFinder.findMedian());
                if (i > k - 1) medianFinder.removeNum(nums[i - k]);

            }
        }

        return res;
    }
};