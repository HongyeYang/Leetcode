class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*>s1;
        stack<ListNode*>s2;
        while(l1){
            s1.push(l1);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2);
            l2=l2->next;
        }
        ListNode* cur=NULL;
        int flag=0;
        int d1=0,d2=0;
        while((!s1.empty())||(!s2.empty())){
            if(s1.empty())d1=0;
            else {
                d1=s1.top()->val;
                s1.pop();
            }
            
            if(s2.empty())d2=0;
            else{
                d2=s2.top()->val;
                s2.pop();
            }
            int tep=d1+d2+flag;
            flag=0;
            while(tep>=10){
                tep-=10;
                flag=1;
            }
            ListNode* nnd=new ListNode(tep);
            nnd->next=cur;
            cur=nnd;
        }
        if(flag){
            ListNode* nnd=new ListNode(flag);
            nnd->next=cur;
            cur=nnd;
        }
        return cur;
    }
};
