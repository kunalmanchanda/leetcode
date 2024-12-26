class Solution {
public:

/**
 * @param {number} n
 * @return {boolean}
 */
    bool checking(int n, int b) {
        string palindrome = "";
        while(n) {
            int rem = n % b;
            n = n / b;
            if(rem == 1) {
                palindrome = "1" + palindrome;
            } else {
                palindrome = "0" + palindrome;
            }
        }

        int i = 0, j = palindrome.size() - 1;

        while(i < j) {
            if(palindrome[i] != palindrome[j]) {
                return false;
            }
        }

        return true;
    }

    bool isStrictlyPalindromic(int n) {
        for(int b = 2; b <= n - 2; b++) {
            if(checking(n, b) == false){
                return false;
            }
        }

        return true;
    }
};