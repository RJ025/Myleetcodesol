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
            tail->next=n;
            tail=n;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        
        priority_queue<int , vector<int> , greater<int>>q;
        
       for(int i=0 ; i<lists.size() ; i++)
       {
           ListNode*temp = lists[i];
            while(temp!=NULL)
            {
                q.push(temp->val);
                temp=temp->next;
            }
       }
   
        ListNode*head = NULL , *tail=NULL;
        while(!q.empty())
        {
            insertatend(head , tail , q.top());
            q.pop();
        }
        
        return head;
        
        
    }
};