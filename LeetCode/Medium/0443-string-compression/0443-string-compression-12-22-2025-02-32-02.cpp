class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        int i = 0;

        while(i < chars.size()) {
            char currentChar = chars[i];
            int count = 0;


            while(i < chars.size() && currentChar == chars[i]) {
                count++;
                i++;
            }

            chars[index++] = currentChar;

            if(count > 1) {
                string cnt = to_string(count);

                for(char ch: cnt) {
                    chars[index++] = ch;
                }
            }
        }

        return index;
    }
};