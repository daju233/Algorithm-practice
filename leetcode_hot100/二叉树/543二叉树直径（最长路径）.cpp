DFS
定义全局变量 ans（初始化为 0），用于记录二叉树的最大直径。

设计用于遍历二叉树的 DFS 函数：函数传入当前节点 u，返回以该节点为根时，方向“往下”的最大路径节点数量（注意这里是点数，而不是题目要求的边数）。

单次执行流程中，先递归处理当前节点 u 的左右节点，得到左右子树为根时的“往下”最大路径 l 和 r，两者中的较大值 +1 即是本次执行流程的返回值（+1 的含义是在子路径基础上增加当前节点）。

同时，l + r 则是以当前节点 u 为路径最高点时的路径长度，用此更新全局 ans 即可。

作者：宫水三叶
链接：https://leetcode.cn/problems/diameter-of-binary-tree/solutions/2454405/gong-shui-san-xie-jian-dan-dfs-yun-yong-vbf27/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

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
    int ans = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root){
        if(root==nullptr)return 0;
        int l=dfs(root->left),r=dfs(root->right);//求左右子树分别的最长路径
        ans = max(ans,l+r);//用当前节点更新
        return max(l,r)+1;//返回当前节点的左右子树中的最长路径
    }
};
