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
    int res = -1100;
    int maxPathSum(TreeNode* root) {
        int acc = dfs(root);
        return max(res,acc);
    }
    int dfs (TreeNode* root){
        if(root==nullptr)return -1100;
        int l = dfs(root->left);
        int r = dfs(root->right);
        res = max(res,l);//左边比较大
        res = max(res,r);//右边比较大
        res = max(res,l+r+root->val);//整个子树比较大

        int acc = root->val;
        acc = max(acc,root->val+l);//加上左边大
        acc = max(acc,root->val+r);//加上右边大
        //不加最大
        return acc;
    }
};
/*
https://leetcode.cn/problems/binary-tree-maximum-path-sum/description/comments/690627/
*/

/*
不用看官方题解，那么复杂。 所有树的题目，都想成一颗只有根、左节点、右节点 的小树。然后一颗颗小树构成整棵大树，所以只需要考虑这颗小树即可。接下来分情况， 按照题意：一颗三个节点的小树的结果只可能有如下6种情况：

1 根 + 左 + 右
2 根 + 左
3 根 + 右
4 根
5 左
6 右
好了，分析上述6种情况， 只有 2,3,4 可以向上累加，而1,5,6不可以累加（这个很好想，情况1向上累加的话，必然出现分叉，情况5和6直接就跟上面的树枝断开的，没法累加），所以我们找一个全局变量存储 1,5,6这三种不可累加的最大值， 另一方面咱们用遍历树的方法求2,3,4这三种可以累加的情况。 最后把两类情况得到的最大值再取一个最大值即可。
*/

