class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int res = -1;

        vector<int> maxi(n, INT_MIN);
        vector<int> mini(n, -1);

        maxi[0] = values[0] + 0;

        for(int i = 1; i < n; i++) {
            maxi[i] = max(maxi[i - 1], values[i] + i);
        }

        for(int j = 1; j < n; j++) {
            mini[j] =  values[j] - j;
        }

        int i = 0, j = 1;

        while(j < n) {
            res = max(res, maxi[i] + mini[j]);
            j++;
            i++;
        }

        return res;
    }
};