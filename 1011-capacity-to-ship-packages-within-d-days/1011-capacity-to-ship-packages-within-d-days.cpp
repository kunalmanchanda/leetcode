class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0, n = weights.size();

        for(int i = 0; i < n; i++) {
            high += weights[i];
            low = max(low, weights[i]);
        }

        while(low <= high) {
            int mid = (low + high)/2;

            int totalDays = 0;
            int count = 0;

            for(int i = 0; i < n; i++) {
                count += weights[i];
                if(count > mid){
                    totalDays++;
                    count=weights[i];
                }
            }

            if(totalDays < days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};