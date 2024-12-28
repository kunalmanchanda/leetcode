class Solution {
    vector<int> prefix;

    long int helper(int i, int count, vector<int> &arr, int k) {
        if(count == 0) {
            return 0;
        }
        if(i >= arr.size()) {
            return INT_MIN;
        }

        long int take = getSubArraySum(i, i + k - 1) + helper(i + k, count - 1, arr, k);
        long int notTake = helper(i+1, count, arr, k);

        return max(take, notTake);
    }

    int getSubArraySum(int i, int j) {
        if(i == 0) {
            return prefix[j];
        }
        else if(j >= prefix.size()) {
            return INT_MIN;
        } else {
            return prefix[j] - prefix[i-1]; 
        }
    }

    // provides indexes
    void solve(int i, int count, int k, vector<int> &arr, vector<int> &res) {
        if(count == 0) return;
        if(i >= arr.size()) return;

        int takeSum = getSubArraySum(i, i + k - 1) + helper(i + k, count - 1, arr, k);
        int notTakeSum = helper(i+1, count, arr, k);

        if(takeSum >= notTakeSum) {
            res.push_back(i);
            solve(i + k, count - 1, k, arr, res);
        } else {
            solve(i + 1, count, k, arr, res);
        }
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        prefix.resize(n);
        prefix[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        vector<int> res;

        solve(0, 3, k, nums, res);
        return res;
    }
};