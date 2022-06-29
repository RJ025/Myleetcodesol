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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)return head;
        
        ListNode*temp = head;
        ListNode*odd_head = new ListNode();
        ListNode*odd_ans = odd_head;
        ListNode*even_head = new ListNode();
        ListNode*even_ans = even_head;
        for(int i=1 ; temp!=NULL ; i++)
        {
            if(i%2!=0)
            {
                odd_ans->next = temp;
                odd_ans=odd_ans->next;
            }
            else
            {
                even_ans->next = temp;
                even_ans = even_ans->next;
            }
            temp=temp->next;
            
        }
        odd_ans->next = even_head->next;
        even_ans->next = NULL;
        
        return odd_head->next;
    }
};