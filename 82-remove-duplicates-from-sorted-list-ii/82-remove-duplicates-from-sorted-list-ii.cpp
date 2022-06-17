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
    void atend(ListNode*&head , int val)
    {
        ListNode*n = new ListNode(val);
        if(!head)
        {
            
            head=n;
        }
        else
        {
            ListNode*temp = head;
            while(temp->next)
            {
                temp=temp->next;
            }
            temp->next = n;
        }
        return;
        
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*ans = NULL;
        int map[209] = {0};
        
        while(head)
        {
            map[(head->val)+100]++;
            head=head->next;
        }
        
        for(int i=0 ; i<209 ; i++)
        {
            if(map[i]==1)
            {
                atend(ans , i-100);
            }
        }
        
        return ans;
        
    }
};