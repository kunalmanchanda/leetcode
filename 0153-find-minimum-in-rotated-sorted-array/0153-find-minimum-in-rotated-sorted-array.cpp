class Solution {
public:
    int findPivot(vector<int> arr) {
        int start = 0;
        int n = arr.size();
        int end = n - 1;
        
        int mid;
        
        while(start < end) {
            mid = start + (end - start)/2;
            if(mid + 1 < n && arr[mid] > arr[mid+1])
                return mid;
            else if(mid - 1 >= 0 && arr[mid-1] > arr[mid])
                return mid-1;
            else if(arr[start] > arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        
        return -1;
    }
    int findMin(vector<int>& arr) {
        int pivot = findPivot(arr);
        
        if(pivot != -1)
            return arr[pivot+1];
        else 
            return arr[0];
    }
};