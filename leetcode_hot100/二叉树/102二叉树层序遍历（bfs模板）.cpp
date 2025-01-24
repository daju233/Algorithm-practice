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
    queue<TreeNode*> Q;
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)return res;
        Q.push(root);
        while(!Q.empty()){
            vector<int> tmp;
            int len =Q.size();
            for(int i =0;i<len;i++){
                TreeNode* node = Q.front();
                Q.pop();
                tmp.push_back(node->val);
                if(node->left)Q.push(node->left);
                if(node->right)Q.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
