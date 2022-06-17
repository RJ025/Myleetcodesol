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
    int lengthLL(ListNode*head)
    {
        int count=1;
        while(head->next!=NULL)
        {
            count++;

            head=head->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next)return NULL;
        if(n==lengthLL(head))
        {
            ListNode*t = head;
            head=head->next;
            delete t;
            return head;
        }
        else if(n==1)
        {
            ListNode*t1 = head;
            while(t1->next->next)
            {
                t1=t1->next;
            }
            t1->next = NULL;
            return head;
        
        }
        
        n = n%lengthLL(head);
        int diff = lengthLL(head)-n; 
        ListNode*temp = head;
        
        for(int i=0 ; i<diff-1 ; i++)
        {
            temp = temp->next;
            // diff--;
        }
        ListNode*p = temp->next;
        temp->next = temp->next->next;
        delete p;
        
        return head;
        
    }
};