class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];

        for(int i = 1, j = n - 2; i < n, j >= 0; i++, j--) {
            leftMax[i] = max(leftMax[i-1], height[i]);
            rightMax[j] = max(rightMax[j+1], height[j]);
        }

        int sum = 0;
        for(int i = 1; i < n - 1; i++)
            sum += min(leftMax[i], rightMax[i]) - height[i];

        return sum;
    }
};