class Solution {
public:
    void merge(int low, int mid, int high, vector<int> &nums) {
        int left = low, right = mid + 1;
        vector<int> temp;

        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while(left <= mid) {
            temp.push_back(nums[left++]);
        }

        while(right <= high) {
            temp.push_back(nums[right++]);
        }

        for(int k = low, j = 0; k <= high; k++, j++) {
            nums[k] = temp[j];
        }
    }

    void mergeSort(int low, int high, vector<int> &nums) {
        if(low >= high) {
            return;
        }

        int mid = low + (high - low)/2;

        mergeSort(low, mid, nums);
        mergeSort(mid + 1, high, nums);

        merge(low, mid, high, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size() - 1, nums);
        return nums;
    }
};