#include<stdio.h>
#include<stdlib.h>

# define max 200
int deque[max];
int head=-1,tail=-1,data,in=0;	

void init(){
	head=max/2;
	tail=max/2;
	printf("Enter The data\n");
	scanf("%d",&data);
	deque[head]=data;
	printf("Data Successfully inserted\n");
	in=1;
}

void inserthead(){
	if(head==0)
		printf("There is no place to insert at head\n");
	else{
		head=head-1;
		printf("Enter The data\n");
		scanf("%d",&data);
		deque[head]=data;
		printf("Data Successfully inserted\n");		
	}
}
void inserttail(){
	if(tail==max){
		printf("There is no place to insert at tail\n");		
	}
	else{
		tail=tail+1;
		printf("Enter The data\n");
		scanf("%d",&data);
		deque[tail]=data;		
		printf("Data Successfully inserted\n");		
	}
}

void deletehead(){
	if(head==max){
		printf("The Queue is empty\n");
	}
	else{
		data=deque[head];
		head=head+1;
		printf("The data %d has been deleted\n",data);
	}	
}


void display(){
	int i;
	printf("The Queue is \n");
	for(i=head;i<=tail;i++){
		printf("%d\n",deque[i]);
	}
}
int main(){
	int response;
	do{
		printf("Enter 0 to exit \n1 to insert at head\n2 to insert at tail\n3 to delete from head \n4 to display the contens\n");
		scanf("%d",&response);
		if(response==1){
			if(in==1)
				inserthead();
			else
				init();
		}
		else if(response==2){
			if(in==1)
				inserttail();
			else	
				init();	
		}
		else if(response==3){
			if(in==1)
				deletehead();
			else
				printf("Empty Queue\n");	
		}

		else if(response==4){
			display();
		}	
		
		else if(response==0){
			break;
		}	
		
		else{
			printf("Not a correct response\n");
		}
	}while(1);

}
