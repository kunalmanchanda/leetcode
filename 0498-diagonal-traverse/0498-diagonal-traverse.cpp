class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        
        int n = mat.size();
        int m = mat[0].size();

        if(n == 0 || m == 0)
            return res;

        int row = 0;
        int col = 0;

        bool flag = true;

        while(row < n && col < m)
        {
            if(flag)
            {
                while(row > 0 && col < m-1)
                {
                    res.push_back(mat[row][col]);
                    row--;
                    col++;
                }

                res.push_back(mat[row][col]);

                if(col == m-1)
                    row++;
                else
                    col++;
            }
            else
            {
                while(row < n-1 && col > 0)
                {
                    res.push_back(mat[row][col]);
                    row++;
                    col--;
                }

                res.push_back(mat[row][col]);

                if(row == n-1)
                    col++;
                else
                    row++;
            }

            flag = !flag;
        }

        return res;
    }
};