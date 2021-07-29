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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k==1)
        return head;
        int n=0;
        ListNode* cur=head;
        while(cur)
        {
            n++;
            cur=cur->next;
        }
        if(n<k)
        return head;
        cur=head;
        ListNode *prev=nullptr,*next,*t1=nullptr,*t2=cur,*newHead=nullptr;
        while(n>=k)
        {
            for(int i=1;i<=k;i++)
            {
                next=cur->next;
                cur->next=prev;
                prev=cur;
                cur=next;
            }
            if(!newHead)
            newHead=prev;
            if(t1)
            t1->next=prev;
            t2->next=cur; // when n is not multiple of k
            t1=t2;
            t2=cur;
            prev=nullptr;
            n-=k;
        }
        return newHead;
        
    }
};
