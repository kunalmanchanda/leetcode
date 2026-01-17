class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        map<int, int> mp;
        int i = 0;
        int j = 0;
        int n = nums.size();
        vector<int> res;

        while(j < n) {
            mp[nums[j]]++;

            if(j - i + 1 == k) {
                int count = 0;
                int ans = 0;
                for(int l = -50; l < 0; l++) {
                    if(mp[l] > 0) count += mp[l];
                    if(count >= x) {
                        ans = l;
                        break;
                    };
                }

                res.push_back(ans);
                mp[nums[i]]--;
                i++;
            }

            j++;
        }

        return res;
    }
};