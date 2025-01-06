class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), j = 0;
        vector<int> res(n, 0);

        for(int i = 0; i < n; i++) {
            if(boxes[i] == '1') {
                j = 0;
                while(j < n) {
                    res[j] += abs(j-i);
                    j++;
                }
            }
        }

        return res;
    }
};