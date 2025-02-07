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
 //关键，BST中序遍历是升序
 //中序遍历——先遍历左边（左子树），再处理根节点（中间），最后遍历右边（右子树）
class Solution {
    vector<int> res;
public:
    bool isValidBST(TreeNode* root) {
        dfs(root);
        for(int i=1;i<res.size();i++){
            if(res[i]<=res[i-1])return false;
        }
        return true;
    }
    void dfs(TreeNode* root){
        if(root==nullptr)return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }
};
// class Solution {
//     int pre = -1145141919;
// public:
//     bool isValidBST(TreeNode* root) {
//         if(!root)return true;

//         if(!isValidBST(root->left)){
//                 return false;
//             }

//         if(root->val<=pre)return false;

//         pre = root->val;

//         return isValidBST(root->right);
//     }
//     //一个更简洁（字更少）的写法
// };
