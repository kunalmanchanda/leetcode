class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();

        set<char> s;

        if(n1 != n2) {
            return false;
        }

        int cnt = 0;

        map<char, int> mp1, mp2;

        for(int i = 0; i < n1; i++) {
            if(s1[i] != s2[i]) {
                cnt++;
                mp1[s1[i]]++;
                mp2[s2[i]]++;
            }
        }

        if(cnt > 2) {
            return false; 
        }

        for(auto it: mp1) {
            if(mp2.find(it.first) == mp2.end()) {
                return false;
            }
        }

        return true;

    }
};