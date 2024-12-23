class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int index = 0;
        int leftSum = 0;
        int rightSum = 0;
        int n = nums.size();

        for(int i = 1; i < n; i++) {
            rightSum += nums[i];
        }

        while(leftSum != rightSum && index < n - 1) {
            leftSum += nums[index];
            rightSum -= nums[index + 1];
            index++;
        }

        return leftSum == rightSum ? index: -1;
    }
};