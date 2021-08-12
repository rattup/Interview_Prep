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
ListNode* merge(ListNode* a,ListNode* b)
{
    ListNode *temp,*res;
    temp=res=new ListNode(-1);
    while(a && b)
    {
        if(a->val<b->val)
        {
            temp->next=a;
            temp=temp->next;
            a=a->next;
        }
        else
        {
            temp->next=b;
            temp=temp->next;
            b=b->next;
            
        }
    }
    if(a)
    temp->next=a;
    else
    temp->next=b;
    return res->next;
}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size(); // time complexity- O(NlogK)
        // N is total number of elements in all the lists
        // K is number of lists
        // Space complexity O(1)
        if(k==0)
        return nullptr;
        if(k==1)
        return lists[0];
        int i=0,j=k-1;
        int last=k-1;
        while(last!=0)
        {
        i=0;
        while(i<j)
        {
        lists[i]=merge(lists[i],lists[j]);
        i++;
        j--;
        if(i>=j)
        last=j;
        }
        }
        return lists[0];
        
        
    }
};
