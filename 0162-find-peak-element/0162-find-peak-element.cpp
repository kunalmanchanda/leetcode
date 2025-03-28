class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();

        if(n == 1 || arr[0] > arr[1]) {
            return 0;
        }

        if(arr[n-1] > arr[n-2]) {
            return n - 1;
        }

        int low = 1;
        int high = n - 2;
        int mid;

        while(low <= high) {
            mid = (low + high)/2;

            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if(arr[mid - 1] <= arr[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return mid;
    }
};