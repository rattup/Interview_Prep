/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* head, int k) {
    if(!head || !head->next || k==1)
    return head;
    int state=1;
    ListNode *newHead,*cur,*next,*t1,*t2,*prev;
    newHead=prev=t1=nullptr;
    cur=t2=head;
    while(cur)
    {
        if(state)
        {
            for(int i=1;i<=k;i++)
            {
                next=cur->next;
                cur->next=prev;
                prev=cur;
                cur=next;
            }
            if(t1)
            t1->next=prev;
            if(!newHead)
            newHead=prev;
            t2->next=cur;
            t1=t2;
            t2=cur;
            prev=nullptr;
            state=0;

        }
        else
        {
            for(int i=1;i<=k;i++)
            {
                cur=cur->next;
                if(i==k-1)
                t1=cur;

            }
            t2=cur;
            state=1;


        }
    }
    return newHead;

}

