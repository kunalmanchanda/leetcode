class Solution {
public:
    int countPalindromicSubsequence(string s) {
        set<char> chars;

        for(auto it: s) {
            chars.insert(it);
        }

        int res = 0;

        for(auto it: chars) {
            char val = it;
            int i = 0, j = s.length() - 1;

            while(s[i] != val) i++;
            while(s[j] != val) j--;
            i++;
            set<char> unique;

            while(i < j) {
                unique.insert(s[i]);
                i++;
            }

            res += unique.size();
        }

        return res;
    }
};