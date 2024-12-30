class Solution {
public:

    void solve(int i, int target, vector<int> &arr, vector<int> &sub, vector<vector<int>> &res) 
    {
        if(i == arr.size())
        {
            if(target == 0)
                res.push_back(sub);
            return;
        }

        if(arr[i] <= target)
        {
            sub.push_back(arr[i]);
            solve(i, target - arr[i], arr, sub, res);
            sub.pop_back();
        }

        solve(i+1, target, arr, sub, res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sub;

        solve(0, target, candidates, sub, res);

        return res;
    }
};