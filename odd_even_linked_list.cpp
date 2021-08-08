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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
        return head;
        ListNode *odd,*even,*odd_head,*even_head;
        odd=odd_head=head;
        even=even_head=head->next;
        while(even && even->next)
        {
            odd->next=odd->next->next;
            even->next=even->next->next;
            even=even->next;
            odd=odd->next;
        }
        odd->next=even_head;
        return head;
        
        
    }
};
