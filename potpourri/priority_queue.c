#include<stdio.h>
#include<stdlib.h>

#define MAX 200

int priority_queue[MAX][2];
int front=-1,rear=-1;

insert(data,priority){
	int i,j;
	if(rear>=MAX-1){
		printf("Queue Overflow , no more space\n");
		return;
	}
	else if((front==-1)&&(rear==-1)){
		front++;
		rear++;
		priority_queue[rear][0]=data;
		priority_queue[rear][1]=priority;
		return;
	}
	else{
		for(i=0;i<=rear;i++){
			if(priority>=priority_queue[i][1]){
				for(j=rear+1;j>i;j--){
					priority_queue[j][0]=priority_queue[j-1][0];
					priority_queue[j][1]=priority_queue[j-1][1];					
				}
				priority_queue[i][0]=data;
				priority_queue[i][1]=priority;
				break;
			}
		}
		priority_queue[i][0]=data;
		priority_queue[i][1]=priority;
		rear++;
	}
}

void display(){
	int i;
	if((front==-1)&&(rear==-1)){
		printf("Queue is empty\n");
	}
	else{
		for(i=front;i<=rear;i++){
			printf("Element :%d    Priority:%d\n",priority_queue[i][0],priority_queue[i][1]);
		}
	}
}

void main(){
	int data,priority,response;
	do{
		printf("Enter 0 to exit, 1 to enter an entity of the priority Queue, 2 to see all the entities of the priority Queue\n");
		scanf("%d",&response);
		if(response==0){
			break;
		}
		else if(response==1){
			printf("Enter The Element \n");
			scanf("%d",&data);
			printf("Enter The Priority of the element \n");			
			scanf("%d",&priority);
			insert(data,priority);
		}
		else if(response==2){
			display();
		}
		else{
			printf("Enter a valid option\n");
		}
	}while(1);
}
