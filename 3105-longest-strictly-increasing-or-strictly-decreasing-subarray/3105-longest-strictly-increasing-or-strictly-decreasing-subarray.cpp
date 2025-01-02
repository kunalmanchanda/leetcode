class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int i = 0;
        int longestIncreasing = 1;
        int n = nums.size();

        for(int j = 1; j < n; j++) {
            if(nums[j] > nums[j-1]) {
                longestIncreasing = max(longestIncreasing, j - i + 1);
            } else {
                i = j;
            }
        }
        
        i = 0;
        int longestDecreasing = 1;

        for(int j = 1; j < n; j++) {
            if(nums[j] < nums[j-1]) {
                longestDecreasing = max(longestDecreasing, j - i + 1);
            } else {
                i = j;
            }
        }

        return max(longestDecreasing, longestIncreasing);
    }
};