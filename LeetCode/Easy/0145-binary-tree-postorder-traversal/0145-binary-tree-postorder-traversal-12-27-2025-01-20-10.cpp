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
    // Left Right Root = reverse(Root Right Left)
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> res;

        while(true) {
            if(node != NULL) {
                res.push_back(node->val);
                st.push(node);
                node = node->right;
            } else {
                if(st.empty()) break;
                node = st.top();
                st.pop();
                node = node->left;
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};