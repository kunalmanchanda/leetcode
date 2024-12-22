class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            int ele = nums[i];
            int digitCount = 0;

            while(ele) {
                ele = ele/10;
                digitCount++;
            }

            if(digitCount % 2 == 0) {
                count++;
            }
        }
        
        return count;
    }

};