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
    // int lenghtLL(listnode*head)
    // {
    //     int count=0;
    //     while(listhead->next != NULL)
    //     {
    //         listhead=listhead->next;
    //         count++;
    //     }
    //     return count;
    // }
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
        {
            return head;
        }
        ListNode*temp = head;
        // int length = lengthLL(listnode)
        
        while(temp->next!=NULL)
        {
            if(temp->val == temp->next->val)
            {
                temp->next = temp->next->next;
            }
            else{
            temp=temp->next;}
        }
        
        return head;
        
    }
};