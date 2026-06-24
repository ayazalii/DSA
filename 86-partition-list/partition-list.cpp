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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;

        ListNode*n1=new ListNode();//LL-1
        ListNode*n2=new ListNode();//LL-2

        ListNode* temp1=n1;//iterate to ll1
        ListNode*temp2=n2;//iterate to ll2

        while(temp!=NULL){
            if(temp->val<x){
                temp1->next=temp;

                temp1=temp1->next;
            }
            else{
                temp2->next=temp;
                temp2=temp2->next;
            
            }
            temp=temp->next;
        }
//when we merge both the LL
        temp2->next=NULL;
        temp1->next=n2->next;

        return n1->next;


    }
};