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
                ListNode* curr = prev->next;//dummy-!1!-2-3 //dummy-!2!-3-1
                prev->next = curr->next;//dummy-2 dummy-3
                curr->next = tail->next;
                tail->next = curr;//dummy-2-3-1 //dummy-3-2-1
            }
        prev = head_another;
        tail = head_another;
        }
    return dummy->next;
    }
};
