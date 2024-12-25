class Solution {
public:
    
    double pow(double x, int n)
    {
        if(x == 0)
        {
            return 0;
        }
        if(n == 0)
        {    
            return 1;
        }
        
        if(n == 1)
        {
            return x;
        }
        
        if( n  == -1)
        {
            return 1/x;
        }
        
        double res = pow(x, n/2);
        
        if(n % 2 == 0)
        {
            return res * res;
        }
        else
        {
            if(n < 0)
                return 1/x * res * res;
            else
            {
                return res * res * x;
            }
        }
    }
    
    double myPow(double x, int n) {
        return pow(x, n);
    }
};