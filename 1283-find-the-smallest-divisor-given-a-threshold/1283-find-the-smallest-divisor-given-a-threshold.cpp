class Solution {
public:
    int smallestDivisor(vector<int>& arr, int threshold) {
        int low = 1, high = *max_element(arr.begin() , arr.end()), n = arr.size();

        while(low <= high) {
            int mid = (low + high)/2;
            int total = 0;

            for(int i = 0; i < n; i++) {
                total += (arr[i]+mid-1)/mid;;
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