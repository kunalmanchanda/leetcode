class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        map<int, bool> mp;

        for(auto it: nums) {
            mp[it] = true;
        }

        while(mp.find(original) != mp.end()) {
            original *= 2;
        }

        return original;
    }
};