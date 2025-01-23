/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vec;
        if(lists.size()==0)return nullptr;
        for(ListNode* list:lists){
            if(list==nullptr)continue;
            ListNode* head = list;
            while(head){
                vec.push_back(head->val);
                head=head->next;
            }
        }
        sort(vec.begin(),vec.end());
        ListNode* dummy = new ListNode(0);
        ListNode* res = dummy;
        for(int num:vec){
            ListNode* newnode = new ListNode(num);
            res->next = newnode;
            res = newnode;
        }
        return dummy->next;
    }
};//数组转链表 暴力
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode* > &lists) {
        auto cmp = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val; // 最小堆
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
        for (auto head: lists) {
            if (head) {
                pq.push(head);
            }
        }

        ListNode dummy{}; // 哨兵节点，作为合并后链表头节点的前一个节点
        auto cur = &dummy;
        while (!pq.empty()) { // 循环直到堆为空
            auto node = pq.top(); // 剩余节点中的最小节点
            pq.pop();
            if (node->next) { // 下一个节点不为空
                pq.push(node->next); // 下一个节点有可能是最小节点，入堆
            }
            cur->next = node; // 合并到新链表中
            cur = cur->next; // 准备合并下一个节点
        }
        return dummy.next; // 哨兵节点的下一个节点就是新链表的头节点
    }
};

//我觉得一口气把所有节点加到堆里比较符合我的想法
/*
方法一：最小堆
合并后的第一个节点 first，一定是某个链表的头节点（因为链表已按升序排列）。

合并后的第二个节点，可能是某个链表的头节点，也可能是 first 的下一个节点。

例如有三个链表 1->2->5, 3->4->6, 4->5->6，找到第一个节点 1 之后，第二个节点不是另一个链表的头节点，而是节点 1 的下一个节点 2。

按照这个过程继续思考，每当我们找到一个节点值最小的节点 x，就把节点 x.next 加入「可能是最小节点」的集合中。

因此，我们需要一个数据结构，它支持：

从数据结构中找到并移除最小节点。
插入节点。
这可以用最小堆实现。初始把所有链表的头节点入堆，然后不断弹出堆中最小节点 x，如果 x.next 不为空就加入堆中。循环直到堆为空。把弹出的节点按顺序拼接起来，就得到了答案。

实现时，可以用哨兵节点简化代码，具体请看【基础算法精讲 06】。

作者：灵茶山艾府
链接：https://leetcode.cn/problems/merge-k-sorted-lists/solutions/2384305/liang-chong-fang-fa-zui-xiao-dui-fen-zhi-zbzx/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
