class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diffArray(n+1, 0);

        for(auto shift: shifts) {
            if(shift[2] == 0) {
                diffArray[shift[0]]--;
                diffArray[shift[1] + 1]++;
            } else {
                diffArray[shift[0]]++;
                diffArray[shift[1] + 1]--;
            }
        }

        for(int i = 1; i < n; i++) {
            diffArray[i] += diffArray[i-1];
        }

        for(int i = 0; i < n; i++) {
            int count = diffArray[i] % 26;
            if(count < 0) {
                count = count + 26;
            }

            s[i] = char((s[i] - 'a' + count)%26 + 97);
        }

        return s;
    }
};