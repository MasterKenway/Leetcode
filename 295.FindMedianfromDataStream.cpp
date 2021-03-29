//
// Created by Kenway on 2/3/2021.
//
#include <queue>
#include <vector>

class MedianFinder {
public:
    std::priority_queue<int> small;
    std::priority_queue<int, std::vector<int>, std::greater<int>> big;

    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (!small.empty() && num <= small.top())
            small.push(num);
        else
            big.push(num);

        make_balance();
    }

    void make_balance() {
        if (!small.empty() && small.size() - 1 > big.size()) {
            big.push(small.top());
            small.pop();
        } else if (!big.empty() && small.size() < big.size()) {
            small.push(big.top());
            big.pop();
        }
    }

    double findMedian() {
        double mid;
        if (small.size() == big.size()) {
            mid = (double) (small.top() + big.top()) / 2;
        } else {
            mid = small.top();
        }
        return mid;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */