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
    int pathSum(TreeNode* root, int targetSum) {
        int ans =0;
        unordered_map<long,int> cnt{{0,1}};
        auto dfs = [&](this auto&&dfs,TreeNode* node,long s){
        if(node == nullptr)return;
        s+=node->val;
        ans+=cnt.contains(s-targetSum)?cnt[s-targetSum]:0;
        cnt[s]++;
        dfs(node->left,s);
        dfs(node->right,s);
        cnt[s]--;
        };
    dfs(root,0);
    return ans;
    };
};
/*
前置题目：请先完成 560. 和为 K 的子数组（本题在数组上的情况），做法见 我的题解。

本题做法和 560 题是一样的，前缀和+哈希表。

在二叉树上，前缀和相当于从根节点开始的路径元素和。用哈希表 cnt 统计前缀和的出现次数，当我们递归到节点 node 时，设从根到 node 的路径元素和为 s，那么就找到了 cnt[s−targetSum] 个符合要求的路径，加入答案。

答疑
问：为什么要把 0 加到哈希表中？

答：这里的 0 相当于前缀和数组中的 s[0]=0。举个最简单的例子，根节点值为 1，targetSum=1。如果不把 0 加到哈希表中，按照我们的算法，没法算出这里有 1 条符合要求的路径。也可以这样理解，要想把任意路径和都表示成两个前缀和的差，必须添加一个 0，否则当路径是前缀时（从根节点开始的路径），没法减去一个数，具体见 前缀和及其扩展 中的讲解。

问：为什么代码中要先更新 ans，再更新 cnt？

答：在 targetSum

=0 的情况下，这俩谁先谁后都可以。但如果 targetSum=0，假设根节点值为 1，如果先把 cnt[1] 增加 1，再把 ans 增加 cnt[s−targetSum]=cnt[1]=1，就相当于我们找到了一条和为 targetSum=0 的路径，但和为 0 的路径是不存在的。另一种理解方式是，空路径的元素和等于 0，我们把这个 0 当作了符合要求的路径，但题目要统计的是非空路径。

问：代码中的「恢复现场」用意何在？

答：如果不恢复现场，当我们递归完左子树，要递归右子树时，cnt 中还保存着左子树的数据。但递归到右子树，要计算的路径并不涉及到左子树的任何节点，如果不恢复现场，cnt 中统计的前缀和个数会更多，我们算出来的答案可能比正确答案更大。

Python3
Java
Java 写法二
C++
Go
JavaScript
Rust
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        ans = 0
        cnt = defaultdict(int)
        cnt[0] = 1

        def dfs(node: Optional[TreeNode], s: int) -> None:
            if node is None:
                return
            nonlocal ans
            s += node.val
            ans += cnt[s - targetSum]
            cnt[s] += 1
            dfs(node.left, s)
            dfs(node.right, s)
            cnt[s] -= 1  # 恢复现场

        dfs(root, 0)
        return ans
复杂度分析
时间复杂度：O(n)，其中 n 是二叉树的节点个数。
空间复杂度：O(n)。

作者：灵茶山艾府
链接：https://leetcode.cn/problems/path-sum-iii/solutions/2784856/zuo-fa-he-560-ti-shi-yi-yang-de-pythonja-fmzo/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
