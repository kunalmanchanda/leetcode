class Solution {
public:
    int solve(vector<int> &arr, int target, int i, vector<vector<int>> &dp) 
    {
        if(target == 0) {
            return 1;
        }

        if(i == arr.size() || target < 0) {
            return 0;
        }

        if(dp[target][i] != -1) {
            return dp[target][i];
        }
        
        return dp[target][i] = solve(arr, target, i + 1, dp) + solve(arr, target - arr[i], 0, dp);
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(target + 1, vector<int>(n + 1, -1));
        return solve(nums, target, 0, dp);
    }
};