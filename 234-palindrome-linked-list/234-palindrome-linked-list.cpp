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
    
    bool code(vector<int>&v , int start , int end)
    {
        if(start>=end)
            return true;
        
        
        if(v[start] == v[end])return code(v , start+1 , end-1);
        
        return false;
        
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head)return true;
        if(!head->next)return true;
        
        ListNode*temp = head;
        vector<int>v;
        
        while(temp)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        return code(v , 0 , v.size()-1);
        
        
        
    }
};