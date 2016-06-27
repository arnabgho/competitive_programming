 #include <stdio.h>
 #include <iostream>
 #include <stdlib.h>
 using namespace std;

 struct ListNode {
        int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
  };

    ListNode * reverseList(ListNode *head){
        int num=0;
        if(head==NULL)
            return NULL;
        ListNode *curr,*next,*next_next;
        ListNode * temp=head;    
        while(!(temp==NULL)) {temp=temp->next;num++;}
        if(num==1)
            return head;
        if(num==2){
            curr=head;
            next=curr->next;
            next->next=head;
            curr->next=NULL;
            head=next;
            return head;
        }    
        if(num>=3){
            curr=head;
            next=curr->next;
            next_next=next->next;
            while(next_next!=NULL){
                next->next=curr;
                curr=next;
                next=next_next;
                next_next=next->next;
            }
            next->next=curr;
            head->next=NULL;
            head=next;
            return head;
        }
    }

int main(){
    int val,ch;
    ListNode *newnode,*curr,*head;
    newnode=(ListNode*)malloc(sizeof(ListNode));
    curr=(ListNode*)malloc(sizeof(ListNode));
    head=(ListNode*)malloc(sizeof(ListNode));
    cout<<"Add Elements to Linked List: \n";
    cin>>val;
    newnode->val=val;
    newnode->next=NULL;
    curr=newnode;
    head=curr;
    ch=1;
    while(ch==1){
        cout<<"Hi\n";
        newnode=(ListNode*)malloc(sizeof(ListNode));
        cin>>val;
        newnode->val=val;
        newnode->next=NULL;
        curr->next=newnode;
        curr=newnode;
        cout<<"Wanna Continue (1/0)??..........."<<endl;
        cin>>ch;
    }
    head=reverseList(head);
    curr=head;
    while(curr!=NULL){
        cout<<curr->val<<"->";
        curr=curr->next;
    }
    return 0;
}