    //
    // Created by Kenway on 2/6/2021.
    //
    #include <vector>
    #include <numeric>

    class Solution {
    public:
        int maxScore(std::vector<int>& cardPoints, int k) {
            int max = std::accumulate(cardPoints.begin(), cardPoints.begin() + k, 0), currSum = max, i = 0, n = cardPoints.size();
            while (i < k) {
                currSum -= cardPoints[k - 1 - i];
                currSum += cardPoints[n - 1 - i];
                max = std::max(currSum, max);
                i++;
            }

            return max;
        }
    };