class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int l1 = -1;
        int l2 = -1;

        while(low <= high) {
            int mid = (low+ high)/2;

            if(nums[mid] <= target) {
                l1 = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if(l1 == -1 || nums[l1] != target) {
            return { -1, -1 };
        }

        low = 0;
        high = nums.size() - 1;
        
        while(low <= high) {
            int mid = (low + high)/2;

            if(nums[mid] >= target) {
                l2 = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return {l2, l1};
    }
};