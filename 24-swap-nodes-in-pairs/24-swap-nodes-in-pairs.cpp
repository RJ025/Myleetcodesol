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
        return count;
    }
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)return head;
        
        ListNode*ans_head = new ListNode(-1);
        ans_head->next = head;
        ListNode*ans = ans_head;
        
        while(ans and ans->next and ans->next->next)
        {
            ListNode*first = ans;
            ListNode*second = ans->next;
            ListNode*third = ans->next->next;
            
            first->next = third;
            second->next = third->next;
            third->next = second;
            
            ans = second;
        }
        
        
        return ans_head->next;
        
    }
};