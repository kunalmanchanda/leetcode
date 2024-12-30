class Solution {

public:
    int threeSumClosest(vector<int>& arr, int target) {
        int n = arr.size();

        sort(arr.begin(), arr.end());
 
        int res = 1000000;

        for(int k = 0; k <= n-3; k++) {
            int i = k + 1;
            int j = n - 1;
            
            while(i < j) {
                int sum = arr[i] + arr[j] + arr[k];
                
                if(abs(target - sum) < abs(target - res)) {
                    res = sum;
                }

                if(sum < target) {
                    i++;
                } else {
                    j--;
                }
            }
        }

        return res;
    }
};