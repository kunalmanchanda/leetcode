class Solution {
    int m, k;
    vector<vector<long>> freq;
    vector<vector<long>> dp;
    int mod = (int)1e9+7;

public:
    int waysTotal(int i, int j, string &target) {
        if(i == m) return 1;
        if(j == k) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int not_taken = waysTotal(i, j + 1, target)%mod;
        int taken = freq[target[i] - 'a'][j] * waysTotal(i + 1, j + 1, target)%mod;
        
        return dp[i][j] = (taken+ not_taken)%mod;
    }
    int numWays(vector<string>& words, string target) {
        m = target.length();
        k = words[0].length();

        freq.resize(26, vector<long>(k, 0));
        dp.resize(m + 1, vector<long>(k + 1, -1));

        for(int col = 0; col < k; col++) {
            for(string &word: words) {
                char ch = word[col];
                freq[ch - 'a'][col]++;
            }
        }

        return waysTotal(0, 0, target);
    }
};