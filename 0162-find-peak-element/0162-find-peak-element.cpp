class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int low = 0, n = arr.size(), high = n - 1;

        while(low < high) {
            int mid = (low + high)/2;

            if(arr[mid] > arr[mid + 1]) {
                high =  mid;
            } else {
                low = mid + 1;
            }
        }

        return high;
    }
};