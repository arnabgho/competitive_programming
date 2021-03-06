#include<stdio.h>
#include<stdlib.h>

#define MAX 200

int queue[MAX];
int head=-1,tail=-1,entity;

void insert(){
	if((head==0 && tail == MAX-1)||head==tail+1){
		printf("Overflow (The Queue is full)\n %d %d",head,tail);
	}
	else{
		printf("Enter The Value to be entered \n");
		scanf("%d",&entity);
		if(head==-1 && tail==-1){
			tail=0;
			head=0;
		}
		else if(tail==MAX-1){
			tail=0;
		}
		else{
			tail++;
		}
		queue[tail]=entity;
		printf("Successfully inserted entity\n");
	}
}

void delete(){

	if(head==-1){
		printf("The Queue is Empty hence nothing to delete\n");
	}
	else{
		if(head==tail){
			entity=queue[head];
			head=-1;
			tail=-1;
		}
		
		else if(head<MAX-1){
			entity=queue[head];
			head++;
		}
		else{
			entity=queue[head];
			head=0;
		}
		printf("The Entity has been successfully deleted\n");
	}
}
void display(){
	int i;
	if((head==-1 && tail==-1)||head==tail+1){
		printf("The Queue is Empty\n");
	}
	else if(tail>=head){
		printf("The Queue is : \n");
		for(i=head;i<=tail;i++)
			printf("%d\n",queue[i]);	
	}
	else if(tail<head){
		printf("The Queue is : \n");
		for(i=head;i<MAX;i++)
			printf("%d\n",queue[i]);	
		for(i=0;i<=tail;i++)				
			printf("%d\n",queue[i]);			
	}
}

void main(){
	int response;
	do{
		printf("Enter 0 to exit,1 to insert , 2 to delete , 3 to display the queue\n");
		scanf("%d",&response);
		if(response ==1){
			insert();
		}
		else if(response==2){
			delete();
		}
		else if(response==3){
			display();
		}
		else if(response==0){
			break;
		}
		else{
			printf("Enter A Valid option\n");	
		}	
	}while(1);
}
