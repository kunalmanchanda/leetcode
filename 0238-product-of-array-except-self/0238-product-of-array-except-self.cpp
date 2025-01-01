class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n), prefix(n), suffix(n);
        prefix[0] = arr[0];
        suffix[n-1] = arr[n-1];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] * arr[i];
        }
        
        for(int j = n - 2; j >= 0; j--) {
            suffix[j] = suffix[j+1] * arr[j];
        }

        for(int i = 0; i < n; i++) {
            if(i == 0) {
                res[i] = suffix[i+1];
            }
            else if(i == n-1) {
                res[i] = prefix[i-1];
            }
            else {
                res[i] = prefix[i-1] * suffix[i+1];
            }
        }

        return res;
    }
};