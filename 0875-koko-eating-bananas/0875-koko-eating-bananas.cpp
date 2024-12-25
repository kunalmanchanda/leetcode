class Solution {
    bool isPossible(vector<int>& piles, int h, int k) {
        long int res = 0;

        for(auto it: piles) {
            res += ceil((long double)it/k);
        }

        return res <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = 0;
        int low = 1;

        for(auto it: piles) {
            high = max(high, it);
        }

        while(low <= high) {
            int mid = (low + high)/2;

            if(isPossible(piles, h, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};