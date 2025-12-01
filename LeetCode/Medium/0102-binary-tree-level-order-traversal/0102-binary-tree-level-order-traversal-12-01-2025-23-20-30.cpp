/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int> sub;            
            while(n--)
            {
                TreeNode* root= q.front();
                q.pop();
                
                if(root->left != NULL)
                    q.push(root->left);
                if(root->right != NULL)
                    q.push(root->right);
                sub.push_back(root->val);
            }
            res.push_back(sub);
        }
        
        return res;
    }
};