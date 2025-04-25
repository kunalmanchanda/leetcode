class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size() - 1;
        int m = b.size() - 1;
        int carry = 0;
        string res = "";

        while(n >= 0 ||  m >= 0 || carry) {
            int sum = (n >= 0 ? a[n] - '0' : 0) + (m >= 0 ? b[m] - '0' : 0) + carry;

            if(sum == 0) {
                res = '0' + res;
                carry = 0;
            } else if(sum == 1) {
                res = '1' + res;
                carry = 0;
            } else if(sum == 2) {
               res = '0' + res;
                carry = 1;
            } else {
                res = '1' + res;
                carry = 1;
            }

            n--;
            m--;
        }

        return res;
    }
};