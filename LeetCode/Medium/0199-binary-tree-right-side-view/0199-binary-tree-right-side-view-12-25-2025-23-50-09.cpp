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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        if(root == NULL) {
            return res;
        }

        while(!q.empty()) {
            int size = q.size();

            if(size) {
                res.push_back(q.front()->val);
            }

            while(size--) {
                TreeNode *temp = q.front();
                q.pop();
             

                if(temp->right) {
                    q.push(temp->right);
                }

                if(temp->left) {
                    q.push(temp->left);
                }            
            }
        }

        return res;
    }
};