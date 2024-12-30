class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());

        for(int i = 0; i < n; i++) {
            if(i != 0 && arr[i] == arr[i-1]) continue;

            int target = -arr[i];
            int j = i + 1;
            int k = n - 1;

            while(j < k) {
                if(arr[j] + arr[k] > target) {
                    k--;
                } else if(arr[j] + arr[k] < target) {
                    j++;
                } else {
                    while(j < k && arr[j] == arr[j+1]) j++;

                    while(j < k && arr[k] == arr[k-1]) k--;

                    res.push_back({-target, arr[j], arr[k]});
                    j++;
                    k--;
                }
            }
        }
        
        return res;
    }
};