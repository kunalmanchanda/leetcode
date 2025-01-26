class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        map<int, int> nge;
        stack<int> monoStack;

        for(int i = 0; i < n; i++) {
            while(!monoStack.empty() && nums2[monoStack.top()] < nums2[i]) {
                int j = monoStack.top();
                monoStack.pop();

                nge[nums2[j]] = nums2[i];
             }

            monoStack.push(i);
        }

        int m = nums1.size();
        vector<int> res(m, 0);

        for(int i = 0; i < m; i++) {
            if(nge.find(nums1[i]) != nge.end()) {
                res[i] = nge[nums1[i]];
            } else {
                res[i] = -1;
            }
        }

        return res;
    }
};