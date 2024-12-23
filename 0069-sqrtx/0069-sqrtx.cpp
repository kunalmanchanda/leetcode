class Solution {
public:
    int mySqrt(int x) 
    {
        int start = 0;
        int end = x;
        int res;

        while(start <= end)
        {
            long long int mid = start + (end - start)/2;

            if(mid*mid < x)
            {
                res = mid;
                start = mid + 1;
            }
            else if(mid*mid > x)
            {
                end = mid - 1;
            }
            else
            {
                res = mid;
                break;
            }
        }

        return res;
    }
};