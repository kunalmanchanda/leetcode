class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int track = 1;
        int i = 0;
        int count = 0;
        int n = arr.size();

        while(true) {
            if(i >= n || arr[i] > track) {
                count++;
            } else if(arr[i] == track) {
                i++;
            }

            if(count == k) {
                return track;
            }
            
            track++;
        }

        return 0;
    }
};