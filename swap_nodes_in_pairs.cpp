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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev;
        prev=dummy;
        ListNode* cur=head;
        while(cur && cur->next)
        {
        prev->next=cur->next;
        ListNode* temp=cur->next;
        cur->next=cur->next->next;
        temp->next=cur;
        prev=cur;
        cur=cur->next;
        
        }
        return dummy->next;
        
    }
};
