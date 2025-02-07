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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(0,nums.size()-1,nums);
    }
    TreeNode* BST(int l,int r,vector<int>& nums){
        if(l>r)return nullptr;
        int mid = (l+r)/2;
        TreeNode* res = new TreeNode(nums[mid]);
        //区间为[l,mid],[mid+1,r]，但不能是[l,mid-1],[mid,r]
        //例如mid=2 012 34 向下取整/2后 mid1 mid3可以
        //但是01 234 mid0 mid3?????????????????????????????????
        //他妈的 不如左闭右闭
        res->left = BST(l,mid-1,nums);
        res->right = BST(mid+1,r,nums);
        return res;
    }
};
