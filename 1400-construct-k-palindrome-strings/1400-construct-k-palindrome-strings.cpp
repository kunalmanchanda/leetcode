class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() == k) return true;
        if(s.length() < k) return false;

        map<char, int> mp;

        for(auto it: s) {
            mp[it]++;
        }

        int odd = 0;

        for(auto it: mp) {
            if(it.second % 2 != 0) {
                odd++;
            }
        }


        if(odd > k) {
            return false;
        }

        return true;
    }
};