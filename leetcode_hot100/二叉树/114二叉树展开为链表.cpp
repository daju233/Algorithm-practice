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
    vector<TreeNode*> res;
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        dfs(root);
        int size = res.size();
        for(int i=0;i<size-1;i++){
            res[i]->left = nullptr;
            res[i]->right = res[i+1];
        }
        root = res[0];
    }
    void dfs(TreeNode* root){
        if(root==nullptr)return;
        res.push_back(root);
        dfs(root->left);
        dfs(root->right);
    }
};
