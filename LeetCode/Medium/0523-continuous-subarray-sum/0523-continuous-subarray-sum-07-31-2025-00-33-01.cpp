class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        unordered_map<int, int> modulo_index_freq;

        modulo_index_freq[0] = -1;

        for(int i = 0; i < n; i++) {
            sum += nums[i];

            int remainder = sum % k;

            if(modulo_index_freq.find(remainder) != modulo_index_freq.end()) {
                if(i - modulo_index_freq[remainder] >= 2) {
                    return true;
                }
            } else {
                modulo_index_freq[remainder] = i;
            }
        }
        return false;
    }
};