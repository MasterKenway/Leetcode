package No377;

/**
 * @author Kenway
 * @date 4/24/2021 10:41 PM
 * @description
 **/

//class Solution {
//    public int combinationSum4(int[] nums, int target) {
//        int res = 0;
//        int[][] dp = new int[target + 1][target + 1];
//        dp[0][0] = 1;
//        for (int i = 1; i <= target; i++) {
//            for (int j = 0; j <= target; j++) {
//                for (int item : nums) {
//                    if (j >= item) dp[i][j] += dp[i - 1][j - item];
//                }
//            }
//            res += dp[i][target];
//        }
//
//        return res;
//    }
//}

class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[] dp = new int[target + 1];
        dp[0] = 1;
        for (int i = 0; i <= target; i++) {
            for (int item :
                 nums) {
                if (i >= item) dp[i] += dp[i - item];
            }
        }
        return dp[target];
    }
}

public class CombinationSumIV {

}
