class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();

        int i = 0;
        int minPositionIndex = -1;
        int maxPositionIndex = -1;
        int culpritIndex = -1;
        long long res;

        while(i < n) {
            int element = nums[i];

            if(element < minK || element > maxK)
                culpritIndex = i;
            if(element == minK)
                minPositionIndex = i;
            if(element == maxK)
                maxPositionIndex = i;
            
            long long ans = min(maxPositionIndex, minPositionIndex) - culpritIndex;

            res += (ans < 0 ? 0 : ans);

            i++;
        } 

        return res;
    }
};