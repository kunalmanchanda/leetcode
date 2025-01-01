class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = 100000;
        int n = nums.size();
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

        return res == 100000 ? 0 : res;
    }
};

// 2, 3, 1, 2,  4, 3  +-+-+-+ 2, 5, 6, 8, 12, 15
// 1, 2, 3, 4, 5              1, 3, 6, 10, 15
// 10, 2, 3           10, 12, 15