class Solution {
public:
    int waysToSplitArray(vector<int>& arr) {
        int sum = 0, n = arr.size();
        vector<int> pre(n, 0);

        for(int i = 0; i < n; i++) {
            sum += arr[i];
            pre[i] = sum;
        }

        int res = 0;
        for(int i = 0; i < n - 1; i++) {
            if(pre[i] >= sum - pre[i]) {
                res++;
            }
        }

        return res;
    }
};