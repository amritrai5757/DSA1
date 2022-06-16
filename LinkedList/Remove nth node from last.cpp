    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* headd=new ListNode();
        headd->next=head;
        ListNode* fast=headd;
        ListNode* slow=headd;
        for(int i=0;i<n;i++){      //make a difference of n so that fast is always n node far from slow.
            fast=fast->next;
        }
        while(fast->next!=NULL){   // reaching the node to remove 
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;  // removing the node
        
     
        return headd->next;
    }
