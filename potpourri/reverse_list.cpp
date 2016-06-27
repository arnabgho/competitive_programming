#include<stdio.h>
#include<stdlib.h>

struct node{
	long long int	data;
	struct node * next;
};

struct node * insertAtBeginning(struct node *head, struct node *newnode)
{	
	newnode->next=head;
	head=newnode;
	return head;
}

int main(){
	
	struct node *head,*newnode,*rev_head,*temp1,*temp;
	long long int n,data,ch,ch1;
	printf("Enter the list\n");
	head=NULL;
	while(true)
	{
		scanf("%lld",&data);
		newnode=(struct node *)calloc(1,sizeof(node));
		newnode->data=data;
		newnode->next=head;
		head=newnode;
		printf("Wanna Enter More?? (y/n)\n");
		ch=getchar();
		ch1=getchar();
		//putchar(ch);
		//putchar(ch1);
		//printf("\n");
		if(ch1=='n')
			break;
	}
	temp=head;
	while(temp!=NULL){
		printf("%lld\n",temp->data);	
		temp=temp->next;
	}

	
	temp=head;
	rev_head=NULL;
	while(temp!=NULL){
		temp1=temp;
		temp=temp->next;
		rev_head=insertAtBeginning(rev_head,temp1);
	}

	temp=rev_head;
	while(temp!=NULL){
		printf("%lld\n",temp->data);	
		temp=temp->next;
	}



	return 0;
}
