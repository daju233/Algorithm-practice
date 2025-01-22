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
// 尾插法，把当前节点插到tail后面
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* tail = dummy;
        while(true){
            for(int i=0;i<k;i++){
                tail = tail->next;
                if(!tail) return dummy->next;
            }
            ListNode* head_another = prev->next;
            while(prev->next!=tail){
                //1-2-3
                ListNode* curr = prev->next;//3-2-1
                prev->next = curr->next;
                curr->next = tail->next;
                tail->next = curr;
            }
        prev = head_another;
        tail = head_another;
        }
    return dummy->next;
    }
};
