class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX, n = nums.size();
        vector<int> arr(n, -1);

        for(int i = 0; i < n; i++) {
            if(i == 0) {
                arr[i] = nums[i];
            } else {
                arr[i] = arr[i - 1] + nums[i];
            }
            if(arr[i] >= target) {
                res = min(res, i + 1);
            }
        }

        int i = 0, j = 0;

        while(i <= j && j < n) {
            if(arr[j] - arr[i] < target) {
                j++;
            } else if(arr[j] - arr[i] >= target) {
                res = min(res, j-i);
                i++;
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};
