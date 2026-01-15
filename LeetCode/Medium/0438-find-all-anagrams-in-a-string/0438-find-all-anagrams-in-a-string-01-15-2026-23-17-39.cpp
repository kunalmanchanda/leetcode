class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        map<char,int> count;
        vector<int> res;

        for(int i = 0; i < m; i++) {
            count[p[i]]++;
        }

        int i = 0, j = 0;

        while(j < n && i < n){
            count[s[j]]--;

            if(j - i + 1 == m) {
                bool flag = true;

                for(auto it: count) {
                    if(it.second != 0) {
                        flag = false;
                    }
                }

                if(flag) {
                    res.push_back(i);
                }

                if(count.find(s[i]) != count.end()) {
                    count[s[i]]++;
                }
                
                i++;
            }

            j++;
        }


        return res;
    }
};