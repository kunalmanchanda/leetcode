class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mini = 1000;

        while(low <= high) {
            int mid = (low + high)/2;
            mini = min(mini, nums[mid]);

            if(nums[low] <= nums[mid]) {
                mini = min(mini, nums[low]);
                low = mid + 1;
            } else {
                mini = min(mini, nums[mid+1]);
                high = mid - 1;
            }
        }

        return mini;
    }
};