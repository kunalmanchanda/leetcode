class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int i = 0, j = arr.size() - 1;

        while(i < j) {
            if(arr[i] + arr[j] == target) {
                break;
            } else if(arr[i] + arr[j] > target) {
                j--;
            } else {
                i++;
            }
        }

        vector<int> res(2, -1);
        res[0] = i + 1;
        res[1] = j + 1;

        return res;
    }
};