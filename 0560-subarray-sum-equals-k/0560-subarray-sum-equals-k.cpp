class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        int count = 0, n = nums.size(), prefixSum = 0;
        map<int, int> mp;

        mp[0] = 1;

        for(int i = 0; i < n; i++) {
            prefixSum += nums[i];

            if(mp.find(prefixSum - target) != mp.end()) {
                count+= mp[prefixSum - target];
            }
            mp[prefixSum]++;
        }

        return count;
    }
};