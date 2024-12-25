class Solution {
    bool isPossible(vector<int>& bloomDay, int m, int k, int mid) {
        int n = bloomDay.size();
        vector<bool> arr(n, false);

        for(int i = 0; i < n; i++) {
            if(bloomDay[i] <= mid) {
                arr[i] = true;
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i]) {
                count++;
                if(count == k){
                    m--;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        return m <= 0;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if((long double)m * (long double)k > (long double)n) {
            return -1;
        }

        int low = -1;
        int high = -1;
        int ans = -1;

        for(auto it: bloomDay) {
            high = max(high, it);
            low = min(low, it);
        }

        while(low <= high) {
            int mid = (low + high) / 2;

            if(isPossible(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};