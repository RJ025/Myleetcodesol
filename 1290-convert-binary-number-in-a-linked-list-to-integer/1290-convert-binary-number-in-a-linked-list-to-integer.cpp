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
    int lenghtLL(ListNode*head)
    {
        int count=0;
        while(head)
        {
            count++;
            head=head->next;
        }
        return count-1;
    }
    int getDecimalValue(ListNode* head) {
        if(!head)return 0;
        
        ListNode*temp = head;
        int sum=0;
        int len = lenghtLL(head);
        while(temp)
        {
            sum=sum+(temp->val*pow(2 , len));
            temp=temp->next;
            len--;
        }
        
        return sum;
    }
};