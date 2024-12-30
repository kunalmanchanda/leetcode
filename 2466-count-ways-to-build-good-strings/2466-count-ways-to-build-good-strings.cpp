class Solution {
    int lows, highs, ones, zeros;
    const int mod = 1e9+7;
    vector<int> dp;
public:
    int solve(int length) {
        if(length > highs) return 0;
        if(dp[length] != -1) return dp[length];

        int addOne = 0;
        if(length >= lows && length <= highs) {
            addOne = 1;
        }

        return dp[length] = (addOne + solve(length + zeros) % mod + solve(length + ones) % mod) % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        lows = low, highs = high, ones = one, zeros = zero;

        dp.assign(highs + 1, -1);
        
        return solve(0);
    }
};