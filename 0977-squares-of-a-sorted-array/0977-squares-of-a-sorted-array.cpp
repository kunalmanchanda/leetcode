class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        int right = n - 1;
        int index = n - 1;
        vector<int> res(n, -1);

        while(left <= right) {
            if(abs(nums[left]) > abs(nums[right])) {
                res[index--] = pow(nums[left++], 2);
            } else {
                res[index--] = pow(nums[right--], 2);
            }
        }

        return res;
    }
};