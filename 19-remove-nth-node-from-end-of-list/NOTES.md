```
ListNode* removeNthFromEnd(ListNode* head, int n) {
// create copy node
ListNode* dummy = new ListNode();
dummy->next = head;
//declare pointers
ListNode* fast = dummy;
ListNode* slow = dummy;
// traverse through LL n-times
for(int i=0;i<n;i++){
fast = fast->next;
}
// move both pointer until a condition is met
while(fast->next != NULL){
fast = fast->next;
slow = slow->next;
}
// delete nth node
slow->next = slow->next->next;
return dummy->next;
}
```