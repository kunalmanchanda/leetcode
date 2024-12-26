class Solution {
public:
    int minimumDeletions(string str) {
        stack<char> s;
        int count = 0;
        s.push(str[0]);

        for(int i = 1; i < str.length(); i++) {
            if(!s.empty() && s.top() == 'b' && str[i] == 'a') {
                count++;
                s.pop();
            } else {
                s.push(str[i]);
            }
        }

        return count;
    }
};