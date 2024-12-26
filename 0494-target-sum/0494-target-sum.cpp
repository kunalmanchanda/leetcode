class Solution {
    int targetSum(vector<int> &arr, int i, int n, int k, int res) {
        if(i == n) {
            if(k == res) {
                return 1;
            }
            return 0;
        }

        return targetSum(arr, i + 1, n, k - arr[i], res) 
                + targetSum(arr, i + 1, n, k + arr[i], res);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        return targetSum(nums, 0, n, 0, target);
    }
};