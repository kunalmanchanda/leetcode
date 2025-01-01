class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0;
        int n = s.length();
        for(int i = 1; i < n; i++) {
            if(s[i] == '1') {
                ones++;
            }
        }

        if(s[0] == '0') {
            zeros++;
        }

        int res = ones + zeros;

        int j = 2;

        while(j < n) {
            if(s[j - 1] == '0') {
                zeros++;
            } else {
                ones--;
            }

            res = max(res, ones + zeros);
            j++;
        }

        return res;
    }
};