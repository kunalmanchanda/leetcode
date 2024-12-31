class Solution {
public:
    int clumsy(int n) {
        stack<int> s;
        int count = 0;
        s.push(n);

        for(int i = n - 1; i >= 1; i--) {
            if(count == 0) {
                int ele = s.top();
                s.pop();
                s.push(ele * i);
            }
            else if(count == 1) {
                int ele = s.top();
                s.pop();
                s.push(ele / i);
            }
            else if(count == 2) {
                s.push(i);
            }
            else {
                s.push(i * -1);
            }
            count = (count + 1) % 4;
        }

        int ans = 0;

        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }

        return ans;
    }
};