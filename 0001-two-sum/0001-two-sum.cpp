class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> res(2, -1);
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(mp.find(target - nums[i]) != mp.end()) {
                res[0] = mp[target - nums[i]];
                res[1] = i;
                break;
            }

            mp.insert({nums[i], i});
        }

        return res;
    }
};