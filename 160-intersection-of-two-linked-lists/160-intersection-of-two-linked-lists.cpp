/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int lenghtLL(ListNode*head)
    {
        int count=0;
        while(head!=NULL)
        {
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA)return NULL;
        if(!headB)return NULL;
        int diff=lenghtLL(headA)-lenghtLL(headB);
        ListNode*tempA = headA , *tempB = headB;
        if(diff>0)
        {
            while(diff--)
            {
                tempA=tempA->next;
            }
        }
        else if(diff<0)
        {
            while(diff++)
            {
                tempB=tempB->next;
            }
        }
        
        while(tempA!=tempB)
        {
            // if(tempA->val == tempB->val)return tempA;
            tempA=tempA->next;
            tempB=tempB->next;
            if(tempA==NULL || tempB==NULL)return NULL;
        }
        
        return tempA;
        
    }
};