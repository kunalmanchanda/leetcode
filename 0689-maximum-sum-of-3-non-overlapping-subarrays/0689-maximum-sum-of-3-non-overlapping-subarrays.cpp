class Solution {
    long int helper(int i, int count, vector<int> &arr, int k, vector<vector<int>> &dp) {
        if(count == 0) {
            return 0;
        }

        if(i >= arr.size()) {
            return INT_MIN;
        }

        if(dp[i][count] != -1) {
            return dp[i][count];
        }

        long int take = arr[i] + helper(i + k, count - 1, arr, k, dp);
        long int notTake = helper(i+1, count, arr, k, dp);
        
        dp[i][count] = max(take, notTake);

        return dp[i][count];
    }

    // provides indexes
    void solve(int i, int count, int k, vector<int> &arr, vector<int> &res, vector<vector<int>> &dp) {
        if(count == 0) return;
        if(i >= arr.size()) return;

        int takeSum = arr[i] + helper(i + k, count - 1, arr, k, dp);
        int notTakeSum = helper(i+1, count, arr, k, dp);

        if(takeSum >= notTakeSum) {
            res.push_back(i);
            solve(i + k, count - 1, k, arr, res, dp);
        } else {
            solve(i + 1, count, k, arr, res, dp);
        }
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> prefix;

        int n = nums.size();

        int j = 0, i = 0;
        int sum = 0;

        while(j < k) {
            sum += nums[j++];
        }

        prefix.push_back(sum);

        while(j < n) {
            prefix.push_back(prefix[i] + nums[j++] - nums[i++]);
        }

        int m = prefix.size();

        vector<vector<int>> dp(m + 1,vector<int>(4, -1));

        vector<int> res;

        solve(0, 3, k, prefix, res, dp);
        return res;
    }
};