class Solution {
public:
    int smallestDivisor(vector<int>& arr, int threshold) {
        int low = 1, high = INT_MIN, n = arr.size();

        for(int i = 0; i < n; i++) {
            high = max(high, arr[i]);
        }

        while(low <= high) {
            int mid = (low + high)/2;
            int total = 0;

            for(int i = 0; i < n; i++) {
                total += ceil((double)arr[i]/mid);
            }

            if(total <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};