class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int res = -1;

        int aiplusi = values[0] + 0;

        for(int i = 1; i < n; i++) {
            int aimiusi = values[i] - i;
            res = max(res, aiplusi + aimiusi);
            aiplusi = max(aiplusi, values[i] + i);
        }
        
        return res;
    }
};