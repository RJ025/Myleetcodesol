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
        int count=0;
        while(head!=NULL)
        {
            head=head->next;
            count++;
        }
        return count;
    }
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        ListNode*slow = head , *fast = head->next;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(lengthLL(head)%2==0)
        {
            return slow->next;
        }
        else{
            return slow;
        }
        
        
    }
};