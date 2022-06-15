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
    void insertatend(ListNode*&head , ListNode*&tail , int val)
{
    if(!head)
    {
        ListNode*n = new ListNode(val);
        head = tail = n;
    }
    else
    {
        ListNode*n = new ListNode(val);
        tail->next = n;
        tail = n;
    }
}
    int lengthLL(ListNode*head)
    {
        int count=0;
        while(head!=NULL)
        {
            head=head->next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        if(k>=lengthLL(head))
        {
            k = k%lengthLL(head);
        }
        if(k%lengthLL(head)==0)
        {
            k=k/lengthLL(head);
        }
                if(!head->next || k==0)return head;

        ListNode*temp = head;
        ListNode*a = NULL , *b = NULL;
        int diff = lengthLL(head)-k;
        while(diff--)
        {
            insertatend(a , b , temp->val);
            temp=temp->next;
        }
        ListNode*c = NULL , *d = NULL;
        while(temp!=NULL)
        {
            insertatend(c , d , temp->val);
            temp=temp->next;
        }
        
        d->next = a;
        
        return c;
        
    }
};