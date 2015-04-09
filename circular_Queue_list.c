#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};

struct node * insert(struct node * rear){
	int data;
	struct node * temp;
	temp=(struct node *)calloc(1,sizeof(struct node));
	
	if(temp==NULL){
		printf("Sorry , out of dynamic memory , no dynamic memory left to be allocated\n");
	}
	else{
		printf("Enter The data for the Queue Entity\n");
		scanf("%d",&data);
		temp->data=data;
		if(rear==NULL){
			temp->next=temp;
			rear=temp;			
		}
		else if(rear!=NULL){
			temp->next=rear->next;
			rear->next=temp;
			rear=temp;
		}
		printf("The entity has been successfully inserted\n");
	}
	return rear;
}

struct node * delete(struct node * rear){
	struct node * temp;
	if(rear==NULL){
		printf("Nothing to be deleted , empty queue\n");
	}
	else{
	
		if(rear->next==rear){
			temp=rear;
			free(temp);
			rear=NULL;
		}
		else{
			temp=rear->next;
			rear->next=temp->next;
			free(temp);
		}
		printf("The Entity has been successfully deleted\n");
	}
	return rear;
}

void display(struct node * rear){
	struct node * temp;
	if(rear==NULL){
		printf("Empty Queue\n");
	}
	else{
		printf("The Queue is \n");
		temp=rear->next;
		printf("%d\n",temp->data);
		temp=temp->next;
		while(temp!=rear->next){			
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}	
}

void main(){
	int response;
	struct node * rear=NULL;
	do{
		printf("Enter 0 to exit,1 to insert , 2 to delete , 3 to display the queue\n");
		scanf("%d",&response);
		if(response ==1){
			rear=insert(rear);
		}
		else if(response==2){
			rear=delete(rear);
		}
		else if(response==3){
			display(rear);
		}
		else if(response==0){
			break;
		}
		else{
			printf("Enter A Valid option\n");	
		}	
	}while(1);

}
