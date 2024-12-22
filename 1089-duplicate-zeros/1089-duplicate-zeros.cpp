class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int zeroCount = 0;
        int lastIdx = arr.size() - 1;

        for(int i = 0; i <= lastIdx - zeroCount; i++) {
            if(arr[i] == 0) {
                if(i == lastIdx - zeroCount) {
                    arr[lastIdx] = 0;
                    lastIdx--;
                    break;
                }
                zeroCount++;
            }
        }

        int r = lastIdx - zeroCount;

        for(int i = r; i >= 0; i--) {
            if(arr[i] == 0) {
                arr[i + zeroCount] = 0;
                zeroCount--;
                arr[i + zeroCount] = 0;
            }
            arr[i + zeroCount] = arr[i];
        }
    }
};