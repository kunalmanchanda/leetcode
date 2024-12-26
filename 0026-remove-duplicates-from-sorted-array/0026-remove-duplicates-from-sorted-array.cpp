class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int track = 0;
        int n = arr.size();

        if(n <= 1) {
            return n;
        }

        arr[track++] = arr[0];

        for(int i = 0; i < n - 1; i++) {
            if(arr[i] == arr[i+1]) {
                continue;
            } else {
                arr[track++] = arr[i+1];
            }
        }

        if(track == 0) {
            return 1;
        }

        return track;
    }
};