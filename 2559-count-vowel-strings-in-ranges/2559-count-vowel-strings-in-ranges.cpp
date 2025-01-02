class Solution {
public:
    bool checkVowel(string str) {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        int s = str.length() - 1;

        bool start = false, end = false;

        for(int i = 0; i < 5; i++) {
            if(str[s] == vowels[i]) {
                end = true;
            }

            if(str[0] == vowels[i]) {
                start = true;
            }
        }

        return start && end;

    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();

        vector<int> arr(n, 0);

        for(int i = 0; i < n; i++) {
            if(i == 0) {
                if(checkVowel(words[i])) {
                    arr[i] = 1;
                }
            } else {
                if(checkVowel(words[i])) {
                    arr[i] = arr[i-1] + 1;
                } else {
                    arr[i] = arr[i-1];
                }
            }
        }

        vector<int> res;

        for(auto it: queries) {
            int l = it[0], r = it[1];

            if(l == 0) {
                res.push_back(arr[r]);
            } else {
                res.push_back(arr[r] - arr[l - 1]);
            }
        }

        return res;
    }
};