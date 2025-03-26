class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        map<int, vector<int>> mp;

        vector<int> res;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                mp[row + col].push_back(mat[row][col]);
            }
        }

        bool flip = true;

        for(auto &it: mp) {
            if(flip) {
                reverse(it.second.begin(), it.second.end());
            }

            for(int &num: it.second) {
                res.push_back(num);
            }

            flip = !flip;
        }

        return res;
    }
};