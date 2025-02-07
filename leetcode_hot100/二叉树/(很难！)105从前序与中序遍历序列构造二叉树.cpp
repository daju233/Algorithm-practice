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
     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         if(preorder.empty()){
             return nullptr;
         }
         int left_size = ranges::find(inorder,preorder[0])-inorder.begin();
         vector<int> pre1(preorder.begin() + 1, preorder.begin() + 1 + left_size);
         vector<int> pre2(preorder.begin() + 1 + left_size, preorder.end());
         vector<int> in1(inorder.begin(), inorder.begin() + left_size);
         vector<int> in2(inorder.begin() + 1 + left_size, inorder.end());
         TreeNode* left = buildTree(pre1, in1);
         TreeNode* right = buildTree(pre2, in2);
         return new TreeNode(preorder[0], left, right);
     }
 };
/*
复杂度分析
时间复杂度：O(n 2)，其中 n 为 preorder 的长度。最坏情况下二叉树是一条链，我们需要递归 O(n) 次，每次都需要 O(n) 的时间查找 preorder[0] 和复制数组。
空间复杂度：O(n 2)。
*/

/*
两个优化点：
用一个哈希表（或者数组）预处理 inorder 每个元素的下标，这样就可以 O(1) 查到 preorder[0] 在 inorder 的位置，从而 O(1) 知道左子树的大小。
把递归参数改成子数组下标区间（左闭右开区间）的左右端点，从而避免复制数组。
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }

        auto dfs = [&](this auto&& dfs, int pre_l, int pre_r, int in_l, int in_r) -> TreeNode* {
            if (pre_l == pre_r) { // 空节点
                return nullptr;
            }
            int left_size = index[preorder[pre_l]] - in_l; // 左子树的大小
            TreeNode* left = dfs(pre_l + 1, pre_l + 1 + left_size, in_l, in_l + left_size);
            TreeNode* right = dfs(pre_l + 1 + left_size, pre_r, in_l + 1 + left_size, in_r);
            return new TreeNode(preorder[pre_l], left, right);
        };
        return dfs(0, n, 0, n); // 左闭右开区间
    }
};
/*
作者：灵茶山艾府
链接：https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solutions/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
