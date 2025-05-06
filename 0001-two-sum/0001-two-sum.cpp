class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            if(mp.find(target - nums[i]) != mp.end()) {
                res[0] = mp[target - nums[i]];
                res[1] = i;
                break;
            }

            mp[nums[i]] = i;
        }

        return res;
    }
};