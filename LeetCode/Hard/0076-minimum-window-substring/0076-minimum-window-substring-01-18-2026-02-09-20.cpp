class Solution {
public:
    string minWindow(string s, string t) 
    {
        map<char,int> mp;
        
        for(int i = 0; i < t.length(); i++)
        {
            mp[t[i]]++;
        }
        
        int count = 0;
        string res;
        int ans = 10000000;
        int i = 0,j = 0;
        
        for(int i =0; i < s.length(); i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                //  char are in sub str
                if(mp[s[i]] > 0)
                    count++;
                mp[s[i]]--;
            }
            
            while(count == t.length())
            {
                if(ans > i-j+1)
                {
                    ans = i-j+1;
                    res = s.substr(j,i-j+1);
                }
                
                if(mp.find(s[j]) != mp.end())
                {
                    mp[s[j]]++;
                    if(mp[s[j]] > 0)
                        count--;
                }
                j++;
            }
        }
        return res;
    }
};