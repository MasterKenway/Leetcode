#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> &n1 = nums1.size() <= nums2.size() ? nums1 : nums2;
        vector<int> &n2 = nums1.size() > nums2.size() ? nums1 : nums2;

        int mid = (int)(n1.size() + n2.size() + 1) / 2;

        int min = 0, max = n1.size();

        if (n1.empty()) {
            if (n2.size() % 2 == 0)
                return (double) (n2[mid - 1] + n2[mid]) / 2;
            else
                return n2[mid - 1];
        }

        while (min <= max) {
            int i = (int)(min + max) / 2;
            int j = mid - i;

            if (i < max && n2[j - 1] > n1[i])
                min = i + 1;
            else if (i > min && n1[i - 1] > n2[j])
                max = i - 1;
            else {
                int maxLeft = 0;

                if (i == 0)
                    maxLeft = n2[j - 1];
                else if (j == 0)
                    maxLeft = n1[i - 1];
                else
                    maxLeft = n1[i - 1] > n2[j - 1] ? n1[i - 1] : n2[j - 1];

                if ((n1.size() + n2.size()) % 2 == 1){
                    return maxLeft;
                } else {
                    int maxRight = 0;
                    if (i == n1.size())
                        maxRight = n2[j];
                    else if (j == n2.size())
                        maxRight = n1[i];
                    else
                        maxRight = n1[i] < n2[j] ? n1[i] : n2[j];

                    return (double)(maxLeft + maxRight) / 2;
                }
            }
        }
        return 0.0;
    }
};

/*
int main() {
    Solution solution;
    vector<int> nums1 = {};
    vector<int> nums2 = {1,2,3,4,5};
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
}*/
