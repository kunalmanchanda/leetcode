class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s;
        }

        string res = "";
        
        int div = 2 * (numRows - 1);
        int n = s.length();

        int currRow = 0;

        while(currRow < numRows) {
            int index = currRow;

            while(index < n) {
                res += s[index];

                if(currRow != 0 && currRow != numRows - 1) {
                    int nextIndex = index + div - 2 * currRow;

                    if(nextIndex < n) {
                        res += s[nextIndex];
                    }
                }

                index += div;
            }
            currRow++;
        }

        return res;
    }
};