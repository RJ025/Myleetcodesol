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
    int LengthLL(ListNode*head)
    {
        int count=0;
        while(head)
        {
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)return head;
        
        priority_queue<pair<int , ListNode*> , vector<pair<int , ListNode*>> , greater<pair<int , ListNode*>>>q;
        
        int len = LengthLL(head);
        ListNode*temp = head;
        
        while(temp)
        {
            q.push({temp->val , temp});
            temp=temp->next;
        }
        
        ListNode*fake_head = new ListNode();
        // fake_head->next = head;
        ListNode*ans = fake_head;
        
        while(!q.empty())
        {
            ans->next = q.top().second;
            ans=ans->next;
            q.pop();
        }
        
        ans->next = NULL;
        
        return fake_head->next;
        
    }
};